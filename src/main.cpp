#include <getopt.h>
#include "niyebe.h"


int main(int argc, char **argv)
{
    int option_char;
    
    display_welcome_message(argc);
      
    while (true)
    {
        static struct option long_options[] = {
            {"help",    no_argument,        NULL, 'h'},
            {"length",  required_argument,  NULL, 'l'},
            {"version", no_argument,        NULL, 'v'},
            {0, 0, 0, 0}
        };
        int option_index = 0;
        option_char = getopt_long(argc, argv, "hvl:", long_options, &option_index);
        
        // Exit loop when no more optional characters to process
        if (option_char == -1)
            break;
        
        switch (option_char)
        {
            case 'h':
                help_option();
                break;
            case 'l':          
                length_option(optarg);
                break;
            case 'v':
                version_option();
                break;
        }
    }

    return 0;
}
