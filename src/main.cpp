#include "niyebe.h"


int main(int argc, char **argv)
{
    display_welcome_message(argc);
    parse_command(argc, argv);
 
    return 0;
}
