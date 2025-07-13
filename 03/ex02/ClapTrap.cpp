#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor" << '\n';
}

ClapTrap::ClapTrap(std::string _name) : name(_name)
{
    std::cout << "Actual Constructor" << '\n';
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor" << '\n';
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "Attacking" << '\n';
    this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "Taking Damage" << '\n';
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "Repairing" << '\n';
    this->energyPoints -= 1;
    hitPoints += amount;
}

void ClapTrap::setName(std::string _name)
{
    name = _name;
}

void ClapTrap::setHitPoints(int points)
{
    this->hitPoints = points;
}
void ClapTrap::setEnergyPoints(int energy)
{
    this->energyPoints = energy;
}

void ClapTrap::setAttackDamage(int attack)
{
    this->attackDamage = attack;
}