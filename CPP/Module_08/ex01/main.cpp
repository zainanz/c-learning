#include "Span.hpp"
#include <iostream>

int main(void)
{
    std::srand(time(NULL));
	Span newSpan(1000000);
    /*
	newSpan.addNumber(952);
	newSpan.addNumber(2);
	newSpan.addNumber(9);
	newSpan.addNumber(152);
	newSpan.addNumber(92);
	newSpan.addNumber(52);
    */
    newSpan.addRandomRange(1000000 - 1);
    Span newnewSpan(newSpan);
    std::cout << "newSpan[5]: " << newSpan[5];
    std::cout << "\t | \t newnewSpan[5]: " << newnewSpan[5] << std::endl;
    newSpan[5] = 5;
    std::cout << "~changed newSpan[5] = 5" << std::endl;
    std::cout << "newSpan[5]: " << newSpan[5];
    std::cout << "\t | \t newnewSpan[5]: " << newnewSpan[5] << std::endl;
	std::cout << "shortest newSpan: " << newSpan.shortestSpan() << std::endl;
	std::cout <<  "longest newSpan: " << newSpan.longestSpan() << std::endl;

	std::cout << "shortest newnewSpan: " << newnewSpan.shortestSpan() << std::endl;
	std::cout <<  "longest newnewSpan: " << newnewSpan.longestSpan() << std::endl;
	return 0;
}
