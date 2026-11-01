#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec; 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    try {
        std::vector<int>::iterator value_i = easyfind(vec, 4);
        *value_i = 99;
        for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++) std::cout << *i << std::endl;
        value_i = easyfind(vec, 42);
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
