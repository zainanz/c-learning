#pragma once
#include <iostream>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#define FLT_DIG 6
#define DBL_DIG 15

class ScalarConverter {
    public:
    static void         convert(const std::string&  str);
    private:
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter&    operator=(const ScalarConverter& copy);
        ScalarConverter();
        virtual ~ScalarConverter() = 0;
};