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
	Contact();
	Contact(std::string first, std::string last, std::string nick, int num, std::string sec);
	void SetIndex(int i);
	const std::string firstName();
	const std::string lastName();
	const std::string nickName();
	const std::string Secret();
	int Number();
};

#endif
