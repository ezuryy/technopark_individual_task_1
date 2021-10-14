#include <gtest/gtest.h>

extern "C" {
#include <restaurant.h>
}

TEST(Test1, three_simple_guests) {
    restaurant_t R{};
    create_restaurant(&R);
    EXPECT_TRUE(add_guest(&R, 5, (const char*)"dasha", 1));
    EXPECT_TRUE(add_guest(&R, 3, (const char*)"alena", 2));
    EXPECT_TRUE(add_guest(&R, 4, (const char*)"denis", 3));
    bubble_sort(&R);
    EXPECT_EQ(R.guests[0].table_number, 3);
    EXPECT_FALSE(strcmp(R.guests[0].name, "alena"));
    EXPECT_EQ(R.guests[0].bill, 2);
    EXPECT_EQ(R.guests[1].table_number, 4);
    EXPECT_FALSE(strcmp(R.guests[1].name, "denis"));
    EXPECT_EQ(R.guests[1].bill, 3);
    EXPECT_EQ(R.guests[2].table_number, 5);
    EXPECT_FALSE(strcmp(R.guests[2].name, "dasha"));
    EXPECT_EQ(R.guests[2].bill, 1);
    delete_restaurant(&R);
}

TEST(Test2, five_guests_with_fullname) {
    restaurant_t R{};
    create_restaurant(&R);
    EXPECT_TRUE(add_guest(&R, 5, (const char*)"Dasha Kidinova", 1));
    EXPECT_TRUE(add_guest(&R, 3, (const char*)"Alena Dorodnaya", 2));
    EXPECT_TRUE(add_guest(&R, 4, (const char*)"Vasilisa Efimova", 3));
    EXPECT_TRUE(add_guest(&R, 1, (const char*)"Denis Kudinov", 4));
    EXPECT_TRUE(add_guest(&R, 2, (const char*)"Zakhar Ushakov", 5));
    bubble_sort(&R);
    EXPECT_EQ(R.guests[0].table_number, 1);
    EXPECT_FALSE(strcmp(R.guests[0].name, "Denis Kudinov"));
    EXPECT_EQ(R.guests[0].bill, 4);
    EXPECT_EQ(R.guests[1].table_number, 2);
    EXPECT_FALSE(strcmp(R.guests[1].name, "Zakhar Ushakov"));
    EXPECT_EQ(R.guests[1].bill, 5);
    EXPECT_EQ(R.guests[2].table_number, 3);
    EXPECT_FALSE(strcmp(R.guests[2].name, "Alena Dorodnaya"));
    EXPECT_EQ(R.guests[2].bill, 2);
    EXPECT_EQ(R.guests[3].table_number, 4);
    EXPECT_FALSE(strcmp(R.guests[3].name, "Vasilisa Efimova"));
    EXPECT_EQ(R.guests[3].bill, 3);
    EXPECT_EQ(R.guests[4].table_number, 5);
    EXPECT_FALSE(strcmp(R.guests[4].name, "Dasha Kidinova"));
    EXPECT_EQ(R.guests[4].bill, 1);
    delete_restaurant(&R);
}

TEST (Test3, use_without_initialisation) {
    restaurant_t R{};
    EXPECT_FALSE(add_guest(nullptr, 5, (const char*)"dasha", 1.1));
    EXPECT_FALSE(bubble_sort(nullptr));

    create_restaurant(&R);
    EXPECT_TRUE(add_guest(&R, 5, (const char*)"", 1.1));
    EXPECT_EQ(R.guests[0].table_number, 5);
    EXPECT_FALSE(strcmp(R.guests[0].name, ""));
    EXPECT_EQ(R.guests[0].bill, 1.1);

    EXPECT_TRUE(add_guest(&R, 5, nullptr, 1));
    delete_restaurant(&R);
}

TEST (Test4, create_delete_print_read_nullptr) {
    create_restaurant(nullptr);
    delete_restaurant(nullptr);
    testing::internal::CaptureStdout();
    print(nullptr);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "empty\n");
}

TEST (Test5, test_file) {
    restaurant_t R;
    create_restaurant(&R);

    FILE* file;
    file = fopen("../tests/input.txt", "r");
    read_guests(nullptr, file);
    read_guests(&R, file);

    testing::internal::CaptureStdout();
    print(&R);
    std::string output = testing::internal::GetCapturedStdout();
    std::string answer = "1 1.900000 alena\n"
                         "2 10.900000 dasha\n"
                         "3 100.900000 denis\n";
    EXPECT_EQ(output, answer);
    delete_restaurant(&R);
}
