//
// Created by Yuri Moiseyenko on 2025-12-28.
//

#ifndef PASSWORD_GENERATOR_RANDOM_GENERATOR_H
#define PASSWORD_GENERATOR_RANDOM_GENERATOR_H
#include <string>
std::string generateRandomString(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial);
#endif //PASSWORD_GENERATOR_RANDOM_GENERATOR_H