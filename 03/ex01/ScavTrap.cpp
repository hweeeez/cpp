#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default Constructor" << '\n';
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "Actual Constructor" << '\n';
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{

}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor" << '\n';
}

void ScavTrap::guardGate()
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap cannot guard, it is DEAD!" << '\n';
		return ;
	}
    std::cout << "In Gate Keeper mode" << '\n';
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "ScavTrap cannot attack, it is DEAD!" << '\n';
		return ;
	}
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << '\n';
    setEnergyPoints(energyPoints - 1);
	std::cout << "Number of energy points left: " << energyPoints << '\n';
}
