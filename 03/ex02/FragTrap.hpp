#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
		FragTrap();
		FragTrap& operator=(const FragTrap &other);
		FragTrap(const FragTrap &other);
        ~FragTrap();
        FragTrap(std::string _name);
        void highFivesGuys();
};

#endif