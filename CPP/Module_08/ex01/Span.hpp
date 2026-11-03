#pragma once
#include <exception>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
    public:
		void		addNumber(int n);
		int			shortestSpan();
		int			longestSpan();
        void		addRandomRange(unsigned int size);
		
		int&    	operator[](unsigned int n);

		// canonical
		Span(unsigned int n);
		~Span();
		Span(const Span&);
		const Span& operator=(const Span&);
    private:
		unsigned int		_cap;
		std::vector<int>	data;
};
