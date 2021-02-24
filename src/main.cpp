#include <iostream>
#include <getopt.h>
#include "NiyebeConfig.h"


// for debugging only
void printd(std::string message);

void display_welcome_message(int argc);
void random_string(int length);
char random_lowercase(void);
char random_uppercase(void);
char random_special(void);



int main(int argc, char **argv)
{
    display_welcome_message(argc);

    int option_char;
    int str_length;

    while (true)
    {
        static struct option long_options[] = {
            {"length", required_argument, NULL, 'l'},
            {0, 0, 0, 0}
        };
        int option_index = 0;

        option_char = getopt_long(argc, argv, "l:", long_options, &option_index);
        
        // Exit loop when no optional character found
        if (option_char == -1)
            break;
        
        switch (option_char)
        {
            case 'l':
                std::cout << optarg << std::endl;
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
