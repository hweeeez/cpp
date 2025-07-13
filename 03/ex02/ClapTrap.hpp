#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ~ClapTrap();
        ClapTrap();
        ClapTrap(std::string _name);
        void setName(std::string _name);
        void setHitPoints(int points);
        void setEnergyPoints(int energy);
        void setAttackDamage(int attack);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif