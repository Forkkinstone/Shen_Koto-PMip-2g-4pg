#include <iostream> // Модуль ввода - вывода
using namespace std; // Позволяет не писать std::
int main() // VAR 10
{
// 4.1
   cout << "Enter a natural number" << endl; // Выводит в консоль надпись перед вводом чисел
   int a, b, c; // Объявление переменных с типом int
   cin >> a >> b >> c; // Считывание значений

   if ((a>0) && (b>0) && (c>0)) // Проверка условия, что числа натуральные
   {
     if (((a+b)%c == 0) && (c%b == 0))
   {
    cout << (((a+b)/c) - (c/b)); // Вывод при успешном выполнении первого условия
   }
   else if (((a+b)%c == 0) && (c%b != 0)) // Конструкция else if (Иначе если) применяется при наличинии дополнительного условия
   {
    cout << (((a+b)/c) + (b*c)); // Вывод при успешном выполнении второго условия
   }
   else 
   {
    cout << a-b+c; // Вывод при не выполнении первых двух условий
   } 
    }
   else // Если числа при их вводе оказались не натуральными, выполняется else
   {
    cout << "The numbers must be natural!"; // Вывод надписи: Числа должны быть натуральными
   } 




// 4.2
// cout << "Enter the product code" << "\n"; // Выводится строка с просьбой ввести код
//   short codeProduct; // объявляется переменная с типом short, т.к. больших, чем четырехзначных значений нам не требуется
//   char count = 0; // объявляется переменная - счётчик (нужен для цикла while)

//   while (count == 0) // Цикл while. В данном случае предназначен для зацикливания кода с возможностью пользователю искать нужный товар
//   {
  
//   cin >> codeProduct; // Пользователь вводит код
  
//   if (codeProduct > 0) // При условии, что код - натуральное число - далее происходит поиск кода и соответствуюшего товара
//   {
//     switch (codeProduct) // Оператор switch получает код и при его наличии выводит название соответсвующего товара
//     {
//     case 3746: 
//       cout << "Product Code: " << codeProduct << ";      " << "Product name: " << "Chocolate" << "\n";
//       break;
    
//     case 8062: 
//       cout << "Product Code: " << codeProduct << ";      " << "Product name: " << "Milk" << "\n";
//       break;

//     case 7451: 
//       cout << "Product Code: " << codeProduct << ";      " << "Product name: " << "Cookie" << "\n";
//       break;

//     case 5320:
//       cout << "Product Code: " << codeProduct << ";      " << "Product name: " << "Donuts" << "\n";
//       break;

//     case 7293: 
//       cout << "Product Code: " << codeProduct << ";      " << "Product name: " << "Gingerbreads" << "\n";
//       break;

//     default:
//       cout << "Sorry, code is undefined. Please, try again..."<< "\n"; // Если известного кода не имеется, выводится текст с просьбой попробовать снова
//       break;
      
//     }
//   }
  
//   else
//   {
//     cout << "You have entered a non-existent product code! Please, try again..." << "\n"; // Если введенный код - отрицательное число - выводится текст с просьбой попробовать снова
//   }


//   }

  


// 4.3
// short num; 
//     printf("Enter a value: ");
//     cin >> num;

//     if (num == -1)
//     {
//         printf("Negative number");
//     }
//     else if (num == 1)
//     {
//         printf("Positive number");
//     }
//     else
//     {
//         printf("You have entered non-existent values!");
//     }   


}