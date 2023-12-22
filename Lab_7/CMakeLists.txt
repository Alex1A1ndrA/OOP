cmake_minimum_required(VERSION 3.10)
project(lab7)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

find_package(GTest REQUIRED)

add_executable(main.out main.cpp dungeon_location.cpp npc.cpp dragon.cpp knight.cpp elf.cpp game_controller.cpp)
add_executable(gtests.out test.cpp dungeon_location.cpp npc.cpp dragon.cpp knight.cpp elf.cpp)

target_link_libraries(gtests.out ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

enable_testing()

add_test(gtests gtests)
