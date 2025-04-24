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


void generate_random_string(int length)
{
    for (int i=0; i < length; ++i)
    {
        switch (get_random_number(1, 4))
        {
            case 1:
                std::cout << ASCII_LOWERCASE.at(get_random_number(1, 26));
                break;
                case 2:
                std::cout << ASCII_UPPERCASE.at(get_random_number(1, 26));
                break;
            case 3:
                std::cout << ASCII_DIGIT.at(get_random_number(0, 9));
                break;
            case 4:
                std::cout << ASCII_SYMBOL.at(get_random_number(1, 32));
                break;
        }
    }
    std::cout << "\n";
}
