#include <gtest/gtest.h>
#include "function.cpp"

TEST(test_01, random_test) {
    ASSERT_TRUE(fear("Понедельник", 12) == true);
    ASSERT_TRUE(fear("Понедельник", 13) == false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}