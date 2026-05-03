#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

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
    void addNumber(std::vector<int>::iterator iter, std::vector<int>::iterator iter2);
    int shortestSpan();
    int longestSpan();
    void print();
    class NoSpanException : public std::exception
    {
        public:
        virtual	const char* what() const throw();
    };
    class SpanOverflow : public std::exception
    {
        public:
        virtual	const char* what() const throw();
    };
};

#endif