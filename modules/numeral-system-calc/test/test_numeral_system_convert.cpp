// Copyright 2018 Yermakov Alexey

#include <climits>
#include <gtest/gtest.h>

#include "include/numeral_system_calc.h"

TEST(Numeral_System_Convert, Can_Convert) {
    // Arrange
    int n = 86;

    // Act
    std::string res2 = Calc::toString(n, 2);
    std::string res8 = Calc::toString(n, 8);
    std::string res16 = Calc::toString(n, 16);

    // Assert
    EXPECT_STREQ(res2.c_str(), "1010110");
    EXPECT_STREQ(res8.c_str(), "126");
    EXPECT_STREQ(res16.c_str(), "56");
}

TEST(Numeral_System_Convert, Convert_Negative) {
    // Arrange
    int n = -86;

    // Act
    std::string res2 = Calc::toString(n, 2);
    std::string res8 = Calc::toString(n, 8);
    std::string res16 = Calc::toString(n, 16);

    // Assert
    EXPECT_STREQ(res2.c_str(), "-1010110");
    EXPECT_STREQ(res8.c_str(), "-126");
    EXPECT_STREQ(res16.c_str(), "-56");
}

TEST(Numeral_System_Convert, Convert_Max) {
    // Arrange
    int n = INT_MAX;

    // Act
    std::string res2 = Calc::toString(n, 2);
    std::string res8 = Calc::toString(n, 8);
    std::string res16 = Calc::toString(n, 16);

    // Assert
    EXPECT_STREQ(res2.c_str(), "1111111111111111111111111111111");
    EXPECT_STREQ(res8.c_str(), "17777777777");
    EXPECT_STREQ(res16.c_str(), "7FFFFFFF");
}

TEST(Numeral_System_Convert, Convert_Min) {
    // Arrange
    int n = INT_MIN;

    // Act
    std::string res2 = Calc::toString(n, 2);
    std::string res8 = Calc::toString(n, 8);
    std::string res16 = Calc::toString(n, 16);

    // Assert
    EXPECT_STREQ(res2.c_str(), "-10000000000000000000000000000000");
    EXPECT_STREQ(res8.c_str(), "-20000000000");
    EXPECT_STREQ(res16.c_str(), "-80000000");
}
