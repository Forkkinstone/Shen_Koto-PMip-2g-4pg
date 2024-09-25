#include <iostream> // Модуль ввода-вывода
#include <cmath> // Библиотека матопераций 
using namespace std; // Позволяет не писать std::

int main() // V10
{
    float x, n; // Объявляем переменные с типом float (тип с плавающей точкой)
    cout << "Enter the first number -- "; // Выводим в консоль "Введите первое число -- "
    cin >> x; // Пользователь вводит число 

    if (x>0 && x<100) 
    {
        cout << "Enter the second number -- "; // Выводим в консоль "Введите второе число --"
        cin >> n; // Пользователь вводит число
        
        if (n>0 && n<100) 
        {
            cout << "Calculating the result..." << endl; // Вычисление результата, строка переходит на новую
            cout << "Result = " << pow(x, (1/n)); // Результат 
        }
        else
        {
            cout << "You have entered a value that exceeds the allowed values."; // Если второе значение не удовлетворяет условию, выводится текст с ошибкой
        }
    }
    else 
    {
        cout << "You have entered a value that exceeds the allowed values."; // Если первое значение не удовлетворяет условию, выводится текст с ошибкой
    }

    return 0; 

}