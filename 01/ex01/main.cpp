#include "Zombie.hpp"

int main()
{
    Zombie* zombie = zombieHorde(18, "bad");
    delete[] zombie;
}