#include "iter.hpp"
#include <iostream>

void    AddOne(int& x){
    x += 1;
}

/*
void    AddOne_C(char& x){
    x += 1;
}
*/

int main( void ) {
    int nums[] = {1,2,3,4,5,6,7};


    int len = sizeof(nums) / sizeof(int);
    ::iter<int>(nums, len, AddOne);
    for (int i = 0; i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    /* -> char cast iter
    int nums[] = {1,2,3,4,5,6,7};
    int len = sizeof(nums) / sizeof(int);
    ::iter<char>((char *)nums, len, AddOne_C);
    for (int i = 0; i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    */
    return 0;
}
