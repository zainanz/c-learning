#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

static std::string  convertStrToChar(const std::string& str){
    try {
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
        long int c = strtol(str.c_str(), NULL, 10);
        std::ostringstream stri;
        stri << (static_cast<int>(c));
        return stri.str();
    }
    catch (...){
        return "Impossible";
    }
}

static std::string  convertStrToFloat(const std::string& str){
    (void) str;
    return "Impossible";
}

static std::string  convertStrToDouble(const std::string& str){
    (void) str;
    return "Impossible";
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