#include "bigint.hpp"

bigint::bigint(): strnum_("0"){
}

bigint::~bigint(){

}

bigint::bigint(unsigned int val){ 
	strnum_ = "";
	if (val == 0){
		strnum_ = "0";
		return ;
	}
	while (val){
		strnum_.push_back('0' + (val % 10));
		val /= 10;
	}	
}

bigint::bigint(const bigint& bint){
	*this = bint;
}

bigint&	bigint::operator=(const bigint& bint){
	this->strnum_ = bint.strnum_;
	return (*this);
}
const std::string&	bigint::getBigIntStr() const{
	return (this->strnum_);
}

std::ostream&	operator<<(std::ostream& os, bigint& bint){
	std::string bintstr = bint.getBigIntStr();
	for (int i = bintstr.size(); i >= 0; i--) os << bintstr[i];
	return (os);
}

std::ostream&	operator<<(std::ostream& os, const bigint& bint){
	std::string bintstr = bint.getBigIntStr();
	for (int i = bintstr.size(); i >= 0; i--) os << bintstr[i];
	return (os);
}

bigint	bigint::operator+(bigint& bint){
	return bint;
}

bigint	bigint::operator+=(int x){
	bigint::bigIntAddInt(*this, x);
	return (*this);
}


void	bigint::perform_ls(bigint& bint, int x){
	int all_z = 1;

	for (long unsigned i = 0; i < bint.strnum_.size(); i++){
		if (bint.strnum_[i] != '0'){
			all_z = 0;
			break ;
		}
		if (all_z && bint.strnum_.size() == i + 1) {
			bint.strnum_ = "0";
			return ;
		}
	}
	for (int i = 0; i < x; i++) {
		bint.strnum_.insert(0, 1, '0');
	}
}

void	bigint::perform_rs(bigint& btemp, int x){
	if (btemp.strnum_.size() <= (long unsigned) x){
		btemp.strnum_ = "0";
		return ;
	} 
	for (int i = 0; i < x; i++) btemp.strnum_.erase(0, 1);
}

bigint	bigint::operator<<(int x){
	bigint btemp(*this);
	bigint::perform_ls(btemp, x);
	return (btemp);

}
bigint	bigint::operator<<=(int x){
	bigint::perform_ls(*this, x);
	return (*this);
}

bigint	bigint::operator>>(int x){
	bigint btemp(*this);
	bigint::perform_rs(btemp, x);
	return (btemp);
}

bigint	bigint::operator>>=(int x){
	bigint::perform_rs(*this, x);
	return (*this);
}

bigint	bigint::operator<<(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	bigint btemp(*this); 
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		perform_ls(btemp, val);
	}
	return (btemp);
}

bigint	bigint::operator<<=(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		perform_ls(*this, val);
	}
	return (*this);
}
bigint	bigint::operator+(bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	bigint btemp(*this);
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		bigint::bigIntAddInt(btemp, val);
	}
	return (btemp);
}

bigint	bigint::operator++(){
	bigint temp;
	temp.strnum_ = "guess what?! i cant continue to make this anymore.. its so boring!";
	return temp;

}
bigint	bigint::operator++(int){
	bigint temp;
	temp.strnum_ = "guess what?! i cant continue to make this anymore.. its so boring!";
	return temp;
}

bigint	bigint::operator+(bigint& bint) const{
	int	bint_size = bint.strnum_.size();
	int val = 0;
	bigint btemp(*this);
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		bigint::bigIntAddInt(btemp, val);
	}
	return (btemp);
}

bigint	bigint::operator+=(bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		bigint::bigIntAddInt(*this, val);
	}
	return (*this);
}

bigint	bigint::operator+(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	bigint btemp(*this);
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		bigint::bigIntAddInt(btemp, val);
	}
	return (btemp);
}

bigint	bigint::operator+=(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		bigint::bigIntAddInt(*this, val);
	}
	return (*this);
}

bigint	bigint::operator>>(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	bigint btemp(*this); 
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		perform_rs(btemp, val);
	}
	return (btemp);
}

bigint	bigint::operator>>=(const bigint& bint){
	int	bint_size = bint.strnum_.size();
	int val = 0;
	for (int i = 0; i < bint_size; i++){
		val = (bint.strnum_[i] - '0') * std::pow(10, i);
		perform_rs(*this, val);
	}
	return (*this);
}


void	bigint::bigIntAddInt(bigint& btemp, int x){
	int last_val = 0;
	for (long unsigned i = 0; i < btemp.strnum_.size(); i++){
		int x_val = x % 10;
		x /= 10;
		int temp = last_val + (btemp.strnum_[i] - '0') + x_val;
		last_val = temp / 10;
		btemp.strnum_[i] = (temp % 10) + '0';
		if ((last_val != 0 || x != 0 ) && i + 1 == btemp.strnum_.size()) btemp.strnum_ += '0';
	}
}

bigint	bigint::operator+(int x){
	bigint btemp(*this);
	bigint::bigIntAddInt(btemp, x);
	return (btemp);
}

// bigint	bigint::operator+(int x){
// 	int last_val = 0;
// 	for (long unsigned i = 0; i < this->strnum_.size(); i++){
// 		std::cout << "Index\tx_val\ttemp\tstrnum[i]\tlastval\t {x = " << x << ", before change strnum[i] = " << strnum_[i] << std::endl;
// 		std::cout << "i = " << i << "\t"; 
// 		int x_val = x % 10;
// 		std::cout << x_val << "\t";
// 		x /= 10;
// 		int temp = last_val + (strnum_[i] - '0') + x_val;
// 		last_val = temp / 10;
// 		std::cout << temp << "\t";
// 		strnum_[i] = (temp % 10) + '0';
// 		std::cout << strnum_[i] << "\t\t";
// 		std::cout << last_val << "\t";
// 		if ((last_val != 0 || x != 0 )&& i + 1 == this->strnum_.size())
// 		{
// 			strnum_ += '0';
// 			std::cout << "\t last_val != 0 -> adding += 0 to strnum_ "; 
// 		} else {
// 			std::cout << "\t last_value == 0 && end!"; 
// 		}
// 		std::cout << std::endl;
// 	}
// 	std::cout << strnum_ << std::endl;
// 	return (*this);
// }
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


