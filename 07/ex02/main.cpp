#include "Array.hpp"

int main(void)
{
	Array<int> b(2);
	Array<int> c;

	int *a = new int();
	std::cout << *a << '\n';
	std::cout << b[0] << '\n';

	delete a;
	try{
		std::cout << c[0] << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	for (int i = 0; i < 2; i++)
	{
		b[i] = 0 + i;
	}
	c = b;
	for (int i = 0; i < 5; i++)
	{
		try{
		std::cout << b[i] << '\n';
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << "c og:  " << c[i] << '\n';
		c[i] += 2;
		std::cout << "c now: " << c[i] << '\n';
		std::cout << "b now: " << b[i] << '\n';
	}

	const Array<int>d(c);
	std::cout << "Copy c to d" << '\n';
	for (unsigned int i = 0; i < c.size(); i++)
	{
		//d[i] = 0;
		std::cout << d[i] << '\n';
	}
}