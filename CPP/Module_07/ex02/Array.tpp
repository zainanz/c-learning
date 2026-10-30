#include "Array.hpp"

int escape_error(){
    return 0;
}

template <typename T>
Array<T>::Array() : array(new T[escape_error()]), _size(0){};


template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]){
	for (unsigned int i = 0; i < n; i++) array[i] = 0;
	this->_size = n;
}
template <typename T>
unsigned int	Array<T>::size(){
	return this->_size;
}
template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
T&	Array<T>::operator[](unsigned int n){
	if ((unsigned int)n >= this->_size){
		std::ostringstream s;
		s << "Index " << n << " is out of bounds " << "(size: " << this->_size << ")";
		throw std::out_of_range (s.str());
	}
	return array[n];
}

template <typename T>
Array<T>::Array(const Array<T>& copy): array(new T[copy._size]), _size(copy._size){
    if (this == &copy || copy._size == 0) return ;
	for (unsigned int i = 0; i < copy._size; i++)
        this->array[i] = copy.array[i];
}
