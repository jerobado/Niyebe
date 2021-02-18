#include <iostream>
#include "NiyebeConfig.h"


void random_string(int length);
char random_lowercase(void);
char random_uppercase(void);
char random_special(void);



int main(int argc, char **argv)
{

    std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                           << Niyebe_VERSION_MINOR << "."
                           << Niyebe_VERSION_PATCH << std::endl;
    std::cout << "Simple password generator for the forgetful\n";

    return 0;
}
