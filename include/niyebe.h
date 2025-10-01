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
        int run();

    private:
        std::optional<int> result;
        std::optional<int> parseArguments(int argc, char **argv);
        void helpOption();
        void versionOption();
        std::optional<int> lengthOption(std::string length);
};
