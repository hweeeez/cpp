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

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{

}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor" << '\n';
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "Claptrap cannot attack, it is DEAD!" << '\n';
		return ;
	}
    std::cout << "Claptrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
    this->energyPoints -= 1;
	std::cout << "Number of energy points left: " << energyPoints << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "Claptrap is dead!" << '\n';
		return ;
	}
    std::cout << "Claptrap took " << amount << " points of damage!" << '\n';
	hitPoints -= amount;
	if (hitPoints <= 0)
	{
		std::cout << "Claptrap is dead!" << '\n';
		hitPoints = 0;
		return ;
	}
	std::cout << "Health: " << hitPoints << '\n';
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
		return ;
    std::cout << "Claptrap gained " << amount << " points of hit points!" << '\n';
    this->energyPoints -= 1;
    hitPoints += amount;
	std::cout << "Number of energy points left: " << energyPoints << '\n';
	std::cout << "Health: " << hitPoints << '\n';
}