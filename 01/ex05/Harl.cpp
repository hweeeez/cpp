#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "buggo" << '\n';
}

void Harl::info(void)
{
    std::cout << "MEEP MEEP MEEP MEEP" << '\n';
}

void Harl::warning(void)
{
    std::cout << "WEEWOOWEEWOOWEEWOO" << '\n';
}

void Harl::error(void)
{
    std::cout << "404" << '\n';
}

void Harl::complain(std::string level)
{
    Harl harl;
    //list of pointers to member functions
    void (Harl::*FunctionArray[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levelArray[4] = { "debug", "info", "warning", "error" };

    for (int i = 0; i < 4; ++i)
    {
        if (level == levelArray[i])
            (harl.*FunctionArray[i])();
    }
}