#include "Base.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h> 
#include <ctime>
#include <exception>

Base* generate(void)
{
	int rng = std::rand() % 3;
	//std::cout << rng << '\n';
	if (rng == 0)
		return new A();
	if (rng == 1)
		return new B();
	if (rng == 2)
		return new C();
	return NULL;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a != NULL){
		std::cout << "A" << '\n';
		return;
	}
	B* b = dynamic_cast<B*>(p);
	if (b != NULL){
		std::cout << "B" << '\n';
		return;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL){
		std::cout << "C" << '\n';
		return;
	}
}

void identify(Base& p)
{
	try
    { 
        dynamic_cast<A&>(p); 
		std::cout << "A" << '\n';
    }
    catch (std::exception &e){}
    try{
        dynamic_cast<B&>(p);
        std::cout << "B" << '\n';
    }
	catch (std::exception &e){}
	try{
        dynamic_cast<C&>(p);
		std::cout << "C" << '\n';
    }catch (std::exception &e){}

}

int main()
{
	std::srand(std::time(0));

	Base *r = generate();

	identify(r);
	identify(*r);

	delete r;
}