#include "MutantStack.hpp"

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
    return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
    return this->c.rbegin();
}


template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(){
}


template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){
}

template <typename T, typename Container>
void	MutantStack<T, Container>::printStack(){

	std::cout << "[";
	for (size_t i = 0; i < std::stack<T, Container>::c.size(); i++)
	{
		std::cout << std::stack<T, Container>::c[i];
		if (i != this->c.size() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename T, typename Container>
void	MutantStack<T, Container>::iteratorPrint(){
	//typename std::stack<T, Container>::container_type::iterator it;
	typename Container::iterator it;

	std::cout << "["; 
	for (it = this->c.begin(); it != this->c.end();)
	{
		std::cout << *it;
		if (it++ != this->c.end() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename T, typename Container>
void	MutantStack<T, Container>::reversePrint(){
	//- > does the same thing. - std::stack implementations: typedef Container container_type;

	//typename std::stack<T, Container>::container_type::reverse_iterator it;
	typename Container::reverse_iterator it;
	std::cout << "["; 

	for (it = this->c.rbegin(); it != this->c.rend();)
	{
	
		std::cout << *it;
		if (it++ != this->c.rend() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

