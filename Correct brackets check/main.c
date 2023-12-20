#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool checkBrackets(char input[]) {
    char *stack = malloc(sizeof(char) * 100);
    if (stack == NULL) {
        printf("Memory allocation error\n");
        return false;
    }

    int top = -1;
    char missingBrackets[5] = "";  // Строка для хранения отсутствующих скобок
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<') {
            stack[++top] = input[i];
        } else if (input[i] == ')' || input[i] == '}' || input[i] == ']' || input[i] == '>') {
            if (top == -1) {
                printf("Unexpected closing bracket %c in %d\n", input[i], i);
                free(stack);
                return false;
            }

            char openBracket = stack[top--];
            if ((input[i] == ')' && openBracket != '(') ||
                (input[i] == '}' && openBracket != '{') ||
                (input[i] == ']' && openBracket != '[') ||
                (input[i] == '>' && openBracket != '<')) {
                if(openBracket == '('){
                    printf("Crossed bracket %c in %d, expected ) \n", input[i], i);
                }
                if(openBracket == ')'){
                    printf("Crossed bracket %c in %d, expected ( \n", input[i], i);
                }
                if(openBracket == '{'){
                    printf("Crossed bracket %c in %d, expected } \n", input[i], i);
                }
                if(openBracket == '}'){
                    printf("Crossed bracket %c in %d, expected { \n", input[i], i);
                }
                if(openBracket == '['){
                    printf("Crossed bracket %c in %d, expected ] \n", input[i], i);
                }
                if(openBracket == ']'){
                    printf("Crossed bracket %c in %d, expected [ \n", input[i], i);
                }
                if(openBracket == '<'){
                    printf("Crossed bracket %c in %d, expected > \n", input[i], i);
                }
                if(openBracket == '>'){
                    printf("Crossed bracket %c in %d, expected < \n", input[i], i);
                }
                //printf("Crossed bracket %c in %d, expected %c\n", input[i], i, openBracket);
                free(stack);
                return false;
            }
        }
    }

    while (top != -1) {
        if(stack[top] == '['){
            strcat(missingBrackets, "]");
        }
        if(stack[top] == '{'){
            strcat(missingBrackets, "}");
        }
        if(stack[top] == '<'){
            strcat(missingBrackets, ">");
        }
        if(stack[top] == '('){
            strcat(missingBrackets, ")");
        }
        top--;
    }

    if (missingBrackets[0] != '\0') {
        printf("Missing closing brackets: %s\n", missingBrackets);
    } else {
        printf("All brackets OK\n");
    }

    free(stack);
    return true;
}

int main() {
    char input[100];

    scanf("%99[^\n]", input);
    printf("Read: %s\n", input);
    checkBrackets(input);
    return 0;
}
