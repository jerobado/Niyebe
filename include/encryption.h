#pragma once

#include <string>


class IRandomGenerator
{
    public:
        virtual int generateRandomNumber(int min, int max) = 0;
        virtual std::string generateString(int stringLength) = 0;
        virtual std::string generateDigits(int stringLength) = 0;
        virtual std::string generateLowercase(int stringLength) = 0;
        virtual std::string generateUppercase(int stringLength) = 0;
        virtual ~IRandomGenerator() { }
};


class RandomGenerator : public IRandomGenerator
{
    public:
        int generateRandomNumber(int min, int max) override;
        std::string generateString(int stringLength) override;
        std::string generateDigits(int stringLength) override;
        std::string generateLowercase(int stringLength) override;
        std::string generateUppercase(int stringLength) override;
};
