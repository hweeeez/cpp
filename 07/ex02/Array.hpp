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
			array = NULL;
			arrsize = 0;
		}
		Array(unsigned int _size)
		{
			arrsize = _size;
			array = new T[arrsize]();
		}
		Array(const Array<T> &other)
		{
			this->array = NULL;
			*this = other;
		}
		Array<T>& operator=(const Array<T> &other)
		{
			if (this != &other)
			{
				if (this->array != NULL)
					delete []this->array;
				array = new T[other.arrsize];
				arrsize = other.arrsize;
				for (unsigned int i = 0; i < other.arrsize; i++)
				{
					array[i] = other.array[i];
				}
			}
			return *this;
		}
		~Array()
		{
			if (this->array != NULL)
				delete []array;
		}
		class IndexOutOfBounds : public std::exception
		{
			public:
			const char* what() const throw();
		};
		T& operator[](unsigned int i)
		{
			if (i >= arrsize || array == NULL)
				throw IndexOutOfBounds();
			else
				return array[i];
		}
		const T& operator[](unsigned int i) const
		{
			if (i >= arrsize || array == NULL)
				throw IndexOutOfBounds();
			else
				return array[i];
		}
		unsigned int size() const
		{
			return arrsize;
		}
};

template<typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw(){
	return "Index Out of Bounds";
}

#endif
