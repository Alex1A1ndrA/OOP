cmake_minimum_required(VERSION 3.10)
project(lab)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_executable(main.out main.cpp)
add_executable(gtests.out test.cpp)

target_link_libraries(gtests.out ${GTEST_LIBRARIES}${CMAKE_THREAD_LIBS_INIT})

enable_testing()

add_test(gtests gtests)