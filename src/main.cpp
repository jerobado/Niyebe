#include <chrono>
#include <iostream>
#include <getopt.h>
#include <random>
#include <unordered_map>
#include "NiyebeConfig.h"


std::unordered_map<int, char> ASCII_DIGIT {
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
};

std::unordered_map<int, char> ASCII_UPPERCASE {
    {65, 'A'},
    {66, 'B'},
    {67, 'C'},
    {68, 'D'},
    {69, 'E'},
    {70, 'F'},
    {71, 'G'},
    {72, 'H'},
    {73, 'I'},
    {74, 'J'},
    {75, 'K'},
    {76, 'L'},
    {77, 'M'},
    {78, 'N'},
    {79, 'O'},
    {80, 'P'},
    {81, 'Q'},
    {82, 'R'},
    {83, 'S'},
    {84, 'T'},
    {85, 'U'},
    {86, 'V'},
    {87, 'W'},
    {88, 'X'},
    {89, 'Y'},
    {90, 'Z'},
};

std::unordered_map<int, char> ASCII_LOWERCASE {
    { 97, 'a'},
    { 98, 'b'},
    { 99, 'c'},
    {100, 'd'},
    {101, 'e'},
    {102, 'f'},
    {103, 'g'},
    {104, 'h'},
    {105, 'i'},
    {106, 'j'},
    {107, 'k'},
    {108, 'l'},
    {109, 'm'},
    {110, 'n'},
    {111, 'o'},
    {112, 'p'},
    {113, 'q'},
    {114, 'r'},
    {115, 's'},
    {116, 't'},
    {117, 'u'},
    {118, 'v'},
    {119, 'w'},
    {120, 'x'},
    {121, 'y'},
    {122, 'z'},
};


// for debugging only
void printd(std::string message);

void display_welcome_message(int argc);
int random_number(int start, int end);
void random_string(int length);
char random_lowercase(void);    // ok
char random_uppercase(void);    // ok
char random_symbol(void);       // ok
int random_digit(void);         // ok

// TEST: new functions using unordered_map
char random_lowercase_v2(void);


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


char random_lowercase()
{
    /* Return a random character between a-z based on its ASCII decimal value. */

    int ascii_value = 0;
    ascii_value = random_number(97, 122);
    
    return char(ascii_value);
}


char random_lowercase_v2()
{
   /* Get and return a random character in ASCII_LOWERCASE. */ 

    return ASCII_LOWERCASE[random_number(97, 122)];
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


char random_symbol()
{
    /* Return a random symbol. */

    int ascii_value = 0;
    int choice = 0;

    choice = random_number(1, 4);
    if (choice == 1)
        ascii_value = random_number(33, 47);
    else if (choice == 2)
        ascii_value = random_number(58, 64);
    else if (choice == 3)
        ascii_value = random_number(91, 96);
    else if (choice == 4)
        ascii_value = random_number(123, 126);   

    return char(ascii_value);
}


void random_string(int length)
{
    /* Primary function that will generate a random string based on the given length. */

    for (int i=0; i < length; ++i)
    {
        switch(random_number(1, 4))
        {
            case 1:
                std::cout << ASCII_LOWERCASE[random_number(97, 100)];
                break;
            case 2:
                std::cout << ASCII_UPPERCASE[random_number(65, 90)];
                break;
            case 3:
                std::cout << ASCII_DIGIT[random_number(0, 9)];
                break;
            case 4:
                std::cout << random_symbol();
                break;
        }
    }
    std::cout << "\n";
}
