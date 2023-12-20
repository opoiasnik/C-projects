typedef struct Node {
    char symbol;
    int freq;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

void printHuffmanCodes();
int validateInputFile(const char *filename);
void printHuffmanTree(Node *node, int depth);
void freeHuffmanTree(Node *node);
void displayHelp();
void* safeMalloc(size_t size);
void printErrorMessage(const char *message);
void initializeGlobalVariables();
void displayHelp();
void* safeMalloc(size_t size);
void printErrorMessage(const char *message);
void initializeGlobalVariables() ;
void printHuffmanCodes();
int validateInputFile(const char *filename);
void printHuffmanTree(Node *node, int depth) ;
void freeHuffmanTree(Node *node);
void countCharacterFrequencies(char *inputStr);
int nodeComparator(const void *nodeA, const void *nodeB) ;
Node *extractMinNode(Node *nodes, int totalNodes);
void generateHuffmanCodes(Node *root, char *code, int depth);
char *readFileContents(const char *filename, long *fileLength);
void writeBitToFile(unsigned char bit, FILE *file, int flush);
void huffmanDecompress(FILE *inputFile, Node *root, FILE *outputFile, long originalSize);


void bubbleSort(Node *nodes, int count) ;
//RLE
void compressRLE(const char* inputFile, const char* outputFile);
void decompressRLE(const char* inputFile, const char* outputFile);
