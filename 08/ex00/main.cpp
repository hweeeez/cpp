#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
    std::list<int> a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(10);
    
    try {
        std::list<int>::iterator result = easyfind(a, 10);
        std::cout << "Found: " << *result << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    try {
        std::list<int>::iterator result = easyfind(a, 3);
        std::cout << "Found: " << *result << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

    std::vector<int> v;
    v.push_back(8);
    v.push_back(4);
    v.push_back(9);
    try {
        std::vector<int>::iterator result = easyfind(v, 10);
        std::cout << "Found: " << *result << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    try {
        std::vector<int>::iterator result = easyfind(v, 9);
        std::cout << "Found: " << *result << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

    std::deque<char> d;
    d.push_back('c');
    d.push_back('a');
    d.push_back('t');
    try {
        std::deque<char>::iterator result = easyfind(d, 'a');
        std::cout << "Found: " << *result << std::endl;
        result--;
        std::cout << "Iter--: " << *result << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::deque<char>::iterator result = easyfind(d, 't');
        std::cout << "Found: " << *result << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}