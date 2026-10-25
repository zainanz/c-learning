// test_main.cpp
#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main() {
    const char *tests[] = {
        // chars
        "a", "~", " ", "-", "+", ".", "f", "0", "42", "31", "32", "126", "127",
        "128", "255", "256", "-5", "-128", "-129",

        // int limits
        "2147483647", "2147483648", "-2147483648", "-2147483649",
        "99999999999999999999",

        // floats
        "0.f", "-0.0f", "+4.2f", "42.0f", "42.5f", "3.4028235e38f", "3.5e38f",
        "1e10f", "1.5e-5f", "16777217.0f", "2.0f", "0.1f",

        // doubles
        "0.0", "0.1", "-4.2", "+4.2", "4.", ".5", "1.7976931348623157e308",
        "1e400",

        // pseudo-literals
        "nan", "nanf", "+inf", "-inf", "inf", "+inff", "-inff", "inff",
        "NAN", "INF",

        // invalid
        "", "abc", "2f", "1f", "0.2ff", ".f", "2.0ff", "2..0", "2.0.0",
        "--5", "+-5", "+.", "-.f", "0x2A", " 42", "42 ", "4 2", "'a'",
        "42f", "42.f"
    };

    const size_t n = sizeof(tests) / sizeof(tests[0]);
    for (size_t i = 0; i < n; i++) {
        std::cout << "===== [" << tests[i] << "] =====" << std::endl;
        ScalarConverter::convert(std::string(tests[i]));
        std::cout << std::endl;
    }
    return 0;
}
