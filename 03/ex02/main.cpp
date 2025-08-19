#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clapTrap = ClapTrap("Luigi");
	clapTrap.attack("Wario");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(2);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);

	std::cout << '\n';
	ScavTrap scavTrap = ScavTrap("Mario");
	scavTrap.attack("Wario");
	scavTrap.guardGate();

	std::cout << '\n';
	FragTrap fragTrap = FragTrap("Yoshi");
	fragTrap.attack("Wario");
	fragTrap.highFivesGuys();

	std::cout << '\n';
	FragTrap YoshiClone(fragTrap);
	YoshiClone.takeDamage(20);

	std::cout << '\n';
	FragTrap YoshiDouble;
	YoshiDouble = fragTrap;
	fragTrap.beRepaired(2);
}