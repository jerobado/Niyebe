#include "niyebe.h"
#include "encryption.h"
#include <format>
#include <openssl/opensslv.h>


Niyebe::Niyebe(int argc, char **argv)
{
    result = parseArguments(argc, argv);
}

std::optional<int>
Niyebe::parseArguments(int argc, char **argv)
{
    opterr = 0; // Disable default error message for unknown optional arguments

    int option_char;
    while (true)
    {
        static struct option long_options[] = {
            {"help",    no_argument,        NULL, 'h'},
            {"version", no_argument,        NULL, 'v'},
            {0,         0,                  0,     0 }
        };
        int option_index = 0;
        option_char = getopt_long(argc, argv, "hv", long_options, &option_index);
        
        // Exit loop when no more optional characters to process
        if (option_char == -1) break;
        
        switch (option_char)
        {
            case 'h':
                helpOption();
                return std::nullopt;
            case 'v':
                versionOption();
                return std::nullopt;
            case '?':
                std::cout << "Unknown option.\n\n";
                helpOption();
                return std::nullopt;
        }
    }

    if (optind >= argc)
    {
        std::cout << "Missing required number.\n\n";
        helpOption();
        return std::nullopt;
    }

    if (optind + 1 < argc)
    {
        std::cout << "Too many arguments. Only one positional argument is allowed.\n\n";
        helpOption();
        return std::nullopt;
    }
    
    return lengthOption(argv[optind]);
}

void
Niyebe::helpOption()
{
    RandomGenerator randomGenerator;
    std::cout << "Usage: niyebe <number> [--help] [--version]\n";
    std::cout << std::endl;
    std::cout << "Example:\n";
    std::cout << "$ niyebe 46\n";
    std::cout << randomGenerator.generateRandomString(46) << std::endl;
    std::cout << std::endl;
    std::cout << "Options:\n";
    std::cout << " -h, --help\t\t" << "Display this information\n";
    std::cout << " -v, --version\t\t" << "Display the program's current version\n";
}

std::optional<int>
Niyebe::lengthOption(std::string length)
{
    try
    {
        int string_length;
        string_length = std::stoi(length);
        return string_length;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << std::format("INPUT ERROR: '{}' is not a number.\n\n", length);
        std::cout << "Suggestion: Try entering numbers from 1-100.\n";
        return std::nullopt;
    }
}

void
Niyebe::versionOption()
{
    std::cout << std::format("Niyebe {}.{}.{}\n", Niyebe_VERSION_MAJOR, Niyebe_VERSION_MINOR, Niyebe_VERSION_PATCH);
    std::cout << std::format("{}\n", OPENSSL_VERSION_TEXT);
}

int
Niyebe::run()
{
    if (result.has_value())
    {
        RandomGenerator randomGenerator;
        auto string_length = result.value();
        auto random_string = randomGenerator.generateRandomString(string_length);
        std::cout << random_string << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}