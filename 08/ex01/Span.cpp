#include "Span.hpp"

Span::Span(unsigned int x)
{
    size = x;
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        size = other.size;
        container = other.container;
    }
    return *this;
}

Span::~Span()
{

}

// int Span::shortestSpan()
// {
//     if (container.size() < 2)
//         throw NoSpanException();
//     std::vector<int> dup = container;
//     int shortest = INT_MAX;
//     for (int i = 0; i < static_cast<int>(dup.size()) - 1; i++)
//     {
//         int comp = -1;
//         if (dup[i + 1] > dup[i])
//             comp = dup[i + 1] - dup[i];
//         if (dup[i + 1] < dup[i])
//             comp = dup[i] - dup[i + 1];
//         if (comp < shortest)
//         {
//             shortest = comp;
//         }
//     }
//     return shortest;
// }

int Span::shortestSpan()
{
    if (container.size() < 2)
        throw NoSpanException();
    std::vector<int> dup = container;
    std::sort(dup.begin(), dup.end());
    int shortest = INT_MAX;
    for (int i = 0; i < static_cast<int>(dup.size()) - 1; i++)
    {
        if (dup[i + 1] - dup[i] < shortest)
        {
            shortest = dup[i + 1] - dup[i];
        }
    }
    return shortest;
}

int Span::longestSpan()
{
    if (container.size() < 2)
        throw NoSpanException();
    return *std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end());
}

void Span::addNumber(int num)
{
    if (container.size() + 1 > size)
        throw SpanOverflow();
    container.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (container.size() + std::distance(start, end) > size)
        throw SpanOverflow();
    container.insert(container.end(), start, end);
}

void Span::print()
{
    for (int i = 0; i < static_cast<int>(container.size()); i++)
    {
        std::cout << container[i] << ' ';
    }
}

const char *Span::NoSpanException::what(void) const throw()
{
	return ("No Span Found!");
}

const char *Span::SpanOverflow::what(void) const throw()
{
	return ("Cannot add, Span is full!");
}

