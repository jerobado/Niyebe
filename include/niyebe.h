#include <exception>
#include <getopt.h>
#include <iostream>
#include <optional>
#include "NiyebeConfig.h"


// Program operations
std::optional<int> parse_command(int argc, char **argv);
void process(std::optional<int> result);

// Options
void help_option();
std::optional<int> length_option(std::string input);
void version_option();
