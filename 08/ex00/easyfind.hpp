#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class ElementNotFoundException: public std::exception
{
    public:
    ElementNotFoundException(){}
    const char *what() const throw()
    {
        return "Element Not Found!";
    }
};

template <typename T> typename T::iterator easyfind(T& x, int y)
{
    typename T::iterator iter;
    iter = (std::find(x.begin(), x.end(), y));
    if (iter != x.end())
    {
        return iter;
    }    
    throw ElementNotFoundException();
} 

#endif