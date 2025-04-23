#include "niyebe.h"
#include "encryption.h"


int main(int argc, char **argv)
{

    std::cout << "random number: " << get_random_number(1, 4) << std::endl;
    //std::cout << "random number: " << get_random_number(1, 4) << std::endl;
    //std::cout << "random number: " << get_random_number(1, 4) << std::endl;
    //std::cout << "random number: " << get_random_number(1, 4) << std::endl;

    std::cout << std::endl;

    display_welcome_message(argc);
    
    auto result = parse_command(argc, argv);
    if (result.has_value())
        random_string(result.value());

    return 0;
}
