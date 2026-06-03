#pragma once

#include <string>


class IRandomGenerator
{
    public:
        virtual int generateRandomNumber(int min, int max) = 0;
        virtual std::string generateRandomString(int stringLength) = 0;
        virtual std::string generateRandomDigits(int stringLength) = 0;
        virtual std::string generateLowercase(int stringLength) = 0;
        virtual ~IRandomGenerator() { }
};


class RandomGenerator : public IRandomGenerator
{
    public:
        int generateRandomNumber(int min, int max) override;
        std::string generateRandomString(int stringLength) override;
        std::string generateRandomDigits(int stringLength) override;
        std::string generateLowercase(int stringLength) override;
};
