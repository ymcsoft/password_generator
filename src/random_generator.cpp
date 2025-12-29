//
// Created by Yuri Moiseyenko on 2025-12-28.
//
#include "random_generator.h"
#include <iostream>
#include <random>

std::string generateRandomString(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial) {
    std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    std::string numbers = "0123456789";
    std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::string allChars;
    if (useUpper) allChars += upperCase;
    if (useLower) allChars += lowerCase;
    if (useDigits) allChars += numbers;
    if (useSpecial) allChars += special;

    if (allChars.empty()) {
        std::cerr << "Error: At least one character type must be selected." << std::endl;
        return "";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, allChars.length() - 1);

    std::string result;
    for (int i = 0; i < length; i++) {
        result += allChars[dist(gen)];
    }

    return result;
}