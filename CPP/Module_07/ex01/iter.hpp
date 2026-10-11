#pragma once

template <typename T>
void    iter(T *addr, const int arrlen, void (*f)(T&f)){
    for (int i = 0; i < arrlen; i++) f(addr[i]);
}