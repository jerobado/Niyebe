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

std::unordered_map<int, char> ASCII_SYMBOL {
    { 1, '!'},
    { 2, '"'},
    { 3, '#'},
    { 4, '$'},
    { 5, '%'},
    { 6, '&'},
    { 7, '\''},
    { 8, '('},
    { 9, ')'},
    {10, '*'},
    {11, '+'},
    {12, ','},
    {13, '-'},
    {14, '.'},
    {15, '/'},
    {16, ':'},
    {17, ';'},
    {18, '<'},
    {19, '='},
    {20, '>'},
    {21, '?'},
    {22, '@'},
    {23, '['},
    {24, '\\'},
    {25, ']'},
    {26, '^'},
    {27, '_'},
    {28, '`'},
    {29, '{'},
    {30, '|'},
    {31, '}'},
    {32, '~'},
};

std::unordered_map<int, char> ASCII_UPPERCASE {
    { 1, 'A'},
    { 2, 'B'},
    { 3, 'C'},
    { 4, 'D'},
    { 5, 'E'},
    { 6, 'F'},
    { 7, 'G'},
    { 8, 'H'},
    { 9, 'I'},
    {10, 'J'},
    {11, 'K'},
    {12, 'L'},
    {13, 'M'},
    {14, 'N'},
    {15, 'O'},
    {16, 'P'},
    {17, 'Q'},
    {18, 'R'},
    {19, 'S'},
    {20, 'T'},
    {21, 'U'},
    {22, 'V'},
    {23, 'W'},
    {24, 'X'},
    {25, 'Y'},
    {26, 'Z'},
};

std::unordered_map<int, char> ASCII_LOWERCASE {
    { 1, 'a'},
    { 2, 'b'},
    { 3, 'c'},
    { 4, 'd'},
    { 5, 'e'},
    { 6, 'f'},
    { 7, 'g'},
    { 8, 'h'},
    { 9, 'i'},
    {10, 'j'},
    {11, 'k'},
    {12, 'l'},
    {13, 'm'},
    {14, 'n'},
    {15, 'o'},
    {16, 'p'},
    {17, 'q'},
    {18, 'r'},
    {19, 's'},
    {20, 't'},
    {21, 'u'},
    {22, 'v'},
    {23, 'w'},
    {24, 'x'},
    {25, 'y'},
    {26, 'z'},
};


// Function declration
void display_welcome_message(int argc);
int random_number(int start, int end);
void random_string(int length);


// Main starts here
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
