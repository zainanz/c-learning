#include "Zombie.hpp"

int main(void)
{
	Zombie *z_ptr;
	z_ptr = newZombie("small-z");
	randomChump("big-Z");
	delete z_ptr;
}