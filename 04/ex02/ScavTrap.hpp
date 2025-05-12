#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
    public:
        ~ScavTrap();
        ScavTrap(std::string _name);
        void guardGate();
};

#endif