#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
		ScavTrap();
		ScavTrap& operator=(const ScavTrap &other);
		ScavTrap(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap(std::string _name);
        void guardGate(void);
		void attack(const std::string &target);
};

#endif