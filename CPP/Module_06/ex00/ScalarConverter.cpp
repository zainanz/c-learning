#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

static std::string  convertStrToChar(const std::string& str){
    try {
        if (str == "nan") return "Impossible";
        long int c = strtol(str.c_str(), NULL, 10);
        if (!isascii(static_cast<char>(c))){
            return "Impossible";
        }
        if (std::isprint(static_cast<char>(c))){
            return "'" + std::string(1, static_cast<char>(c)) + "'";
        }
        return "Non displayable";
    }
    catch (...){
        return "Impossible";
    }

}

static std::string  convertStrToInt(const std::string& str){
    try {
        if (str == "nan") return "Impossible";
        long int c = strtol(str.c_str(), NULL, 10);
        if (c > INT_MAX || c < INT_MIN) return "Impossible";
        std::ostringstream stri;
        stri << (static_cast<int>(c));
        return stri.str();
    }
    catch (...){
        return "Impossible";
    }
}

static bool IsNegativeInf(const std::string& str){
    return (str == "-inff" || str == "-inf");
}

static bool IsPositiveInf(const std::string& str){
    return (str == "+inff" || str == "+inf");
}

static std::string  convertStrToFloat(const std::string& str){
    try {
        if (str == "nan") return "nanf";
        if (IsNegativeInf(str)) return "-inff";
        if (IsPositiveInf(str)) return "+inff";
        float c = strtof(str.c_str(), NULL);
        std::ostringstream stri;
        if (std::fmod(c, 1.0) == 0.0)
            stri << std::fixed << std::setprecision(1) << c;
        else 
            stri << std::setprecision(FLT_DIG) << c;
        return stri.str();
    }
    catch (...){
        return "Impossible";
    }
}

static std::string  convertStrToDouble(const std::string& str){
    try {
        double c;
        if (str == "nan") return "nan";
        if (IsNegativeInf(str)) return "-inf";
        if (IsPositiveInf(str)) return "+inf";
        c = strtod(str.c_str(), NULL);
        std::ostringstream stri;
        if (std::fmod(c, 1.0) == 0.0)
            stri << std::fixed << std::setprecision(1) << c;
        else 
            stri << std::setprecision(DBL_DIG) << c;
        return stri.str();
    }
    catch (...){
        return "Impossible";
    }
}

void    ScalarConverter::convert(const std::string& str){
    std::cout << "char: " << convertStrToChar(str) << std::endl;
    std::cout << "int: " << convertStrToInt(str) << std::endl;
    std::cout << "float: " << convertStrToFloat(str) << std::endl;
    std::cout << "double: " << convertStrToDouble(str) << std::endl;
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){
    (void) copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){
    if (this != &copy){
        // do nothing!
    }
    return (*this);
}