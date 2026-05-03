#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try{
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span sp1 = Span (1);
    sp1.addNumber(1);

    try{
        std::cout << sp1.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::vector<int> spanner;
    for (int i = 0; i < 10; i++)
    {
        spanner.push_back(i);
    }
    Span sp2 = Span(999);
    try{
        sp2.addNumber(spanner.begin(), spanner.end());
        sp2.print();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::vector<int> spanner1;
    for (int i = 10; i < 21; i++)
    {
        spanner1.push_back(i);
    }
    try{
        sp2.addNumber(spanner1.begin(), spanner1.end());
        sp2.print();
        std::cout << '\n';
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}