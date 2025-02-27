#include <iostream>   
#include <cstring>    
#include <cctype>     

using namespace std;  

// Рекурсивная функция для подсчета гласных букв в строке
int countVowels(const char* str, int index = 0) {
    // Проверяем, достигли ли конца строки
    if (str[index] == '\0') {
        return 0;  
    }

    // Преобразуем текущий символ к нижнему регистру
    char currentChar = tolower(str[index]);

    // Проверяем, является ли символ гласной
    bool isVowel = (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' ||
                    currentChar == 'o' || currentChar == 'u');

    // Рекурсивно вызываем функцию для следующего символа и суммируем результат
    return isVowel + countVowels(str, index + 1);
}

int main() {
    char str[101];  

    cout << "Enter a string (up to 100 characters): ";  
    cin.getline(str, 101);  

    int vowelCount = countVowels(str);  // Вызываем рекурсивную функцию для подсчета гласных

    cout << "Number of vowel letters: " << vowelCount << endl;  

    return 0;  
}




