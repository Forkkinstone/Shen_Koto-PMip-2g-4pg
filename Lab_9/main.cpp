#include <iostream>
using namespace std;

void printBytes(int number) {
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&number);

    cout << "Adress: " << static_cast<void*>(ptr) << endl;
    cout << "Size int: " << sizeof(number) << " byte " << endl;

    for (size_t i = 0; i < sizeof(number); ++i) {
        cout << "Byte " << i << ": " << hex << static_cast<int>(ptr[i]) << endl;
    }
}

int main() {
    int number = 4236423465;
    printBytes(number);
    return 0;
}