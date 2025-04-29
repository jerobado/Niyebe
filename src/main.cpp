#include "niyebe.h"
#include "encryption.h"


int main(int argc, char **argv)
{    
    auto result = parse_command(argc, argv);
    process(result);
    return 0;
}
