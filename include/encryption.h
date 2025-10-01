#pragma once

#include <string>

class IRandomGenerator
{
    public:
        virtual int generateRandomNumber(int min, int max) = 0;
        virtual std::string generateRandomString(int stringLength) = 0;
        virtual ~IRandomGenerator() { }
};


class RandomGenerator : public IRandomGenerator
{
    public:
        int generateRandomNumber(int min, int max) override;
        std::string generateRandomString(int stringLength) override;
};
