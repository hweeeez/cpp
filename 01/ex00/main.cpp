#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("hello");
    zombie->announce();
    randomChump("bye");
    delete zombie;
}