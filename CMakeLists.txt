cmake_minimum_required(VERSION 3.13)

project(Vector)

add_compile_options(-std=c++14)
include_directories(app/src)

#adding testing
enable_testing()
add_executable(simple_test test/simple_test.cpp app/src/what_a_day.cpp)
add_executable(error_test test/error_test.cpp app/src/what_a_day.cpp)

add_test(simple_test simple_test)
add_test(error_test error_test)
#

add_executable(loop-vector app/main.cpp app/src/what_a_day.cpp)

