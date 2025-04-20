#include <iostream>
#include <fstream>
#include <cstring>

void strcpy(std::string src, std::string* dest)
{
    // int len = (src).size();

    // for (int i = 0; i < len; i++)
    // {
    //     (*dest)[i] = src[i];
    // }
    (*dest) = src;
}

void replaceLine(std::string* line, std::string s2, int start, int end)
{
    int i = 0;
    std::string copy;

    strcpy(*line, &copy);
    while (s2[i] != '\0')
    {
        (*line)[start] = s2[i];
        i++;
        start++;
    }
    if (start != end)
    {
        (*line).resize(start + copy.size() - end); 

        while ((copy)[end] != '\0')
        {
            (*line)[start] = (copy)[end];
            start++;
            end++;
        }
    }
}

int processLine(std::string* line, std::string s1, std::string s2)
{
    int len = (*line).size();
    int s1len = s1.size();
    for (int i = 0; i < len; i++)
    {
        int k = i;
       for (int j = 0; j < s1len; j++)
       {
            if ((*line)[k] ==  s1[j])
            {
                k++;
                if (s1[j + 1] == '\0')
                { 
                    replaceLine(line, s2, i, k);
                    break;
                }
            }
       }
    }
    return (0);
}

int main(int argc, char **argv)
{
    std::string text;
    (void)argc;
    if (argc != 4)
        return (0);
    std::ifstream rfile;
    rfile.open(argv[1]);
    while (std::getline(rfile, text))
    {
        processLine(&text, argv[2], argv[3]);
        std::cout << text << '\n';
    }
    rfile.close();
}