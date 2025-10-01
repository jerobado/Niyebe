#pragma once

#include <exception>
#include <getopt.h>
#include <iostream>
#include <optional>
#include "NiyebeConfig.h"


class Niyebe
{
    public:
        Niyebe(int argc, char **argv);
        void run();

    private:
        std::optional<int> result;
        std::optional<int> parseArguments(int argc, char **argv);
        void process(std::optional<int> result);
        void helpOption();
        std::optional<int> lengthOption(std::string length);
        void versionOption();
};
