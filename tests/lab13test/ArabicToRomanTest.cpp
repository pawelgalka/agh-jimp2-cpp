//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <ArabicRoman.h>

TEST(ArabicToRomanTest, ConversionOf1) {
    EXPECT_EQ("I", ArabicToRoman(1));
}

TEST(ArabicToRomanTest, ConversionOf4) {
    EXPECT_EQ("IV", ArabicToRoman(4));
}

TEST(ArabicToRomanTest, ConversionOf1251) {
    EXPECT_EQ("MCCLI", ArabicToRoman(1251));
}

TEST(ArabicToRomanTest, ConversionOf3888) {
    EXPECT_EQ("MMMDCCCLXXXVIII", ArabicToRoman(3888));
}

TEST(ArabicToRomanTest, ConversionOfNegativeValue) {
    EXPECT_THROW(ArabicToRoman(-10),std::invalid_argument);
}

TEST(ArabicToRomanTest, ConversionOfBigValue) {
    EXPECT_THROW(ArabicToRoman(5000),std::invalid_argument);
}