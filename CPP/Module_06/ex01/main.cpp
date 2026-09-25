#include "Serializer.hpp"
#include <iostream>

int main(void){
    Data a;
    a.c = 'z';
    a.i = 42;
    a.str = "My name is zainan!";

    uintptr_t address = Serializer::serialize(&a);
    std::cout << "Address: " << address << std::endl;
    std::cout << "&Data: " << (long int)(&a) << std::endl;

    Data *b = (Data *)(address);
    std::cout << "Data *b = (Data *)(address) -> " << (long int)b << std::endl;
    std::cout << b->str << std::endl;


    Data *c = Serializer::deserialize(address);
    std::cout << "Data *c = Serializer::deserialize(address) -> " << (long int)c << std::endl;
    std::cout << c->str << std::endl;

    return 0;
}