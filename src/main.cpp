#include <iostream>
#include "NiyebeConfig.h"


int main(int argc, char **argv)
{

    std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                           << Niyebe_VERSION_MINOR << "."
                           << Niyebe_VERSION_PATCH << std::endl;
    std::cout << "Simple password generator for the forgetful\n";

    return 0;
}
