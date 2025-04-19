#include <iostream>
#include <fstream>

void processLine(std::string line, std::string s1, std::string s2)
{
    int len = line.size();
    int s1len = s1.size();
    for (int i = 0; i < len; i++)
    {
       for (int j = 0; j < s1len; j++)
       {
            if (line[i] ==  s1[j])
            {

            }
            else
            {
                break;
            }
       }
       i++;
    }
}

int main(int argc, char **argv)
{
    std::string text;

    if (argc != 4)
        return (0);
    std::ifstream rfile;
    rfile.open(argv[1]);
    while (std::getline(rfile, text))
    {
        std::cout << text << '\n';
    }
    rfile.close();
}