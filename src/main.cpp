#include <chrono>
#include <iostream>
#include <getopt.h>
#include <random>
#include "NiyebeConfig.h"


// for debugging only
void printd(std::string message);

void display_welcome_message(int argc);
int random_number(int start, int end);

// TODO: to be implemented
void random_string(int length);
char random_lowercase(void);
char random_uppercase(void);
char random_special(void);
int random_digit(void);



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


void printd(std::string message)
{
    /* Handy function for printing in the console while debugging. */

    std::cout << message << std::endl;
}


void display_welcome_message(int argc)
{
    if (argc == 1)
    {
        std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                               << Niyebe_VERSION_MINOR << "."
                               << Niyebe_VERSION_PATCH << std::endl;
        std::cout << "Simple password generator for the forgetful\n";
    }
}


int random_number(int start, int end)
{
    /* Return a random number between start and end. */
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 randomizer (seed);
    std::uniform_int_distribution<int> choices(start, end);

    return choices(randomizer);
}


char random_lowercase()
{
    /* Return a random character between a-z based on its ASCII decimal value. */

    int ascii_value = 0;
    ascii_value = random_number(97, 122);
    
    return char(ascii_value);
}


char random_uppercase()
{
    /* Return a random character between A-Z based on its ASCII decimal value. */

    int ascii_value = 0;
    ascii_value = random_number(65, 90);

    return char(ascii_value);
}


int random_digit()
{
    /* Return a random number between 0-9. */

    return random_number(0, 9);
}


void random_string(int length)
{
    for (int i=0; i < length; ++i)
    {
        std::cout << random_lowercase();
    }
    std::cout << "\n";
}
