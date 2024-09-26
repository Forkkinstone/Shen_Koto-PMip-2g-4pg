#include <iostream>

int main()
{
    std::cout << "char: 8 bit [-128, 127] or [0, 255]" << std::endl; // Вывод строки в консоль (cout) и переход на новую строку (endl)
    std::cout << "short: 16 bit [-32768, 32767]" << std::endl;
    std::cout << "int: 16 or 32 bit [-32768, 32767] or [-2147483648, 2147483647]" << std::endl;
    std::cout << "unsigned int: 16 or 32 bit [0, 65535] or [0, 4294967295]" << std::endl;
    std::cout << "long: 32 or 64 bit [-2147483648, 2147483647] or [-9223372036854775, 9223372036854774]" << std::endl;
    std::cout << "long long: 64 bit [−9223372036854775808, 9223372036854775807]" << std::endl;
    std::cout << "bool: True or False" << std::endl;
    std::cout << "float: 32 bit [+/- 3.4E-38, 3.4E+38]" << std::endl;
    std::cout << "double: 64 bit [+/- 1.7E-308, 1.7E+308]" << std::endl;
    std::cout << "65 + 97 = " << 65+97 << std::endl; // Вывод в консоль строки и ответа
    std::cout << "89 * 0.5 = " << 89*0.5 << std::endl;
    std::cout << "976 : 6 = " << 976/6 << std::endl;
    std::cout << "3*4 = " << 3*4 << std::endl; 
    return 0;
}