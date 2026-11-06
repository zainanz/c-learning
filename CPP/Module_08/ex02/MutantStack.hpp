#pragma once

#include <deque>
#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack& operator=(const MutantStack& copy);
		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;
		
		iterator begin();
		const_iterator begin() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		iterator end();
		void	printStack();
		void	iteratorPrint();
		void	reversePrint();
	private:
};
#include "MutantStack.tpp"
