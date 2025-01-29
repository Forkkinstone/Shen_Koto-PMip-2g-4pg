#include <iostream>

int main()
{
    long long number = 1237635123463254753LL;

    unsigned char* bytePointer = (unsigned char *)&number;

    std::cout << number << std::endl;

    for(size_t i=0; i < sizeof(long long); i++)
    {
        printf("%zu: %02x\n", i, bytePointer[i]);
    }

    return 0;

}