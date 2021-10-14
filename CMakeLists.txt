cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -Werror -Wpedantic")
set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Werror -Wpedantic")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# libraries
add_library(common_files STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/restaurant.c)
target_include_directories(common_files PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

# main
add_executable(main
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.c)
target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main common_files)

# gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(test_restaurant
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp)
target_include_directories(test_restaurant PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_restaurant gtest_main common_files)

include(GoogleTest)
gtest_discover_tests(test_restaurant)
