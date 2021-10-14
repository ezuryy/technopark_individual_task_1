#ifndef UNTITLED_RESTAURANT_H
#define UNTITLED_RESTAURANT_H

#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

bool create_restaurant(restaurant_t* R);

bool add_guest(restaurant_t* R, size_t table_number, const char* name,
               double bill);

void delete_restaurant(restaurant_t* R);

bool bubble_sort(restaurant_t* R);

void read_guests(restaurant_t* R, FILE* in);

void print(restaurant_t* R);

#endif  // UNTITLED_RESTAURANT_H
