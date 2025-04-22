#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    for (int i = 1; i < argc - 1; ++i)
    {
        harl.complain(argv[i]);
    }
}