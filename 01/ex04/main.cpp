#include <iostream>
#include <fstream>
#include <cstring>

void replaceLine(std::string* line, std::string s2, int start, int* end)
{
    std::string copy;

    copy = *line;
    (*line).resize(copy.size() + s2.size());
    (*line) = copy.substr(0, start) + s2 + copy.substr(*end, copy.size() - start);
    (*end) = start + s2.size() - 1;
}

int processLine(std::string* line, std::string s1, std::string s2)
{
    unsigned long i = -1;
    int s1len = s1.size();
    while ((i = (*line).find(s1, i + 1)) != std::string::npos)
    {
		int end = i + s1len;
		replaceLine(line, s2, i, &(end));
    }

    return (0);
}

int main(int argc, char **argv)
{
    std::string text;
    (void)argc;
    if (argc != 4)
	{
		std::cout << "Bad Args" << '\n';
        return (0);
	}
    std::ofstream wfile;
    std::string wname = argv[1];
	std::ifstream rfile(argv[1]);
	if (!rfile.good())
	{
		std::cout << "Bad file" << '\n';
		return (0);
	}
    //rfile.open(argv[1]);
    wname.append(".replace");
    wfile.open((const char*)(wname.c_str()));
	if (!wfile.is_open())
	{
		std::cout << "Bad file" << '\n';
		return (0);
	}
    while (std::getline(rfile, text))
    {
		//std::cout << text << '\n';
        processLine(&text, argv[2], argv[3]);
        wfile << text << '\n';
    }
    rfile.close();
    wfile.close();
    return (0);
}
