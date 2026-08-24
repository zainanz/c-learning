#include "bigint.hpp"

int	main(void){
	bigint a(10);

	// std::cout << a + 55555555 << std::endl ;
	// std::cout << bigint(100000000) + 1<< std::endl ;
	// std::cout << a << std::endl;
	// std::cout << (a += 1) << std::endl ;
	// std::cout << a << std::endl;
	std::cout << "performing ========= << shifts ==========" << std::endl;
	std::cout << (a << 3) << std::endl;
	std::cout  << (a << 10) << std::endl;
	std::cout  << (a << 0) << std::endl;
	std::cout  << (a << -99999) << std::endl;
	std::cout << (a <<= 5) << std::endl;

	std::cout << "a is -> " << a << std::endl;


	std::cout << "performing ========= >> shifts ==========" << std::endl;
	std::cout << (a >> 1) << std::endl;
	std::cout << (a >> 2) << std::endl;
	std::cout << (a >> 3) << std::endl;
	std::cout << "a is -> " << a << std::endl;
	// std::cout << a << std::endl;
	// std::cout  << (a >> 1) << std::endl;
}