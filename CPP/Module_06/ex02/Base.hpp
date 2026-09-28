#pragma once
#include <cstdlib>
#include <iostream>

class A : public Base {};
class B : public Base {};
class C : public Base {};

class Base {
    public:
        virtual ~Base();
};

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);


