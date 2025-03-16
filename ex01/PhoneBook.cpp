#include "PhoneBook.hpp"

std::string truncate(std::string str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + "."; 
    }
    return str;
}
void    DisplaySearch(PhoneBook& pb)
{
    for (int i = 0; i < 8; i++)
    {
        if (pb.contacts[i].index != -1)
        {
            std::cout << std::setw(10) << truncate(std::to_string(pb.contacts[i].index + 1)) << std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].firstName())<< std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].lastName()) << std::right << '|';
            std::cout << std::setw(10) << truncate(pb.contacts[i].nickName()) << std::right << '|';
            std::cout << '\n';
        }
    }
    std::string ind;
    int index = -1;
    std::cout << "Entry: ";
    std::getline(std::cin >> std::ws, ind);
    index = std::stoi(ind.c_str(), NULL, 10);
    if (index > 8 || index < 1)
        std::cout << "Invalid number!" << '\n';
    else
    {
        Contact c = pb.contacts[index - 1];
        std::cout << "First Name: " << c.firstName() << '\n';
        std::cout << "Last Name: " << c.lastName() << '\n';
        std::cout << "Nickname: " << c.nickName() << '\n';
        std::cout << "Phone Number: " << c.Number() << '\n';
        std::cout << "Secret: " << c.Secret() << '\n';
    }
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

int    MakeContact(PhoneBook& pb)
{
    std::string first;
    std::string second;
    std::string nickname;
    std::string number;
    std::string secret;
    int num;

    std::cout << "Adding new contact" << '\n';
    std::cout << "First Name: ";
    std::getline(std::cin >> std::ws, first);
    std::cout << "Second Name: ";
    std::getline(std::cin >> std::ws, second);
    std::cout << "Nickname: ";
    std::getline(std::cin >> std::ws, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin >> std::ws, number);
    const char *cstr = number.c_str();
    num = strtoll(cstr, NULL, 10);
    if (num == 0)
    {
        std::cout << "Invalid number!" << '\n';
        return (0);
    }
    std::cout << "Darkest Secret: ";
    std::getline(std::cin >> std::ws, secret);
    AddContact(pb, Contact(first, second, nickname, num, secret));
    return (1);
}

int main()
{
    std::string command;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "What do you want to do? (ADD/SEARCH/EXIT) ";
        std::getline(std::cin >> std::ws, command);
        if (command.compare(0, 3, "ADD") == 0)
            MakeContact(phoneBook);
        if (command.compare(0, 4, "EXIT") == 0)
            break ;
        if (command.compare(0, 6, "SEARCH") == 0)
            DisplaySearch(phoneBook);
    }
    return (0);
}