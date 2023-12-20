#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 256
int isReadingNoBranch = 0; // Глобальная переменная для контроля чтения ветви 'no' узла
int stopReading = 0; // Флаг для остановки дальнейшего чтения при обнаружении ошибки или завершении ввода
struct tree {
    char value[SIZE];
    struct tree* yes;
    struct tree* no;
};

void destroy_tree(struct tree* tree) {
    if (tree) {
        destroy_tree(tree->yes);
        destroy_tree(tree->no);
        free(tree);
    }
}


struct tree* read_tree(int* counter) {
    char buffer[SIZE];
    memset(buffer, 0, SIZE);
    char* r = fgets(buffer, SIZE, stdin);

    if (r == NULL) {
        return NULL;
    }

    if (buffer[0] == '\0') {
        return NULL;
    }

    struct tree* node = calloc(1, sizeof(struct tree));
    buffer[strcspn(buffer, "\n")] = 0;
    if((buffer[0] != '*' && isReadingNoBranch == 1)){
        if(buffer[0] == 0){
            memcpy(node->value, buffer, SIZE);
            stopReading = 1;
            return node;
        }

        destroy_tree(node);
        return NULL;
    }

    // Проверка, если yes заполнен, а no нет, или наоборот
    if ((node->yes != NULL && node->no == NULL) || (node->yes == NULL && node->no != NULL)) {

        destroy_tree(node);
        return NULL;
    }

    // Если ввод после yes содержит слово без *, вернуть ошибку
    if (node->yes != NULL && strncmp(buffer, "*", 1) != 0) {

        destroy_tree(node);
        return NULL;
    }

    memcpy(node->value, buffer, SIZE);


    if (strncmp(buffer, "*", 1) != 0) {
        if(stopReading == 0){
            node->yes = read_tree(counter);
        }



        if (strncmp(buffer, "*", 1) != 0) {
            if(stopReading==0){
                isReadingNoBranch = 1;
                node->no = read_tree(counter);
                (*counter)++;
            }

        }else{
            destroy_tree(node);
            return NULL;
        }
    }

    return node;
}




void print_tree(struct tree* tree, int offset) {
    for (int i = 0; i < offset; i++) {
        printf(" ");
    }
    printf("%s", tree->value);
    printf("\n");

    if (tree->yes) {
        print_tree(tree->yes, offset + 3);
    }
    if (tree->no) {
        print_tree(tree->no, offset + 3);
    }
}


int knowledge_system(struct tree* node) {
    //printf("%s\n", node->value);
    if (node->yes == NULL && node->no == NULL) {
        printf("%s\n", node->value);
        printf("Koniec\n");
        return 0;
    }

    printf("%s\n", node->value);
    char answer;
    if (scanf(" %c", &answer) != 1) {
        printf("Koniec vstupu\n");
        return 0;
    }

    if (answer == 'a') {
        if (node->yes == NULL || node->no == NULL) {
            printf("Expert z bufetu to vie.\n");
            printf("Chybna databaza\n");
            return 0;
        }
        knowledge_system(node->yes);
    } else if (answer == 'n') {
        if (node->yes == NULL || node->no == NULL) {
            printf("Expert z bufetu to vie.\n");
            printf("Chybna databaza\n");
            return 0;
        }
        knowledge_system(node->no);
    } else {
        printf("Nerozumiem\n");
    }
}


int main() {
    struct tree* root = NULL;
    int counter = 0;

    root = read_tree(&counter);

    if (root == NULL || root->value[0] == '\n' || (root->yes == NULL && root->no == NULL)) {
        printf("Expert z bufetu to vie.\n");
        printf("Chybna databaza\n");
        // Uvoľniť pamäť
        return 0;
    }
    printf("Tree: \n");
    print_tree(root, 5);

    printf("Expert z bufetu to vie.\n");
    printf("Pozna %d druhov ovocia a zeleniny.\n", counter + 1);
    printf("Odpovedajte 'a' pre prvu moznost alebo 'n' pre druhu moznost.\n");
    knowledge_system(root);


    destroy_tree(root);

    return 0;
}
