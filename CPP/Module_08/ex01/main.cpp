#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span newSpan(10);
	newSpan.addNumber(952);
	newSpan.addNumber(2);
	newSpan.addNumber(9);
	newSpan.addNumber(152);
	newSpan.addNumber(92);
	newSpan.addNumber(52);
	/*
	try {
		newSpan.addNumber(4);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	*/
	std::cout << newSpan.shortestSpan() << std::endl;
	std::cout << newSpan.longestSpan() << std::endl;
	return 0;
}
