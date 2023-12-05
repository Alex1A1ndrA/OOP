#include <gtest/gtest.h>
#include "MyStack.hpp"
#include "MyAllocator.hpp"

TEST(MyStackTest, BasicOperations) {
    MyStack<int, MyAllocator<int>> stack;

    ASSERT_TRUE(stack.empty());
    ASSERT_EQ(stack.size(), 0);

    stack.push(42);
    ASSERT_FALSE(stack.empty());
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 42);

    stack.pop();
    ASSERT_TRUE(stack.empty());
    ASSERT_EQ(stack.size(), 0);
}

TEST(MyStackTest, CustomAllocator) {
    MyAllocator<int> customAllocator;
    MyStack<int, MyAllocator<int>> stack(customAllocator);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    ASSERT_EQ(stack.top(), 3);
    stack.pop();
    ASSERT_EQ(stack.top(), 2);
    stack.pop();
    ASSERT_EQ(stack.top(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
