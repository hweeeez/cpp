#include "Array.hpp"

int main(void)
{
	//int a[4] = { 1, 2, 3, 4 };
	int* a = new int();
	std::cout << *a << '\n';

	Array<int> b(2);
	Array<int> c;

	for (int i = 0; i < 2; i++)
	{
		b[i] = 0 + i;
		std::cout << b[i] << '\n';
	}
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
}