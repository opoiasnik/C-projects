#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TRAIN_H
#define TRAIN_H
#define SIZE 100


struct car {
    char value[SIZE];
    struct car* next;
};


struct car* add_car(struct car* first,const char* target);
void print_train(struct car* first);
void cancel_train(struct car* first);
struct car* clear_train(struct car* first,const char* target);
#endif


int main() {
    struct car* train = NULL; // Указатель на первый вагон поезда
    char target[SIZE]; // Буфер для хранения имени станции


    while (1) {
        printf("\n1. Add station\n");
        printf("2. Print train\n");
        printf("3. Clear station\n");
        printf("4. Cancel train\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter station name: ");
                scanf("%s", target);
                train = add_car(train, target);
                break;
            case 2:

                printf("\nCurrent train stations:\n");
                print_train(train);
                break;
            case 3:

                printf("Enter station name to clear: ");
                scanf("%s", target);
                train = clear_train(train, target);
                break;
            case 4:

                printf("\nCancelling train...\n");
                cancel_train(train);
                train = NULL;
                printf("Train cancelled successfully.\n");
                break;
            case 5:

                printf("Exiting program.\n");
                cancel_train(train);
                return 0;
            default:

                printf("Invalid choice. \n");
                return 0;
        }
    }
    return 0;
}


struct car* add_car(struct car* first, const char* target) {
    struct car *newcar = calloc(1, sizeof(struct car));
    strcpy(newcar->value, target);
    if (first == NULL) {
        return newcar; // Если поезд пуст, новый вагон становится первым
    }
    struct car *this = first;
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = newcar;
    return first;
}

    void print_train(struct car *first) {
        if (first == NULL) {
            printf("The train is empty.\n");
            return;
        }
        struct car *current = first;
        while (current != NULL) { // Проход по всем вагонам
            printf("Station: %s\n", current->value);
            current = current->next;
        }
    }


    void cancel_train(struct car *first) {
        if (first == NULL) {
            return;
        }
        cancel_train(first->next);
        free(first);
    }


    struct car *clear_train(struct car *first, const char *target) {
        if (first == NULL) {
            return NULL; // Если поезд пуст, возвращение NULL
        }
        if (strcmp(first->value, target) == 0) {
            struct car *newFirst = first->next; // Сохранение указателя на следующий вагон
            free(first);
            return newFirst;
        }
        struct car *prev = first; // Начало обхода поезда для поиска удаляемого вагона
        while (prev->next != NULL && strcmp(prev->next->value, target) != 0) {
            prev = prev->next;
        }
        if (prev->next == NULL) {
            return first;
        }
        struct car *third = prev->next->next; // Сохранение указателя на вагон, следующий за удаляемым
        free(prev->next);
        prev->next = third; // Связывание предыдущего вагона с следующим за удаляемым
        return first;
    }
