#include "Zombie.hpp"

int main()
{
    Zombie* zombie = zombieHorde(10, "bad");
    delete[] zombie;
}