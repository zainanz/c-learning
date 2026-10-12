#include "Array.hpp"
#include <iostream>


int main( void ) {
	Array<char> i(5);
	char &x = i[2];
	x = '5';
	std::cout << x << std::endl;
	std::cout << i[2] << std::endl;
	x = 'x';
	try {
		std::cout << i[4] << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Array Size: " << i.size() << std::endl;
    return 0;
}