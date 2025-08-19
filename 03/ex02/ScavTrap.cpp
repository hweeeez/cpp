#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Constructor" << '\n';
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap Actual Constructor" << '\n';
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor" << '\n';
	std::cout << "ScavTrap AttackDamage: " << attackDamage << '\n';
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy Assignment Constructor" << '\n';
	ClapTrap::operator=(other);
	std::cout << "ScavTrap AttackDamage: " << attackDamage << '\n';
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor" << '\n';
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
