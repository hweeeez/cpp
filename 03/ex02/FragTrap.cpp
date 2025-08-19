#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default Constructor" << '\n';
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap Actual Constructor" << '\n';
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor" << '\n';
	std::cout << "FragTrap attackDamage: " << attackDamage << '\n';
	std::cout << "FragTrap hitPoints: " << hitPoints << '\n';
	std::cout << "FragTrap energyPoints: " << energyPoints << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy Assignment Constructor" << '\n';
	ClapTrap::operator=(other);
	std::cout << "FragTrap attackDamage: " << attackDamage << '\n';
	std::cout << "FragTrap hitPoints: " << hitPoints << '\n';
	std::cout << "FragTrap energyPoints: " << energyPoints << '\n';
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor" << '\n';
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "POSITIVE HIGH_FIVES REQUEST" << '\n';
}