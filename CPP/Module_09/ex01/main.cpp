#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "invalid args: ex ./RPN \"2 4 1 + \"";
		return 1;
	}
	RPN::run(argv[1]);
	return 1;
}
