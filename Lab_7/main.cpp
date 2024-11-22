#include <iostream>
#include <cmath> // Для использования abs()
#include "func.hpp"

int main()
{
    using namespace func;
    int matrix[100][100];
    int n, m, i = 0, j = 0;
    std::cin >> n >> m;

    read(matrix, i, j, n, m); // Ввод

    bool hasZeroSumColumnWithoutPrimes = false;

    // Проверяем наличие столбцов без простых чисел с суммой 0
    for (int col = 0; col < m && !hasZeroSumColumnWithoutPrimes; col++) {
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

    /// Упорядочиваем строки по неубыванию абсолютных величин
    if (hasZeroSumColumnWithoutPrimes) {
        // Сортировка всех строк
        for (int k = 0; k < n; k++) {
            // Пузырьковая сортировка для текущей строки
            for (int l = 0; l < m - 1; l++) {
                for (int p = 0; p < m - l - 1; p++) {
                    if (std::abs(matrix[k][p]) > std::abs(matrix[k][p + 1])) {
                        int temp = matrix[k][p];
                        matrix[k][p] = matrix[k][p + 1];
                        matrix[k][p + 1] = temp;
                    }
                }
            }
        }  
    }

    write(matrix, i, j, n, m);  // Вывод
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();  // Ждем нажатия клавиши Enter
    return 0;
}