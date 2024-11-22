#include <iostream>
#include "func.hpp"

namespace func
{
    // Функция ввода значений в матрицу
    void read(int matrix[100][100], int& i, int& j, int& n, int& m)
    {
        for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
            }
        }
    }

    // Вывод матрицы
    void write(int matrix[100][100], int& i, int& j, int& n, int& m)
    {
        for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
            }
    }

    //Проверка, является ли число простым
    bool isPrime(int num) 
    {
        if (num<=1)
            return false;
        for (int i = 2; i*i <= num; i++){
            if (num % i == 0)
                return false;

        }
        return true;
    }
    




}