#include <iostream>

int main ()
{
    const int N_Max = 10000;
    int mas[N_Max];

    int n;
    std::cin >> n;

    // Ввод
    for(int i=0; i<n; i++)
        std::cin >> mas[i];

    //Обработка
    //Проверить, есть ли число, сумма цифр которого равна 12
    bool isSum12 = false;

    for(int i=0; i<n; i++)
    {
        int value = mas[i];
        int sum = 0;

        while(value > 0)
            {
                value = value / 10;
                sum += value;
            } 
        
        if(sum == 12)
        {
            isSum12 = true;
            break;
        }

    }

    //Сортировка
    if(isSum12 == false)
    {
        for(int i=0; i<n-1;i++)
            for(int j=i+1; j<n; j++)
                if (mas[i]>mas[j])
                {
                    int tmp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = tmp;
                }
    }


    //Вывод
    for(int i=0; i<n; i++)
        std::cout << mas[i] << " ";
        
    return 0;

}






