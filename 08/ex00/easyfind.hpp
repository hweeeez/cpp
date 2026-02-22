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

template <typename T> typename T::value_type easyfind(T& x, int y)
{
    //for (int i = 0; i < (int)x.size(); i++)
    {
        typename T::iterator iter;
        iter = (std::find(x.begin(), x.end(), y));
        if (iter != x.end())
        {
            return *iter;
        }
    }
    throw ElementNotFoundException();
} 

#endif