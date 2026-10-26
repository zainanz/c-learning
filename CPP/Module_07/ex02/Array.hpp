#pragma once
#include <stdexcept>
#include <sstream>

template <typename T>
class Array {
	public:
		Array();
		~Array();
		Array(unsigned int n);
		T&	operator[](unsigned int n);
		Array(const Array<T>& copy);
		unsigned int	size();
	private:
		T				*array;
		unsigned int	_size;

};
#include "Array.tpp"
