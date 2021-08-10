#include <chrono>
#include <iostream>
#include <getopt.h>
#include <random>
#include "NiyebeConfig.h"
#include "ascii_characters.h"


// Function declration
void display_welcome_message(int argc);
int random_number(int start, int end);
void random_string(int length);


void display_welcome_message(int argc)
{
    if (argc == 1)
    {
        std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                               << Niyebe_VERSION_MINOR << "."
                               << Niyebe_VERSION_PATCH << std::endl;
        std::cout << "Simple pseudo-random password generator for the forgetful\n";
    }
}


// [] TODO: analyze generated seed if its unique and no duplicate
int random_number(int start, int end)
{
    /* Return a random number between start and end. */
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 randomizer (seed);
    std::uniform_int_distribution<int> choices(start, end);

    return choices(randomizer);
}


// [] TODO: add simple string stistics, ie, total length, number of characters, etc.
void random_string(int length)
{
    /* Primary function that will generate a random string based on the given length. */

    for (int i=0; i < length; ++i)
    {
        switch(random_number(1, 4))
        {
            case 1:
                std::cout << ASCII_LOWERCASE[random_number(1, 26)];
                break;
            case 2:
                std::cout << ASCII_UPPERCASE[random_number(1, 26)];
                break;
            case 3:
                std::cout << ASCII_DIGIT[random_number(0, 9)];
                break;
            case 4:
                std::cout << ASCII_SYMBOL[random_number(1, 32)];
                break;
        }
    }
    std::cout << "\n";
}


// ---------------
// main() is here!
// ---------------
int main(int argc, char **argv)
{
    display_welcome_message(argc);

    int option_char;
    int str_length;

    while (true)
    {
        static struct option long_options[] = {
            {"length", required_argument, NULL, 'l'},
            {"version", no_argument, NULL, 'v'},
            {0, 0, 0, 0}
        };
        int option_index = 0;

        option_char = getopt_long(argc, argv, "vl:", long_options, &option_index);
        
        // Exit loop when no more optional characters to process
        if (option_char == -1)
            break;
        
        switch (option_char)
        {
            case 'l':
                str_length = std::stoi(optarg);
                random_string(str_length);
                break;
            case 'v':
                std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                                       << Niyebe_VERSION_MINOR << "."
                                       << Niyebe_VERSION_PATCH << std::endl;
                break;
        }
    }

    return 0;
}
