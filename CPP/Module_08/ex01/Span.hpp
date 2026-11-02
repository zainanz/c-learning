#pragma once
#include <exception>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    public:
		Span(unsigned int n);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
    private:
		unsigned int		_cap;
		std::vector<int>	data;
};
