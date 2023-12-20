#include "a_station.h"
#include <stdlib.h>
#include <string.h>
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
