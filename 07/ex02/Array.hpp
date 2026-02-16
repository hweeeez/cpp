#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
	private:
		T* array;
		unsigned int arrsize;
	public:
		Array()
		{
			array = new T[0];
		}
		Array(unsigned int _size)
		{
			arrsize = _size;
			array = new T[arrsize];
		}
		Array(const Array<T> &other)
		{
			*this = other;
		}
		Array<T>& operator=(const Array<T> &other)
		{
			if (this != &other)
			{
				if (this.array != null)
					delete this.array;
				array = new T[other.arrsize];
				for (int i = 0; i < other.arrsize; i++)
				{
					array[i] = other[i];
				}
			}
			return *this;
		}	
		class IndexOutOfBounds : public std::exception
		{
			public:
			const char* what() const throw()
			{
				return "Index Out Of Bounds";
			};
		};
		T& operator[](unsigned int i)
		{
			if (i > arrsize || array == NULL)
				throw IndexOutOfBounds();
			else
				return array[i];
		}
		unsigned int size() const
		{
			return size;
		}
};

// template<typename T>
// const char* what() const override{
// 	return "Index Out of Bounds";
// }

#endif
