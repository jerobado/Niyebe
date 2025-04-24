#include <exception>
#include <getopt.h>
#include <iostream>
#include <optional>
#include "NiyebeConfig.h"


// Program operations
void display_welcome_message(int argc);
std::optional<int> parse_command(int argc, char **argv);

// Options
void help_option();
std::optional<int> length_option(std::string input);
void version_option();
