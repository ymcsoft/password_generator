//
// Created by Yuri Moiseyenko on 2025-12-28.
//
#include <gtest/gtest.h>
#include <string>
#include "random_generator.h"

TEST(PasswordGeneratorTest, GeneratesCorrectLength) {
    std::string result = generateRandomString(20, true, true, true, true);
    EXPECT_EQ(result.length(), 20);
}

TEST(PasswordGeneratorTest, OnlyUppercaseLetters) {
    std::string result = generateRandomString(50, true, false, false, false);
    EXPECT_EQ(result.length(), 50);
    for (char c : result) {
        EXPECT_GE(c, 'A');
        EXPECT_LE(c, 'Z');
    }
}

TEST(PasswordGeneratorTest, OnlyLowercaseLetters) {
    std::string result = generateRandomString(50, false, true, false, false);
    EXPECT_EQ(result.length(), 50);
    for (char c : result) {
        EXPECT_GE(c, 'a');
        EXPECT_LE(c, 'z');
    }
}

TEST(PasswordGeneratorTest, OnlyDigits) {
    std::string result = generateRandomString(50, false, false, true, false);
    EXPECT_EQ(result.length(), 50);
    for (char c : result) {
        EXPECT_GE(c, '0');
        EXPECT_LE(c, '9');
    }
}

TEST(PasswordGeneratorTest, AllCharacterTypes) {
    std::string result = generateRandomString(100, true, true, true, true);
    EXPECT_EQ(result.length(), 100);
    EXPECT_FALSE(result.empty());
}

TEST(PasswordGeneratorTest, NoCharacterTypesReturnsEmpty) {
    std::string result = generateRandomString(15, false, false, false, false);
    EXPECT_TRUE(result.empty());
}

TEST(PasswordGeneratorTest, GeneratesDifferentResults) {
    std::string result1 = generateRandomString(20, true, true, true, true);
    std::string result2 = generateRandomString(20, true, true, true, true);
    EXPECT_NE(result1, result2);
}
