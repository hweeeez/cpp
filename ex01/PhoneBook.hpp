#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
	private:
		
	public:
		int oldest;
		PhoneBook() : oldest(0)
		{
			
		};
		Contact contacts[8];
};

#endif