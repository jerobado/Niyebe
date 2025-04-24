#include "encryption.h"
#include "ascii_characters.h"
#include <iostream>
#include <openssl/rand.h>


int get_random_number(int min, int max)
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


std::string generate_random_string(int length)
{
    std::string result;
    result.reserve(length);
    
    for (int i=0; i < length; ++i)
    {
        switch (get_random_number(1, 4))
        {
            case 1:
                result += ASCII_LOWERCASE.at(get_random_number(1, 26));
                break;
            case 2:
                result += ASCII_UPPERCASE.at(get_random_number(1, 26));
                break;
            case 3:
                result += ASCII_DIGIT.at(get_random_number(0, 9));
                break;
            case 4:
                result += ASCII_SYMBOL.at(get_random_number(1, 32));
                break;
        }
    }
    return result;
}
