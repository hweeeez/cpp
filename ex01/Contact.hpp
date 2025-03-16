#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	int	number;
	std::string secret;
public:
	int	index;
	Contact() : index(-1)
	{

	};
	Contact(std::string first, std::string last, std::string nick, int num, std::string sec)
		: firstname(first), lastname(last), nickname(nick), number(num), secret(sec), index(-1)
	{
		
	};
	void SetIndex(int i)
	{
		index = i;
	}
	const std::string firstName()
	{
		return firstname;
	}
	const std::string lastName()
	{
		return lastname;
	}
	const std::string nickName()
	{
		return nickname;
	}
	const std::string Secret()
	{
		return secret;
	}
	const int Number()
	{
		return number;
	}
};

#endif
