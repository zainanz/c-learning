#pragma once
#include <stdexcept>
#include <sstream>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		T&	operator[](int n);
		unsigned int	size();
	private:
		T				*array;
		unsigned int	_size;

};
#include "Array.tpp"