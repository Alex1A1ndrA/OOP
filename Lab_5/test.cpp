#include <gtest/gtest.h>
#include "MyAllocator.h"
#include "MyStack.h"

// Тесты для MyAllocator
TEST(MyAllocatorTest, AllocateAndDeallocate) {
    MyAllocator<int, 10> allocator;
    int* ptr = allocator.allocate(5);

    EXPECT_NE(ptr, nullptr);

    allocator.deallocate(ptr, 5);
    // Нет необходимости проверять возвращаемое значение deallocate, так как этот метод не возвращает ничего
}

// Тесты для MyStack
TEST(MyStackTest, PushAndTop) {
    MyStack<int, MyAllocator<int, 10>> stack;
    stack.push(42);

    EXPECT_EQ(stack.top(), 42);
}

TEST(MyStackTest, Pop) {
    MyStack<int, MyAllocator<int, 10>> stack;
    stack.push(42);
    stack.pop();

    EXPECT_TRUE(stack.empty());
}

TEST(MyStackTest, Size) {
    MyStack<int, MyAllocator<int, 10>> stack;
    stack.push(1);
    stack.push(2);

    EXPECT_EQ(stack.size(), 2);
}

TEST(MyStackTest, Iterator) {
    MyStack<int, MyAllocator<int, 10>> stack;
    stack.push(1);
    stack.push(2);

    int sum = 0;
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        sum += *it;
    }

    EXPECT_EQ(sum, 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
