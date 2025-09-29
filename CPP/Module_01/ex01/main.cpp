#include "Zombie.hpp"

int main(void)
{
	Zombie *ptr;

	std::cout << "Dragon Veldora Tempest: **ROARRRRRRRRRRRRRR**\n";
	ptr = zombieHorde(5, "trovo");
	ptr->announce();
	delete [] ptr;
}