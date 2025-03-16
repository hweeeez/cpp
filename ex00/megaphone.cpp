#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNEARALE FEEDBACK NOISE *";
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            putchar(toupper(argv[i][j]));
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}