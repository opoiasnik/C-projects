
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifndef STATION_H
#define STATION_H
#define STATION_SIZE 10
#define TARGET_SIZE 36
struct car {
    // Cielova stanica / nazov
    char value[TARGET_SIZE];
    // Pocet cestujuchich
    int capacity;
    // Smernik na dalsi zaznam
    struct car* next;
};
struct station {
    struct car** tracks;
    int track_count;
};
struct station* create_station();
void destroy_station(struct station* station);
int select_track(struct station* station, const char* target);
void add_target_capacity(struct station* station,const char* target, int capacity);
int get_target_capacity(struct station* station,const char* target);
int count_targets(struct station* station);
int count_capacity(struct station* station);
#endif


void print_station(struct station* station);
void print_summary(struct station* station);

void print_menu();
void add_target_interaction(struct station* station);
void print_station_interaction(struct station* station);
void print_summary_interaction(struct station* station);

int main() {
    srand(time(NULL));
    struct station* station = create_station();
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_target_interaction(station);
                break;
            case 2:
                print_station_interaction(station);
                break;
            case 3:
                print_summary_interaction(station);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (1);

    destroy_station(station);
    return 0;
}

void print_menu() {
    printf("\n1. Add target\n");
    printf("2. Print station\n");
    printf("3. Print summary\n");
    printf("4. Exit\n");
}

void add_target_interaction(struct station* station) {
    char target[TARGET_SIZE];
    int capacity;

    printf("Enter target name: ");
    scanf("%s", target);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    add_target_capacity(station, target, capacity);
    printf("Target added successfully.\n");
}

void print_station_interaction(struct station* station) {
    print_station(station);
}

void print_summary_interaction(struct station* station) {
    print_summary(station);
}


//   srand(time(NULL));
//   struct station* station = create_station();
//   test_station(station);
//   destroy_station(station);
//   return 0;

void print_station(struct station* station) {
    printf("\nCurrent station:\n");
    for (int i = 0; i < station->track_count; i++) {
        struct car* current = station->tracks[i];
        while (current != NULL) {
            printf("%s %d -> ", current->value, current->capacity);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void print_summary(struct station* station) {
    printf("\nSummary:\n");
    printf("Total targets: %d\n", count_targets(station));
    printf("Total capacity: %d\n", count_capacity(station));
}
struct station* create_station(){
    struct station* station = (struct station*)calloc(1,sizeof(struct station));
    station->tracks = (struct car**)calloc(STATION_SIZE, sizeof(struct car*));
    station->track_count = STATION_SIZE;
    return station;
}

void destroy_station(struct station* station){
    for (int i = 0; i < station->track_count; ++i) {
        struct car* current = station->tracks[i];
        while (current != NULL) {
            struct car* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(station->tracks);
    free(station);
}

int select_track(struct station* station, const char* target){
    int hash_value = 0;
    for (int i = 0; i < strlen(target); ++i) {
        hash_value += target[i];
    }
    return hash_value % station->track_count;
}

void add_target_capacity(struct station* station,const char* target, int capacity){
    int track = select_track(station, target);
    struct car* new_car = malloc(sizeof(struct car));
    strcpy(new_car->value, target);
    new_car->capacity = capacity;
    new_car->next = NULL;

    if (station->tracks[track] == NULL) {
        station->tracks[track] = new_car;
    } else {
        struct car* current = station->tracks[track];
        while (current->next != NULL && strcmp(current->value, target) != 0) {
            current = current->next;
        }

        if (strcmp(current->value, target) == 0) {
            current->capacity += capacity;
            free(new_car);
        } else {
            current->next = new_car;
        }
    }
}

int get_target_capacity(struct station* station,const char* target){
    int track = select_track(station, target);
    struct car* current = station->tracks[track];
    while (current != NULL) {
        if (strcmp(current->value, target) == 0) {
            return current->capacity;
        }
        current = current->next;
    }
    return 0;
}

int count_targets(struct station* station){
    int count = 0;
    for (int i = 0; i < station->track_count; ++i) {
        struct car* current = station->tracks[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}

int count_capacity(struct station* station){
    int total_capacity = 0;
    for (int i = 0; i < station->track_count; ++i) {
        struct car* current = station->tracks[i];
        while (current != NULL) {
            total_capacity += current->capacity;
            current = current->next;
        }
    }
    return total_capacity;
}
