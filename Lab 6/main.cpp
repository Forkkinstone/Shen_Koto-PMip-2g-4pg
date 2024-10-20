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
        std::cout << mas[i] << "  ";


    return 0;








    //2
    const int N_Max = 10000;
    int mas[N_Max];

    int n;
    std::cin >> n;

    // Ввод
    for(int i=0; i<n; i++)
        std::cin >> mas[i];


    // Сотировка
    for(int i=0; i<n-1;i++)
        for(int j=i+1; j<n; j++)
            {   // Сортировка по произведению цифр числа
                int value_I = mas[i];
                int multiply_I = 0;

                while(value_I > 0)
                    {
                        int num_I = value_I % 10;
                        value_I /= 10;
                        multiply_I *= value_I;
                    }
                
                int value_J = mas[j];
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
                else if(multiply_I == multiply_J)
                {   //Сортировка по сумме цифр числа
                    value_I = mas[i];
                    int sum_I = 0;

                    while(value_I > 0)
                    {
                        int num_I = value_I % 10;
                        value_I /= 10;
                        sum_I += value_I;
                    }

                    value_J = mas[j];
                    int sum_J = 0;

                    while(value_J > 0)
                    {
                        int num_J = value_J % 10;
                        value_J /= 10;
                        sum_J += value_J;
                    }

                    if(sum_I > sum_J)
                    {
                        int tmp = mas[i];
                        mas[i] = mas[j];
                        mas[j] = tmp;
                    }
                    else if((multiply_I == multiply_J) && (sum_I == sum_J) && (mas[i] > mas[j]))
                    {   //Сортировка по самому числу
                        int tmp = mas[i];
                        mas[i] = mas[j];
                        mas[j] = tmp;
                        
                    }



                }
                

            }

    


    //Вывод
    for(int i=0; i<n; i++)
        std::cout << mas[i] << " ";


    return 0;



    //3 






}






