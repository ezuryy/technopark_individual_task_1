#ifndef UNTITLED_RESTAURANT_H
#define UNTITLED_RESTAURANT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct guest {
    size_t table_number;
    char* name;
    double bill;
} guest_t;

typedef struct restaurant {
    long guests_count;
    long capacity;
    struct guest* guests;
} restaurant_t;

void create_restaurant(restaurant_t* R);

bool add_guest(restaurant_t* R, size_t table_number, const char* name, double bill);

void delete_restaurant(restaurant_t* R);

bool bubble_sort(restaurant_t* R);

void read_guests(restaurant_t* R, FILE* in);

void print(restaurant_t* R);

#endif //UNTITLED_RESTAURANT_H
