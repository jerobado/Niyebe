#include "encryption.h"
#include "ascii_characters.h"
#include <iostream>
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
RandomGenerator::generateRandomString(int stringLength)
{
    std::string result;
    result.reserve(stringLength);
    
    for (int i=0; i < stringLength; ++i)
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
