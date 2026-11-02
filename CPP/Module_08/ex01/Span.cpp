#include "Span.hpp"

Span::Span(unsigned int n): _cap(n){
}

void	Span::addNumber(int n){
	if (this->data.size() >= this->_cap) throw std::out_of_range("[error] span is full");
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
	std::vector<int> tmp_vec = this->data;
	std::sort(tmp_vec.begin(), tmp_vec.end(), std::greater<int>());
	return (*(tmp_vec.begin()) - *(tmp_vec.end() - 1));
}
