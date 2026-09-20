#pragma once
#include <iostream>
#include <climits>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
    public:
    static void         convert(const std::string&  str);
    private:
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter&    operator=(const ScalarConverter& copy);
        ScalarConverter();
        virtual ~ScalarConverter() = 0;
};