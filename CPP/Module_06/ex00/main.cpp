#include "ScalarConverter.hpp"
#include <ostream>

int main(int argc, char *argv[]){
    if (argc > 2){
        std::cerr << "Too many arguments." << std::endl;
        return 1;
    }
    if (argc == 1){
        std::cout << "char: " << "Impossible" << std::endl;
        std::cout << "int: " << "Impossible" << std::endl;
        std::cout << "float: " << "Impossible" << std::endl;
        std::cout << "double: " << "Impossible" << std::endl;
        return 0;
    }
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}