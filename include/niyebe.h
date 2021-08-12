#include <chrono>
#include <exception>
#include <getopt.h>
#include <iostream>
#include <random>
#include "NiyebeConfig.h"


// Program operations
void display_welcome_message(int argc);
void parse_command(int argc, char **argv);

// Random algorithims
int random_number(int start, int end);
void random_string(int length);

// Options
void help_option();
void length_option(std::string input);
void version_option();
