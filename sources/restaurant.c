#include <restaurant.h>

#define MAX_STR_SIZE 100
#define MAX_DIGIT_SIZE 10

bool create_restaurant(restaurant_t* R) {
  if (!R) {
    return false;
  }
  R->guests_count = 0;
  R->capacity = 1;
  R->guests = (guest_t*)malloc(1 * sizeof(guest_t));
  if (!R->guests) {
    return false;
  }
  return true;
}

bool add_guest(restaurant_t* R, size_t table_number, const char* name,
               double bill) {
  if (!R || !R->guests) {
    return false;
  }
  if (R->guests_count == R->capacity) {
    R->capacity = 2 * R->capacity;
    R->guests = (guest_t*)realloc(R->guests, R->capacity * sizeof(guest_t));
    if (!R->guests) {
      return false;
    }
  }
  R->guests[R->guests_count].table_number = table_number;
  if (name) {
    R->guests[R->guests_count].name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(R->guests[R->guests_count].name, name);
  } else {
    R->guests[R->guests_count].name = malloc(1 * sizeof(char));
    strcpy(R->guests[R->guests_count].name, (const char*)"");
  }
  R->guests[R->guests_count].bill = bill;
  R->guests_count++;
  return true;
}

void delete_restaurant(restaurant_t* R) {
  if (!R) {
    return;
  }
  for (long counter = R->guests_count - 1; counter >= 0; --counter) {
    if (R->guests[counter].name) {
      free(R->guests[counter].name);
    }
  }
  free(R->guests);
}

bool bubble_sort(restaurant_t* R) {
  if (!R) {
    return false;
  }
  guest_t tmp;
  for (long i = R->guests_count - 1; i >= 0; --i) {
    bool no_swap = true;
    for (long j = 0; j < i; ++j) {
      if (R->guests[j].table_number > R->guests[j + 1].table_number) {
        tmp = R->guests[j];
        R->guests[j] = R->guests[j + 1];
        R->guests[j + 1] = tmp;
        no_swap = false;
      }
    }
    if (no_swap == true) {
      break;
    }
  }
  return true;
}

void read_guests(restaurant_t* R, FILE* in) {
  if (!R) {
    return;
  }
  char table[MAX_DIGIT_SIZE];
  while (fgets(table, MAX_DIGIT_SIZE, in)) {
    char name[MAX_STR_SIZE];
    char bill[MAX_DIGIT_SIZE];
    fgets(name, MAX_STR_SIZE, in);
    fgets(bill, MAX_DIGIT_SIZE, in);
    long _table = strtol(table, NULL, 10);
    double _bill = strtod(bill, NULL);
    if (!add_guest(R, _table, name, _bill)) {
      return;
    }
  }
}

void print(restaurant_t* R) {
  if (!R) {
    printf("empty\n");
    return;
  }
  bubble_sort(R);
  long counter = 0;
  while (counter < R->guests_count) {
    if (R->guests[counter].name) {
      printf("%zi %f %s", R->guests[counter].table_number,
             R->guests[counter].bill, R->guests[counter].name);
    }
    ++counter;
  }
}
