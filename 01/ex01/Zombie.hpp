#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        std::string GetName();
        void SetName(std::string name);
        void announce(void);
        ~Zombie();
        Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif