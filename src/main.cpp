#include <iostream>
#include "NiyebeConfig.h"


// for debugging only
void printd(std::string message);

void display_welcome_message();
void random_string(int length);
char random_lowercase(void);
char random_uppercase(void);
char random_special(void);



int main(int argc, char **argv)
{
    display_welcome_message();
    return 0;
}


void printd(std::string message)
{
    /* Handy function for printing in the console while debugging. */

    std::cout << message << std::endl;
}


void display_welcome_message()
{
    std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                           << Niyebe_VERSION_MINOR << "."
                           << Niyebe_VERSION_PATCH << std::endl;
    std::cout << "Simple password generator for the forgetful\n";
}
