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

void replaceLine(std::string* line, std::string s2, int start, int* end)
{
    //int i = 0;
    std::string copy;

    strcpy(*line, &copy);
    // while (s2[i] != '\0')
    // {
    //     (*line)[start] = s2[i];
    //     i++;
    //     start++;
    // }
    // if (start != end)
    // {
    //     (*line).resize(start + copy.size() - end); 

    //     while ((copy)[end] != '\0')
    //     {
    //         (*line)[start] = (copy)[end];
    //         start++;
    //         end++;
    //     }
    // }
    (*line).resize(copy.size() + s2.size());
    (*line) = copy.substr(0, start) + s2 + copy.substr(*end, copy.size() - start);
    (*end) = start + s2.size() - 1;
}

int processLine(std::string* line, std::string s1, std::string s2)
{
    int i = 0;
    int len = (*line).size();
    int s1len = s1.size();
    while (i < len)
    {
        int k = i;
       for (int j = 0; j < s1len; j++)
       {
            if ((*line)[k] ==  s1[j])
            {
                k++;
                if (s1[j + 1] == '\0')
                { 
                    replaceLine(line, s2, i, &k);
                    i = k;
                    len = (*line).size();
                    break;
                }
            }
       }
       i++;
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
    std::ofstream wfile;
    std::string wname = argv[1];

    rfile.open(argv[1]);
    wname.append(".replace");
    wfile.open((const char*)(wname.c_str()));
    while (std::getline(rfile, text))
    {
        processLine(&text, argv[2], argv[3]);
        wfile << text << '\n';
    }
    rfile.close();
    wfile.close();
    return (0);
}