#include "restaurant.h"

void create_restaurant(restaurant_t* R) {
    R->guests_count = 0;
    R->capacity = 1;
    R->guests = (guest_t*)malloc(1 * sizeof(guest_t));
}

bool add_guest(restaurant_t* R, size_t table_number, const char* name, double bill) {
    if (R->guests_count == R->capacity) {
        R->capacity = 2 * R->capacity;
        R->guests = (guest_t*)realloc(R->guests, R->capacity * sizeof(guest_t));
    }
    if (R->guests == NULL) return false;
    R->guests[R->guests_count].table_number = table_number;
    R->guests[R->guests_count].name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(R->guests[R->guests_count].name, name);
    R->guests[R->guests_count].bill = bill;
    R->guests_count++;
    return true;
}

void delete_restaurant(restaurant_t* R) {
    for (long counter = R->guests_count - 1; counter >= 0; --counter) {
        free(R->guests[counter].name);
    }
    free(R->guests);
}

void bubble_sort(restaurant_t* R) {
    guest_t tmp;
    bool no_swap;
    for (long i = R->guests_count - 1; i >= 0; i--) {
        no_swap = true;
        for (long j = 0; j < i; j++) {
            if (R->guests[j].table_number > R->guests[j + 1].table_number) {
                tmp = R->guests[j];
                R->guests[j] = R->guests[j + 1];
                R->guests[j + 1] = tmp;
                no_swap = false;
            }
        }
        if (no_swap == true)
            break;
    }
}

