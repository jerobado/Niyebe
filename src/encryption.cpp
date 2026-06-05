#include "encryption.h"
#include "ascii_characters.h"
#include <iostream>
#include <ranges>
#include <openssl/rand.h>


int
RandomGenerator::generateRandomNumber(int min, int max)
{
    unsigned char random_byte;
    if (RAND_bytes(&random_byte, 1) != 1)
    {
        std::cerr << "Unable to create random byte." << std::endl;
        return 1;
    }

    int range = max - min + 1;
    int random_number = (random_byte % range) + min;

    return random_number;
}

std::string 
RandomGenerator::generateString(int stringLength)
{
    std::string result;
    result.reserve(stringLength);
    
    auto range = std::views::iota(0, stringLength);
    for ([[maybe_unused]] int unusedIndex : range)
    {
        switch (generateRandomNumber(1, 4))
        {
            case 1:
                result += ASCII_LOWERCASE.at(generateRandomNumber(1, 26));
                break;
            case 2:
                result += ASCII_UPPERCASE.at(generateRandomNumber(1, 26));
                break;
            case 3:
                result += ASCII_DIGIT.at(generateRandomNumber(0, 9));
                break;
            case 4:
                result += ASCII_SYMBOL.at(generateRandomNumber(1, 32));
                break;
        }
    }
    return result;
}

std::string
RandomGenerator::generateDigits(int stringLength)
{
    std::string result;
    result.reserve(stringLength);

    auto range = std::views::iota(0, stringLength);
    for ([[maybe_unused]] int unusedIndex : range)
    {
        result += ASCII_DIGIT.at(generateRandomNumber(0, 9));
    }

    return result;
}

std::string
RandomGenerator::generateLowercase(int stringLength)
{
    std::string result;
    result.reserve(stringLength);

    auto range = std::views::iota(0, stringLength);
    for ([[maybe_unused]] int unusedIndex : range)
    {
        result += ASCII_LOWERCASE.at(generateRandomNumber(1, 26));
    }

    return result;
}

std::string
RandomGenerator::generateUppercase(int stringLength)
{
    std::string result;
    result.reserve(stringLength);

    auto range = std::views::iota(0, stringLength);
    for ([[maybe_unused]] int unusedIndex : range)
    {
        result += ASCII_UPPERCASE.at(generateRandomNumber(1, 26));
    }

    return result;
}

std::string
RandomGenerator::generateSymbols(int stringLength)
{
    std::string result;
    result.reserve(stringLength);

    auto range = std::views::iota(0, stringLength);
    for ([[maybe_unused]] int unusedIndex : range)
    {
        result += ASCII_SYMBOL.at(generateRandomNumber(1, 32));
    }

    return result;
}