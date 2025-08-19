#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constructor" << '\n';
}

ClapTrap::ClapTrap(std::string _name) : name(_name)
{
    std::cout << "ClapTrap Actual Constructor" << '\n';
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap Copy Constructor" << '\n';
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy Assignment Constructor" << '\n';
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
    std::cout << "ClapTrap Destructor" << '\n';
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