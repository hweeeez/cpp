#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

//template <typename F>

template<typename T> void iter(T *array, int arrayLength, void (*func)(T&))
{
	for (int i = 0; i < arrayLength; i++)
	{
		func(array[i]);
	}
}

#endif
