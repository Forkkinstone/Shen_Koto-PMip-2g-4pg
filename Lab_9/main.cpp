#include <iostream>

int main() {
    long long number;  // Создаем переменную типа long long (обычно 8 байт)
    std::cout << "Введите число: ";
    std::cin >> number;     // Получаем число от пользователя

    // Преобразуем указатель на число в указатель на байт (unsigned char)
    unsigned char* byte_ptr = reinterpret_cast<unsigned char*>(&number);

    std::cout << "Байты числа " << number << " в памяти:\n";
    
    // Проходим по всем байтам числа (от младшего к старшему)
    for (int i = 0; i < sizeof(number); ++i) {
        // Выводим числовое значение байта (преобразуем char в int)
        std::cout << "Байт " << i << ": " << static_cast<int>(*(byte_ptr + i)) << std::endl;
    }
    
    return 0;
}
