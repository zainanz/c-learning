#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

static long int extractValLongInt(const std::string& str, char **endp){
    if (str.size() == 1 && isalpha(str[0]))
        return (str[0]);
    return (strtol(str.c_str(), endp, 10));
}

static double extractValDouble(const std::string& str, char **endp){
    if (str.size() == 1 && isalpha(str[0]))
        return (str[0]);
    return (strtod(str.c_str(), endp));
}

static std::string  convertStrToChar(const std::string& str, long int c){
    if (str == "nan") return "Impossible";
    if (!isascii(static_cast<char>(c))){
        return "Impossible";
    }
    if (std::isprint(static_cast<char>(c))){
        return "'" + std::string(1, static_cast<char>(c)) + "'";
    }
    return "Non displayable";
}

static bool IsNegativeInf(const std::string& str){
    return (str == "-inff" || str == "-inf");
}

static bool IsPositiveInf(const std::string& str){
    return (str == "+inff" || str == "+inf");
}

static std::string  convertStrToInt(const std::string& str, long int c){
    if (str == "nan") return "Impossible";
    if (IsPositiveInf(str) || IsNegativeInf(str)) return "Impossible";
    if (c > INT_MAX || c < INT_MIN) return "Impossible";
    std::ostringstream stri;
    stri << (static_cast<int>(c));
    return stri.str();
}


static std::string  convertStrToFloat(const std::string& str, float c){
    if (str == "nan") return "nanf";
    if (IsNegativeInf(str)) return "-inff";
    if (IsPositiveInf(str)) return "+inff";
    std::ostringstream stri;
    if (std::fmod(c, 1.0) == 0.0)
        stri << std::fixed << std::setprecision(1) << c << "f";
    else 
        stri << std::setprecision(FLT_DIG) << c << "f";
    return stri.str();
}

static std::string  convertStrToDouble(const std::string& str, double c){
    if (str == "nan") return "nan";
    if (IsNegativeInf(str)) return "-inf";
    if (IsPositiveInf(str)) return "+inf";
    std::ostringstream stri;
    if (std::fmod(c, 1.0) == 0.0)
        stri << std::fixed << std::setprecision(1) << c;
    else 
        stri << std::setprecision(DBL_DIG) << c;
    return stri.str();
}

void    ScalarConverter::convert(const std::string& str){
    char *endp = NULL;
    double d;
    long int li;
    try {
        d = extractValDouble(str, &endp);
        if (*endp != '\0'){
            if (*(endp + 1) != '\0') throw true;
            if (*endp != 'f') throw true;
        }
        li = extractValLongInt(str, &endp);
        std::cout << "char: " << convertStrToChar(str, li) << std::endl;
        std::cout << "int: " << convertStrToInt(str, li) << std::endl;
        std::cout << "float: " << convertStrToFloat(str, d) << std::endl;
        std::cout << "double: " << convertStrToDouble(str, d) << std::endl;
    }
    catch (...){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float:  impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
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