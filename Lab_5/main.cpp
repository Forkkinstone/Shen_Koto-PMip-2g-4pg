#include <iostream>
int main ()
{
    //1
    int n;
    int sum = 0;
    int minC = INT_MAX;
    int index = 0;

    std::cout << "Enter a number, the number of number in the sequence: ";
    std::cin >> n;

    for(int i=0; i<n; ++i)
    {
        int num;
        std::cout << "Entering the sequence number: ";
        std::cin >> num;

        if(num % 10 == 1)
        {
            if (num < minC)
            {
                minC = num;
                index = i;
            }
            sum += num;
        }
    }

    std::cout << "The sum of numbers that do not end in one: " << sum << std::endl;
    std::cout << "The smallest number: " << minC << std::endl;
    std::cout << "Index: " << index << std::endl;

    return 0;


    //2
    int N;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> N; 
    int mina = INT_MAX; // Большое число

    while (N > 0)
    {
        int a = N%10; // Отщипляем от числа последнюю цифру и рассматриваем её
        if (a<mina) // Если эта цифра меньше значения то в if присваиваем значение "а" значению "mina" 
        {
            mina = a;
        }
        N /= 10; // Убираем последнюю цифру числа для работы цикла
    }
    std::cout << "The minimum figure is: " << mina << std::endl;

    return 0;

    

}




