#pragma once
#include <iostream>

class bigint {
	public:
		bigint(unsigned int);
		const std::string&	getBigIntStr() const;
		bigint	operator+(bigint& bint);
		bigint	operator+(int x);
	private:
		std::string	strnum_;

};

std::ostream&	operator<<(std::ostream& os, bigint& bint);
std::ostream&	operator<<(std::ostream& os,const bigint& bint);