#include "ascii_characters.h"
#include "niyebe.h"
#include <openssl/opensslv.h>


void display_welcome_message(int argc)
{
    if (argc == 1)
    {
        version_option();
        std::cout << "\nSimple pseudo-random password generator for the forgetful.\n\n";
        help_option();
    }
}


std::optional<int> parse_command(int argc, char **argv)
{
    int option_char;
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
            return std::nullopt;
        
        switch (option_char)
        {
            case 'h':
                help_option();
                return std::nullopt;
            case 'l':          
                return length_option(optarg);
            case 'v':
                version_option();
                return std::nullopt;
        }
    }
}


// [] TODO: analyze generated seed if its unique and no duplicate
int random_number(int start, int end)
{
    /* Return a random number between start and end. */
   
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 randomizer (seed);
    std::uniform_int_distribution<int> choices(start, end);

    return choices(randomizer);
}


// [] TODO: add simple string stistics, ie, total length, number of characters, etc.
void random_string(int length)
{
    /* Primary function that will generate a random string based on the given length. */

    for (int i=0; i < length; ++i)
    {
        switch(random_number(1, 4))
        {
            case 1:
                std::cout << ASCII_LOWERCASE.at(random_number(1, 26));
                break;
            case 2:
                std::cout << ASCII_UPPERCASE.at(random_number(1, 26));
                break;
            case 3:
                std::cout << ASCII_DIGIT.at(random_number(0, 9));
                break;
            case 4:
                std::cout << ASCII_SYMBOL.at(random_number(1, 32));
                break;
        }
    }
    std::cout << "\n";
}


// Options
void help_option()
{
    std::cout << "Usage: niyebe [--length] <number>\n";
    std::cout << std::endl;
    std::cout << "Example:\n";
    std::cout << "$ niyebe --length 16\n";
    random_string(16);
    std::cout << std::endl;
    std::cout << "Options:\n";
    std::cout << " -h, --help\t\t" << "Display this information\n";
    std::cout << " -l, --length\t\t" << "Generate pseudo-random string based on given length\n";
    std::cout << " -v, --version\t\t" << "Display the program's current version\n";
}


std::optional<int> length_option(std::string input)
{
    try
    {
        int string_length;
        string_length = std::stoi(input);
        return string_length;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "INPUT ERROR: " << "\"" << input << "\"" << " is not a valid number.\n\n";
        std::cout << "Suggestion: Try entering numbers from 1-100.\n";
        return std::nullopt;
    }
}


void version_option()
{
    std::cout << "Niyebe " << Niyebe_VERSION_MAJOR << "." 
                           << Niyebe_VERSION_MINOR << "."
                           << Niyebe_VERSION_PATCH << std::endl;
    std::cout << OPENSSL_VERSION_TEXT << std::endl;                           
}
