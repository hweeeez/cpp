#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap = ClapTrap("Luigi");
	clapTrap.attack("Wario");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(2);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
}