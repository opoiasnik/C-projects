#include <stdio.h>
#include "compressor.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 128
#define MAX_HUFFMAN_CODE_LENGTH 64

int charFrequency[MAX_CHARACTERS];
char huffmanCodes[MAX_CHARACTERS][MAX_HUFFMAN_CODE_LENGTH];





void bubbleSort(Node *nodes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (nodes[j].freq > nodes[j + 1].freq) {

                Node temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}
void displayHelp() {
    printf("Usage: huffman [options] <input file> <output file>\n");
    printf("Options:\n");
    printf("  -c    Compress the input file\n");
    printf("  -d    Decompress the input file\n");
    // Additional help information can be added here
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        printErrorMessage("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void printErrorMessage(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void initializeGlobalVariables() {
    memset(charFrequency, 0, sizeof(charFrequency));
    memset(huffmanCodes, 0, sizeof(huffmanCodes));
}
void printHuffmanCodes() {
    printf("Huffman Codes:\n");
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (huffmanCodes[i][0] != '\0') {
            printf("%c: %s\n", i, huffmanCodes[i]);
        }
    }
}

int validateInputFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size > 0;
}

void printHuffmanTree(Node *node, int depth) {
    if (!node) return;
    if (!node->leftChild && !node->rightChild) {
        printf("%*s%c (%d)\n", depth * 4, "", node->symbol, node->freq);
    } else {
        printHuffmanTree(node->leftChild, depth + 1);
        printHuffmanTree(node->rightChild, depth + 1);
    }
}

void freeHuffmanTree(Node *node) {
    if (!node) return;
    freeHuffmanTree(node->leftChild);
    freeHuffmanTree(node->rightChild);
    free(node);
}
void countCharacterFrequencies(char *inputStr) {
    while (*inputStr) {
        charFrequency[(unsigned char)*inputStr++]++;
    }
}


Node *extractMinNode(Node *nodes, int totalNodes) {
    int minIndex = 0;
    for (int i = 1; i < totalNodes; i++) {
        if (nodes[i].freq < nodes[minIndex].freq) {
            minIndex = i;
        }
    }
    Node *minNode = malloc(sizeof(Node));
    *minNode = nodes[minIndex];
    nodes[minIndex] = nodes[totalNodes - 1];
    return minNode;
}

void generateHuffmanCodes(Node *root, char *code, int depth) {
    if (!root) return;
    if (!root->leftChild && !root->rightChild) {
        strncpy(huffmanCodes[root->symbol], code, depth);
        huffmanCodes[root->symbol][depth] = '\0';
        return;
    }
    code[depth] = '0';
    generateHuffmanCodes(root->leftChild, code, depth + 1);
    code[depth] = '1';
    generateHuffmanCodes(root->rightChild, code, depth + 1);
}


char *readFileContents(const char *filename, long *fileLength) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    *fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(*fileLength + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }

    fread(content, 1, *fileLength, file);
    content[*fileLength] = '\0';
    fclose(file);
    return content;
}



void writeBitToFile(unsigned char bit, FILE *file, int flush) {
    static int bitCounter = 0;
    static unsigned char bitBuffer = 0;

    // Операция сброса буфера
    if (flush) {
        if (bitCounter > 0) {
            // Выравнивание битов в буфере и запись в файл
            bitBuffer <<= (8 - bitCounter);
            fwrite(&bitBuffer, sizeof(bitBuffer), 1, file);
        }
        // Сброс счетчика и буфера
        bitCounter = 0;
        bitBuffer = 0;
        return;
    }
    // Добавление бита в буфер
    bitBuffer <<= 1; // Сдвиг буфера для освобождения места под новый бит
    if (bit) {
        bitBuffer |= 1;// Установка младшего бита, если переданный бит равен 1
    }
    bitCounter++; // Увеличение счетчика битов

    // Запись буфера в файл, если он полностью заполнен
    if (bitCounter == 8) {
        fwrite(&bitBuffer, sizeof(bitBuffer), 1, file);
        bitBuffer = 0; // Сброс буфера
        bitCounter = 0; // Сброс счетчика
    }
}
void huffmanDecompress(FILE *inputFile, Node *root, FILE *outputFile, long originalSize) {
    Node *currentNode = root;
    int readChar;
    long decompressedBytesCount = 0;


    while ((readChar = fgetc(inputFile)) != EOF) {

        for (int bitIndex = 7; bitIndex >= 0; bitIndex--) {

            if (decompressedBytesCount >= originalSize) {
                break;
            }

            // Получение текущего бита
            int currentBit = (readChar >> bitIndex) & 1;
            // Перемещение в дереве Хаффмана в зависимости от бита
            currentNode = currentBit ? currentNode->rightChild : currentNode->leftChild;

            // Проверка, достигли ли мы листа дерева
            if (currentNode->leftChild == NULL && currentNode->rightChild == NULL) {

                fputc(currentNode->symbol, outputFile);
                decompressedBytesCount++;

                currentNode = root;
            }
        }
    }
}










//RLE RLE RLE RLE RLE RLE
void compressRLE(const char* inputFile, const char* outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (in == NULL || out == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int head = fgetc(in);
    if (head == EOF) {
        fclose(in);
        fclose(out);
        return;
    }

    int count = 1;
    while(1) {
        int next = fgetc(in);
        if (next == EOF || next != head || (isdigit(head) && count == 1)) {
            if (count > 1) {
                fprintf(out, "%c%d", head, count);
            } else {
                if (isdigit(head)) {
                    fputc('\\', out); // Маркируем цифру
                }
                fputc(head, out);
            }
            if (next == EOF) break;
            head = next;
            count = 1;
        } else {
            count++;
        }
    }

    fclose(in);
    fclose(out);
}

void decompressRLE(const char* inputFile, const char* outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (in == NULL || out == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while(1) {
        int head = fgetc(in);
        if (head == EOF) break;

        if (head == '\\') { // Если встречаем маркер, следующий символ - цифра
            head = fgetc(in);
            if (head == EOF) break;
            fputc(head, out);
            continue;
        }

        int nextChar = fgetc(in);
        if (nextChar == EOF) {
            fputc(head, out);
            break;
        }

        if (isdigit(nextChar)) {
            ungetc(nextChar, in);
            int count;
            fscanf(in, "%d", &count);

            for (int i = 0; i < count; i++) {
                fputc(head, out);
            }
        } else {
            fputc(head, out);
            ungetc(nextChar, in);
        }
    }

    fclose(in);
    fclose(out);
}


