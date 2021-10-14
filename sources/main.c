#include <restaurant.h>

int main() {
  restaurant_t R;
  create_restaurant(&R);
  printf(
      "Enter the table number, name and bill in different lines. To stop enter "
      "Сtrl+D:\n");
  read_guests(&R, stdin);
  print(&R);
  delete_restaurant(&R);
  return 0;
}
