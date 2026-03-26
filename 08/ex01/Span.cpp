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

int Span::shortestSpan()
{
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
    return *std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end());
}

void Span::addNumber(int num)
{
    container.push_back(num);
}

void Span::print(std::vector<int> a)
{
    for (int i = 0; i < static_cast<int>(a.size()); i++)
    {
        std::cout << a[i] << '\n';
    }
}

