#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(new T[1]){
	array[0] = 0;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]){
	for (unsigned int i = 0; i < n; i++) array[n] = 0;
	this->_size = n;
}
template <typename T>
unsigned int	Array<T>::size(){
	return this->_size;
}
template <typename T>
T&	Array<T>::operator[](int n){
	if ((unsigned int)n >= this->_size){
		std::ostringstream s;
		s << "Index " << n << " is out of bounds " << "(size: " << this->_size << ")";
		throw std::out_of_range (s.str());
	}
	return array[n];
}