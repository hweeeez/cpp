#include "PhoneBook.hpp"
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook():oldest(0)
{
    
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + "."; 
    }
    return str;
}

bool    DisplaySearch(PhoneBook& pb)
{
    for (int i = 0; i < 8; i++)
    {
        if (pb.contacts[i].index != -1)
        {
			int no = pb.contacts[i].index + 1;
            std::cout << std::setw(10) << no << std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].firstName())<< std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].lastName()) << std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].nickName()) << std::right << '|';
            std::cout << '\n';
        }
    }
    std::string ind;
    int index = -1;
    std::cout << "Entry: ";
    if (!std::getline(std::cin >> std::ws, ind))
		return false;
	index = std::atoi(ind.c_str());
    //index = strtoll(ind.c_str(), NULL, 10);
    if (index < 1 || index > 8 || pb.contacts[index - 1].index == -1)
        std::cout << "Invalid Entry!" << '\n';
    else
    {
        Contact c = pb.contacts[index - 1];
        std::cout << "First Name: " << c.firstName() << '\n';
        std::cout << "Last Name: " << c.lastName() << '\n';
        std::cout << "Nickname: " << c.nickName() << '\n';
        std::cout << "Phone Number: " << c.Number() << '\n';
        std::cout << "Darkest Secret: " << c.Secret() << '\n';
    }
    return true;
}

int AddContact(PhoneBook& phonebook, Contact contact)
{
    int index;
    for (int i = 0; i < 8; i++)
    {
        if (phonebook.contacts[i].index == -1)
        {
            phonebook.contacts[i] = contact;
            phonebook.contacts[i].SetIndex(i);
            index = i;
            break ;
        }
        if (i == 7 && phonebook.contacts[i].index != -1)
        {
            phonebook.contacts[phonebook.oldest] = contact;
            phonebook.contacts[phonebook.oldest].SetIndex(phonebook.oldest);
            phonebook.oldest++;
            if (phonebook.oldest == 8)
                phonebook.oldest = 0;
        }
    }
    return (0);
}

bool IsValidNumber(const std::string str)
{
    int len = str.size();
	if (len > 10)
		return false;
    for (int i = 0; i < len; i++)
    {
        if (!std::isdigit((unsigned char)(str[i])))
            return false;
    }
    return true;
}

int    MakeContact(PhoneBook& pb)
{
    std::string first;
    std::string second;
    std::string nickname;
    std::string number;
    std::string secret;

    std::cout << "Adding new contact" << '\n';
    std::cout << "First Name: ";
    if (!std::getline(std::cin >> std::ws, first))
        return (0);
    std::cout << "Second Name: ";
    if (!std::getline(std::cin >> std::ws, second))
        return (0);
    std::cout << "Nickname: ";
    if (!std::getline(std::cin >> std::ws, nickname))
        return (0);
    std::cout << "Phone Number: ";
    if (!std::getline(std::cin >> std::ws, number))
        return (0);
    if (!IsValidNumber(number))
    {   
        std::cout << "Invalid number! Must be <= 10 digits long." << '\n'; 
        return (-1);
    }
    std::cout << "Darkest Secret: ";
    if (!std::getline(std::cin >> std::ws, secret))
        return (0);
    AddContact(pb, Contact(first, second, nickname, std::atoi(number.c_str()), secret));
    return (1);
}

int main()
{
    std::string command;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "What do you want to do? (ADD/SEARCH/EXIT) ";
        if (!std::getline(std::cin >> std::ws, command))
            return (0);
        if (command.compare(0, 3, "ADD") == 0 && command.size() == 3)
        {
            if (MakeContact(phoneBook) == 0)
                break;
        }
        if (command.compare(0, 4, "EXIT") == 0 && command.size() == 4)
            break ;
        if (command.compare(0, 6, "SEARCH") == 0 && command.size() == 6)
        {    
            if (!DisplaySearch(phoneBook))
                break;
        }
    }
    return (0);
}
