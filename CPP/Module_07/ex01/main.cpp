#include "iter.hpp"
#include <iostream>

void    AddOne(int& x){
    x += 1;
}

int main( void ) {
    int nums[] = {1,2,3,4,5,6,7};
    int len = sizeof(nums) / sizeof(int);
    ::iter<int>(nums, len, AddOne);
    for (int i = 0; i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    return 0;
}