#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ~ClapTrap();
        ClapTrap();
        ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
        void setName(std::string _name);
        void setHitPoints(int points);
        void setEnergyPoints(int energy);
        void setAttackDamage(int attack);
		// std::string getName();
        // int getHitPoints();
        // int getEnergyPoints();
        // int getAttackDamage();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif