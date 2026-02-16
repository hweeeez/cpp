#include "whatever.hpp"

void addone(int &a)
{
	a += 1;
	std::cout << a << '\n';
}

int main(void)
{
	int a[4] = { 1, 2, 3, 4 };
	::iter(a, 4, addone);	
	return 0;
}