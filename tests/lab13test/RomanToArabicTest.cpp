//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <ArabicRoman.h>

TEST(RomanToArabicTest, ConversionOfI) {
    EXPECT_EQ(1, RomanToArabic("I"));
}

TEST(RomanToArabicTest, ConversionOf4) {
    EXPECT_EQ(4, RomanToArabic("IV"));
}

TEST(RomanToArabicTest, ConversionOf1251) {
    EXPECT_EQ(1251, RomanToArabic("MCCLI"));
}

TEST(RomanToArabicTest, ConversionOf3888) {
    EXPECT_EQ(3888, RomanToArabic("MMMDCCCLXXXVIII"));
}

TEST(RomanToArabicTest, ConversionOfInvalidString) {
    EXPECT_THROW(RomanToArabic("ABC"),std::invalid_argument);
}

