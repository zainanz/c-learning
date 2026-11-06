#include "MutantStack.hpp"
#include <vector>
#include <cstdlib>
#include <limits>

int main(void)
{
	MutantStack<int, std::vector<int> > ms;

	std::srand(time(0));
	int	rval;
	std::cout << "Stack - [";
	#define MAX_INTS 42 
	for (int i = 0; i < MAX_INTS; i++)
	{
		rval =  (std::numeric_limits<int>::max() / std::rand()) * 3;
		std::cout << rval;
		if (i != MAX_INTS - 1) std::cout << ", ";
		ms.push(rval);
	}
	#undef MAX_INTS
	std::cout << "]" << std::endl;

/*
 // Error 
	MutantStack<int, std::vector<int> >::const_iterator cit = ms.begin();
	MutantStack<int, std::vector<int> >::const_reverse_iterator crit = ms.rbegin();
	*cit = 4;
	*crit = 4;
*/

	MutantStack<int, std::vector<int> >::iterator it = ms.begin();
	MutantStack<int, std::vector<int> >::reverse_iterator rit = ms.rbegin();
	std::cout << "*IT(ms.begin) = " << *it << std::endl;
	std::cout << "*RIT(ms.rbegin) = " << *rit << std::endl;
	*it = 4;
	*rit = 4;
	ms.printStack();
	ms.iteratorPrint();
	ms.reversePrint();

	MutantStack<int, std::vector<int> > broken;
	broken.printStack();
	broken.iteratorPrint();
	broken.reversePrint();
	while (!ms.empty())
	{

		std::cout<< "POPPING: "<< ms.top() << std::endl;
		ms.pop();
	}
	return 0;
}
