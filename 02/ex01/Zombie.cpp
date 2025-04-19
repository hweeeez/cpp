#include "Zombie.hpp"

std::string Zombie::GetName()
{
    return name;
}

void Zombie::SetName(std::string _name)
{
    name = _name;
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << name + " was Destroyed" << '\n';
}

void Zombie::announce(void)
{
    std::cout << name + ": BraiiiiiiinnnzzzZ..." << '\n';
}