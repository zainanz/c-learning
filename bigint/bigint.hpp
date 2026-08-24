#pragma once
#include <iostream>
#include <cmath>

class bigint {
	public:
		bigint(); 
		~bigint();
		bigint(unsigned int);
		bigint(const bigint& bint);
		const std::string&	getBigIntStr() const;
		bigint	operator+(bigint& bint);
		bigint	operator+(int x);
		bigint	operator+=(int x);
		bigint&	operator=(const bigint& bint);
		bigint	operator<<(int x);
		bigint	operator>>(int x);
		bigint	operator<<=(int x);
		bigint	operator>>=(int x);
		bigint	operator>>(const bigint& b);
		bigint	operator>>=(const bigint& b);
		bigint	operator<<(const bigint& bint);
		bigint	operator<<=(const bigint& bint);
		bigint	operator+=(const bigint& bint);
		bigint	operator+(const bigint& bint);
		bigint	operator+=(bigint& bint);
		bigint	operator+(bigint& bint);
		bigint	operator+(bigint& bint) const;
		bigint	operator++();
		bigint	operator++(int);

	private:
		std::string	strnum_;
		static void	bigIntAddInt(bigint& btemp, int x);
		static void	perform_ls(bigint& bint, int x);
		static void	perform_rs(bigint& bint, int x);


};

std::ostream&	operator<<(std::ostream& os, bigint& bint);
std::ostream&	operator<<(std::ostream& os,const bigint& bint);