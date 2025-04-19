#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		
	public:
		int oldest;
		Contact contacts[8];
		PhoneBook();
};

#endif