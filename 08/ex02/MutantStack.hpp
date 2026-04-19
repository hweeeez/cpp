#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container>
{
	private:
	public:
	MutantStack() : std::stack<T, Container>()
	{

	}
	MutantStack(std::stack<T, Container> &other) : std::stack<T, Container>(other) {}
	std::stack<T, Container> &operator=(const std::stack<T, Container> &other)
	{
		if (*this != other)
			this = other;
		return *this;
	}
	~MutantStack(){};
	typedef typename Container::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif