#pragma once
#include <cstdlib>
#include <iostream>

class Base {
    public:
        virtual ~Base();
};
class A : public Base {};
class B : public Base {};
class C : public Base {};
// class D : public Base {}; --> Uncomment to run D dtemp tests;


Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);


