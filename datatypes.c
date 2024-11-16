#include <stdio.h>

int main()
{
  // Data Types  ----> Basics

  // Primitive Data types
  // 1)  Integer Data Type

  // The integer datatype in C is used to store the integer numbers (any number including positive, negative and zero without decimal part). Octal values, hexadecimal values, and decimal values can be stored in int data type in C.

  //     Range:  -2,147,483,648 to 2,147,483,647
  //     Size: 4 bytes
  //     Format Specifier: %d

  // Types of Int
  // Unsigned Int - Can only store in a positive value meaning negative is added to positive
  printf("-------------Integers---------------\n");
  printf("\n");
  int unsigned_int = 5U;
  printf("Size of unsigned int %ld bytes\n", sizeof(unsigned int));
  printf("The unsigned integer value is %d\n", unsigned_int);
  printf("It cannot be negative.\nDeclared as int unsigned_int = 5U\n");
  printf("---------------------------------\n");
  // Normal Int -2,147,483,648 to 2,147,483,647
  int normal_int = -10;
  printf("Size of normal int %ld bytes\n", sizeof(int));
  printf("The integer value is %d\n", normal_int);
  printf("Declared as int normal_int = -10\n");
  // Short int (2 bytes) - -32,768 - 32,768
  printf("---------------------------------\n");
  long int long_int = 988888L;
  printf("Size of a long int is %ld bytes\n", sizeof(long int));
  printf("The integer value is %ld\n", long_int);
  printf("Declared as long int long_int = 988888L\n");
  printf("\n");
  printf("-------------Characters---------------\n");
  printf("Character Data Type\n\nCharacter data type allows its variable to store only a single character. The size of the character is 1 byte. It is the most basic data type in C. It stores a single character and requires a single byte of memory in almost all compilers.\n\nRange: (-128 to 127) or (0 to 255)\nSize: 1 byte\nFormat Specifier: %%c\n\n");
  printf("\n");
  char a = 'a';
  char b = 'b';
  printf("1 - char a = 'a'; (NOTE SINGLE QUOTES) \n");
  printf("2 - logs: ");
  printf("'%c'\n", a);
  a++;
  printf("3 - a++; is equvalent to a = a + 1;\n");
  printf("4 - logs: a == ");
  printf("'%c'\n", a);
  printf("Why?\nASCII: a which is 97 when added +1 to it turns 98 which represents B.\n\n");
  printf("-------------Float---------------\n");
  printf("In C programming float data type is used to store floating-point values. Float in C is used to store decimal and exponential values. It is used to store decimal numbers (numbers with floating point values) with single precision.\n\nRange: 1.2E-38 to 3.4E+38\nSize: 4 bytes\nFormat Specifier: %%f\n\n");

  float first_float = 9.0f;
  float second_float = 2.5f;

  // 2x10^-4
  float third_float = 2E-4f;
  printf("\nfloat first_float = 9.0f;\nfloat second_float = 2.5f;\n// 2x10^-4\nfloat third_float = 2E-4f;\n");
  printf("logs: first_float = %f\n", first_float);
  printf("logs: second_float = %f\n", second_float);
  printf("logs: third_float = %f\n", third_float);

  printf("-------------Double---------------\n");
  printf("A Double data type in C is used to store decimal numbers (numbers with floating point values) with double precision. It is used to define numeric values which hold numbers with decimal values in C. The double data type is basically a precision sort of data type that is capable of holding 64 bits of decimal numbers or floating points. Since double has more precision as compared to that float then it is much more obvious that it occupies twice the memory occupied by the floating-point type. It can easily accommodate about 16 to 17 digits after or before a decimal point.\n\nRange: 1.7E-308 to 1.7E+308\nSize: 8 bytes\nFormat Specifier: %%lf\n\n");
  double first_double = 123123123.00;
  double second_double = 12.293123;
  double third_double = 2312312312.123123;

  printf("double a = 123123123.00;\ndouble b = 12.293123;\ndouble c = 2312312312.123123;\n");

  printf("logs: first_double = %lf\n", first_double);

  printf("logs: second_double = %lf\n", second_double);

  printf("logs: third_double = %lf", third_double);

  return 0;
}
