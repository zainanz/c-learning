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

	for (unsigned i = 0; i < new_char.size(); i++)
	{
		new_char[i] = i + 'a';
		std::coit << "new_char[" << i << "] == char_arr
	}

	return (0);
}
