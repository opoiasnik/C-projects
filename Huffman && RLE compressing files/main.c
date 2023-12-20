#include <stdio.h>
//#include "compressor.h"
#include "compressor.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv) {
    if(argc == 1){
        //printf("OK");
        return 0;
    }
    char *flag = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    if (strcmp(flag, "-r") == 0) {
        if (strcmp(argv[2], "-c") == 0) {
            compressRLE(argv[3], argv[4]);
        } else if (strcmp(argv[2], "-d") == 0) {
            decompressRLE(argv[3], argv[4]);
        }

    } else if (strcmp(flag, "-h") == 0) {
        initializeGlobalVariables();




        //  Read the input file
        long file_size;
        char *str = readFileContents(argv[2], &file_size);
        if (!str) {
            printf("Failed to read input file.\n");
            return 1;
        }

        // Calculate character probabilities
        countCharacterFrequencies(str);

        //  Build Huffman Tree
        int node_count = 0;
        for (int i = 0; i < MAX_CHARACTERS; i++) {
            if (charFrequency[i] != 0) node_count++;
        }

        Node nodes[node_count];
        int idx = 0;
        for (int i = 0; i < MAX_CHARACTERS; i++) {
            if (charFrequency[i] != 0) {
                Node newNode;                  // Создаем временную переменную типа Node
                newNode.symbol = (char)i;      // Присваиваем символ
                newNode.freq = charFrequency[i]; // Устанавливаем частоту символа
                newNode.leftChild = NULL;      // Указатели на дочерние элементы пока что NULL
                newNode.rightChild = NULL;

                nodes[idx] = newNode;          // Присваиваем новый узел в массив узлов
                idx++;                         // Увеличиваем индекс для следующего узла
            }
        }


        bubbleSort(nodes, node_count) ;

        while (node_count > 1) {
            Node *min1 = extractMinNode(nodes, node_count--);
            Node *min2 = extractMinNode(nodes, node_count--);
            Node newNode;
            // Устанавливаем символ нового узла в '\0', поскольку он не соответствует никакому конкретному символу
            newNode.symbol = '\0';
            // Устанавливаем частоту нового узла как сумму частот двух извлекаемых узлов
            newNode.freq = min1->freq + min2->freq;
            // Присваиваем левый и правый дочерние узлы
            newNode.leftChild = min1;
            newNode.rightChild = min2;
            // Добавляем новый узел в массив узлов
            nodes[node_count] = newNode;
            // Увеличиваем счетчик узлов
            node_count++;
        }
        Node *root = &nodes[0];

        // Generate Huffman huffmanCodes
        char path[MAX_HUFFMAN_CODE_LENGTH] = {0};
        generateHuffmanCodes(root, path, 0);

        // Write compressed file
        FILE *compressedFile = fopen(argv[3], "wb");


        for (char *s = str; *s; s++) {
            char *code = huffmanCodes[(unsigned char)*s];
            for (int i = 0; code[i]; i++) {
                writeBitToFile(code[i] - '0', compressedFile, 0);
            }
        }
        writeBitToFile(0, compressedFile, 1); // Flush remaining bits
        fclose(compressedFile);

        //  Read and decompress the file
        compressedFile = fopen(argv[3], "rb");


        FILE *decompressedFile = fopen(argv[4], "wb");


        huffmanDecompress(compressedFile, root, decompressedFile, file_size); // Pass original file size

        fclose(compressedFile);
        fclose(decompressedFile);
        free(str);
        printf("Compression and decompression completed.\n");
    } else {
        printf("Invalid flag. \n");
        printf("Choose: \n");
        printf("-r or -h. \n");

        printf("Choose: \n");
        printf("-r or -h. \n");
        return 1;
    }

    printf("Operation completed.\n");


    return 0;
}
