#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

class NoSpanException: public std::exception
{
    public:
    NoSpanException(){}
    const char *what() const throw()
    {
        return "No Span Found!";
    }
};

class Span
{
    private:
    unsigned int size;
    std::vector<int> container;
    public:
    Span(unsigned int _size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    void print(std::vector<int> a);
};

#endif