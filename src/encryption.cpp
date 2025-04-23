#include "encryption.h"
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