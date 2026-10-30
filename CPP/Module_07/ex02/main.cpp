#include "Array.hpp"
#include <iostream>

int main(int, char**)
{
	Array<char> char_arr(5);
	for (unsigned int i = 0; i < char_arr.size(); i++)
	{
		char_arr[i] = i + '0';
		std::cout << "char_arr[" << i << "] = " << i << std::endl;
	}
	char& x = char_arr[2];
	x = 'x';
	std::cout << "'char& x = char_arr[2];'   -> x = 'x'; (char_arr[i] is " << char_arr[2] << ")" << std::endl;

	Array<char> new_char(char_arr);

	for (unsigned int i = 0; i < new_char.size(); i++)
	{
		new_char[i] = i + 'a';
		std::cout << "new_char[" << i << "] (" << (new_char[i]) << ") " << "== char_arr[i] (" << char_arr[i] << ") : " << (new_char[i] == char_arr[i] ? "true" : "false") << std::endl;
	}


    Array<char> empty(0);
    Array<char> empty_two(empty);
    Array<char> empty_three;
    std::cout << &empty<< std::endl;
    if (empty.size() == 0) {
        std::cout << "empty is an empty array" << std::endl;
    }
    std::cout << &empty_two  << std::endl;
    if (empty_two.size() == 0) {
        std::cout << "empty_two is an empty array" << std::endl;
    }
    std::cout << &empty_three << std::endl;
    if (empty_three.size() == 0) {
        std::cout << "empty_three is an empty array" << std::endl;
    }
  	return (0);
}
