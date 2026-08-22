#include "bigint.hpp"

bigint::bigint(unsigned int val){ 
	strnum_ = "";
	while (val){
		strnum_.push_back('0' + (val % 10));
		val /= 10;
	}	
}
const std::string&	bigint::getBigIntStr() const{
	return (this->strnum_);
}

std::ostream&	operator<<(std::ostream& os, bigint& bint){
	const std::string bintstr = bint.getBigIntStr();
	int	bint_size = bintstr.size();
	for (int i = 0; i < bint_size; i++){
		os << bintstr[i];
	}
	return (os);
}

std::ostream&	operator<<(std::ostream& os, const bigint& bint){
	std::string bintstr = bint.getBigIntStr();
	for (int i = bintstr.size(); i >= 0; i--) os << bintstr[i];
	return (os);
}

bigint	bigint::operator+(bigint& bint){
}

bigint	bigint::operator+(int x){
	int last_val = 0;
	for (int i = 0; i < this->strnum_.size(); i++){
		std::cout << "Index\tx_val\ttemp\tstrnum[i]\tlastval\t {x = " << x << ", before change strnum[i] = " << strnum_[i] << std::endl;
		std::cout << "i = " << i << "\t"; 
		int x_val = x % 10;
		std::cout << x_val << "\t";
		x /= 10;
		int temp = last_val + (strnum_[i] - '0') + x_val;
		last_val = temp / 10;
		std::cout << temp << "\t";
		strnum_[i] = (temp % 10) + '0';
		std::cout << strnum_[i] << "\t\t";
		std::cout << last_val << "\t";
		if ((last_val != 0 || x != 0 )&& i + 1 == this->strnum_.size())
		{
			strnum_ += '0';
			std::cout << "\t last_val != 0 -> adding += 0 to strnum_ "; 
		} else {
			std::cout << "\t last_value == 0 && end!"; 
		}
		std::cout << std::endl;
	}
	std::cout << strnum_ << std::endl;
	return (*this);
}
// 		  1 1 1
//  	9 9 0 0
//  	8 9 9 0
// = 	7 9 0 1
// 		str[i]		X%10 			last_val
//   temp = 8 		+	 9 		+	 	0 			 = 17 , X = 2, last_val = 1, str[i] = 7
//   temp = 9 		+	 2 		+ 		1 			 = 12,  X = 0, last_val = 1, str[i] = 2
//   temp = 9 		+	 0 		+ 		1 			 = 10,  X = 0, last_val = 1, str[i] = 0;
//   temp = 9 		+    0      +       1 			 = 10, 	X = 0, last_val = 1, str[i] = 0





//  bi[0] + (x % 10) => 8

//  9 + 8 = 17
//  last_val = 0;
//  if (bi[0] + (x%10)) >= 10 { // 17
// 	bi[0] = (bi[0] + (x%10)) % 10; // 17 % 10 => 7
// 	last_val = (17 - 7) / 10 = 1;	
//  }


