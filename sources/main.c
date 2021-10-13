#include <restaurant.h>

#define MAX_STR_SIZE 100
#define MAX_DIGIT_SIZE 10

void read_from_stdin(restaurant_t* R) {
    if (!exist(R)) {
        return;
    }
    char records_number[MAX_DIGIT_SIZE];
    printf( "Enter guests count:\n" );
    fgets(records_number, MAX_DIGIT_SIZE, stdin);

    printf( "Enter the table number, name and bill in different lines:\n" );
    size_t size = strtol(records_number, NULL, 10);
    size_t counter = 0;
    while (counter < size) {
        char table[MAX_DIGIT_SIZE];
        char name[MAX_STR_SIZE];
        char bill[MAX_DIGIT_SIZE];
        fgets(table, MAX_DIGIT_SIZE, stdin);
        fgets(name, MAX_STR_SIZE, stdin);
        fgets(bill, MAX_DIGIT_SIZE, stdin);
        long _table = strtol(table, NULL, 10);
        double _bill = strtod(bill, NULL);
        add_guest(R, _table, name, _bill);
        ++counter;
    }
}

void print(restaurant_t* R) {
    if (!exist(R)) {
        printf("empty\n");
        return;
    }
    bubble_sort(R);
    long counter = 0;
    while (counter < R->guests_count) {
        printf("%zi %f %s", R->guests[counter].table_number, R->guests[counter].bill, R->guests[counter].name);
        counter++;
    }
}

int main() {
    restaurant_t R;
    create_restaurant(&R);
    read_from_stdin(&R);
    print(&R);
    delete_restaurant(&R);
}


