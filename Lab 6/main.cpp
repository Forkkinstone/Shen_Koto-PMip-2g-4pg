#include <iostream>

int main ()
{
    //1
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
                int num = value % 10;
                value /= 10;
                sum += num;
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








    //2
    // Ввод
    for(int i=0; i<n; i++)
        std::cin >> mas[i];



    for(int i=0; i<n-1;i++)
        for(int j=i+1; j<n; j++)
            {
                int value_I = mas[i];
                int multiply_I = 0;

                while(value_I > 0)
                    {
                        int num_I = value_I % 10;
                        value_I /= 10;
                        multiply_I *= value_I;
                    }
                
                int value_J = mas[i];
                int multiply_J = 0;

                while(value_J > 0)
                    {
                        int num_J = value_J % 10;
                        value_J /= 10;
                        multiply_J *= value_J;
                    }

                if(multiply_I > multiply_J)
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






