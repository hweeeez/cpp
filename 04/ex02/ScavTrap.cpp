#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
    this->setName(_name);
    this->setHitPoints(100);
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
}

void ScavTrap::guardGate()
{
    std::cout << "In Gate Keeper mode" << '\n';
}