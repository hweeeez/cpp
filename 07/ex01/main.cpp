#include "iter.hpp"

void addone(int &a)
{
	a += 1;
	std::cout << a << '\n';
}

void printstring(std::string &s)
{
	std::cout << s;
}

int main(void)
{
	int a[4] = { 1, 2, 3, 4 };
	::iter(a, 4, addone);	

	std::string b[4] = { "this ", "is ", " a", " string." };
	::iter(b, 4, printstring);	
	return 0;
}