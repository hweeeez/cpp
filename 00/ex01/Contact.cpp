#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact() : index(-1)
{

}

Contact::Contact(std::string first, std::string last, std::string nick, int num, std::string sec)
		: firstname(first), lastname(last), nickname(nick), number(num), secret(sec), index(-1)
{
    
}

void Contact::SetIndex(int i)
{
    index = i;
}

const std::string Contact::firstName()
{
    return firstname;
}

const std::string Contact::lastName()
{
    return lastname;
}

const std::string Contact::nickName()
{
    return nickname;
}

const std::string Contact::Secret()
{
    return secret;
}

int Contact::Number()
{
    return number;
}