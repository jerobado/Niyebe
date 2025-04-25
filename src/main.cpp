#include "niyebe.h"
#include "encryption.h"


int main(int argc, char **argv)
{    
    auto result = parse_command(argc, argv);

    // TODO: create a new function for this, ie. process(result)
    if (result.has_value())
    {
        auto string_length = result.value();
        auto random_string = generate_random_string(string_length);
        std::cout << random_string << std::endl;
    }

    return 0;
}
