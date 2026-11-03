#include "Span.hpp"

Span::Span(unsigned int n): _cap(n){
}

Span::~Span(){
}

Span::Span(const Span& copy)
{
    *this = copy;
}

const Span& Span::operator=(const Span& copy)
{
    if (this != &copy){
        this->_cap = copy._cap;
        this->data = copy.data;
    }
    return (*this);
}

void	Span::addNumber(int n){
	if (this->data.size() >= this->_cap) throw std::out_of_range("[error] span isyy full");
	this->data.push_back(n);
	return ;
}
int	Span::shortestSpan(){
	if (!this->data.size() || this->data.size() == 1) throw std::length_error("[error] not enough values to compare.");
	std::vector<int> tmp_vec = this->data;
	std::sort(tmp_vec.begin(), tmp_vec.end());
	int diff = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = tmp_vec.begin(); it + 1 != tmp_vec.end(); it++)
	{
		diff = std::min(diff, *(it + 1) - *it);
	}
	return diff;
}

int	Span::longestSpan(){
	if (!this->data.size() || this->data.size() == 1) throw std::length_error("[error] not enough values to compare.");	
    int res = *std::max_element(this->data.begin(), this->data.end()) - *std::min_element(this->data.begin(), this->data.end());
    return res;
}

void    Span::addRandomRange(unsigned int size)
{
    if (this->_cap <= this->data.size() + size) throw std::out_of_range("[error] span cannot fit all those numbers.");
    for (unsigned int i = 0; i < size; i++){
        this->data.push_back(rand());
    }
    return ;
}

int&    Span::operator[](unsigned int n)
{
    // if (n >= this->data.size()) throw std::out_of_range("[error] out of range."); -> already handled?
    return this->data[n];
}

