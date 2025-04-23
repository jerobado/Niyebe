#include "niyebe.h"
#include "encryption.h"


int main(int argc, char **argv)
{
    display_welcome_message(argc);
    
    auto result = parse_command(argc, argv);
    if (result.has_value())
        random_string(result.value());

    return 0;
}
