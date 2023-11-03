#include <gtest/gtest.h>
#include "hex.hpp"

class HexTests : public ::testing::Test {
protected:
    void SetUp() override {
        // Инициализация перед каждым тестом, если необходимо
    }

    void TearDown() override {
        // Очистка после каждого теста, если необходимо
    }
};

TEST_F(HexTests, Addition) {
    Hex hex1("1A");
    Hex hex2("0B");
    Hex result = hex1 + hex2;
    EXPECT_EQ(result, Hex("25"));
}

TEST_F(HexTests, Subtraction) {
    Hex hex1("1A");
    Hex hex2("0B");
    Hex result = hex1 - hex2;
    EXPECT_EQ(result, Hex("0F"));
}

TEST_F(HexTests, Comparison) {
    Hex hex1("1A");
    Hex hex2("0B");
    Hex hex3("1A");
    EXPECT_TRUE(hex1 > hex2);
    EXPECT_FALSE(hex1 < hex2);
    EXPECT_TRUE(hex1 == hex3);
    EXPECT_FALSE(hex1 != hex3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
