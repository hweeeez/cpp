#include "Base.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h> 
#include <ctime>
#include <exception>

Base* Base::generate(void)
{
	std::srand(std::time(0));
	int rng = std::rand() % 3;
	std::cout << rng << '\n';
	if (rng == 0)
		return new A();
	if (rng == 1)
		return new B();
	if (rng == 2)
		return new C();
	return NULL;
}

void Base::identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "A" << '\n';
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "B" << '\n';
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << "C" << '\n';
}

void Base::identify(Base& p)
{
	Base *base = &p;
	identify(base);
}

int main()
{
	Base *b = new Base();
	Base *r = b->generate();

	b->identify(r);
	b->identify(*r);
}