#include <iostream>
#include "func.hpp"

int main()
{
    using namespace func;
    int matrix[100][100];
    int n, m, i, j;
    std::cin >> n >> m;

    read(matrix, i, j, n, m); // Ввод

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

    /// Упорядочивание строк по неубыванию абсолютных величин
    if (hasZeroSumColumnWithoutPrimes) {
        for (int row = 0; row < n; row++) {
            // Прямо здесь реализуем сортировку строки по неубыванию абсолютных величин
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

   
    write(matrix, i, j, n, m); //Вывод
    system("pause");
    return 0;










}