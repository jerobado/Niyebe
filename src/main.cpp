#include "niyebe.h"
#include "encryption.h"


int main(int argc, char **argv)
{
    display_welcome_message(argc);
    
    auto result = parse_command(argc, argv);
    if (result.has_value())
    {
        auto string_length = result.value();
        auto random_string = generate_random_string(string_length);
        std::cout << random_string << std::endl;
    }

    return 0;
}
