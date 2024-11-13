#include <iostream>

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    int matrix[100][100];
    
    // Ввод матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    bool hasZeroSumColumnWithoutPrimes = false;
    
    // Проверка наличия столбцов без простых чисел с суммой 0
    for (int col = 0; col < n && !hasZeroSumColumnWithoutPrimes; col++) {
        int sum = 0;
        bool allNonPrimes = true;
        
        for (int row = 0; row < n; row++) {
            sum += matrix[row][col];
            
            if (isPrime(matrix[row][col])) {
                allNonPrimes = false;
            }
        }
        
        if (sum == 0 && allNonPrimes) {
            hasZeroSumColumnWithoutPrimes = true;
        }
    }
    
    // Упорядочивание строк по неубыванию абсолютных величин
    if (hasZeroSumColumnWithoutPrimes) {
        for (int row = 0; row < n; row++) {
            // Сортировка строки по неубыванию абсолютных величин
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (std::abs(matrix[row][j]) > std::abs(matrix[row][j + 1])) {
                        int temp = matrix[row][j];
                        matrix[row][j] = matrix[row][j + 1];
                        matrix[row][j + 1] = temp;
                    }
                }
            }
        }
    }
    
    // Вывод результата
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
