#include "Base.hpp"
#include <iostream>

int main(void){
	std::srand(time(NULL));
	Base *x = NULL;
	for (int i = 0 ; i < 10 ; i++){
		std::cout << "xxxxxxxx ~" << i << "~ xxxxxxxxxx"  << std::endl;
		x = generate();
		identify(x);
		identify(*x);
		std::cout << std::endl;
	}
    return 0;
}