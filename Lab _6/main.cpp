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



    //4 
    const int N_Max = 20000;
    int mas[N_Max];
    int n;
    std::cin >> n;

    //Ввод
    for(int i=0; i<n; i++)
        std::cin >> mas[i];

    //Удаление
    for(int i=0; i<n; i++)
    {
        int value_I = mas[i];
        int multiply_I = 0;

        while(value_I > 0)
            {
                int num_I = value_I % 10;
                value_I /= 10;
                multiply_I *= value_I;
            }
        if (multiply_I == 70)
        {
            for(int j=i; j<n-1; j++)
                mas[j] = mas[j+1];
            i--;
            n--;
        }
    }

    //Дублирование
    for(int i=0; i<n; i++)
    {
        int value_I = mas[i];
        bool IsPime = false;

        for(int i=2; i*i <= mas[i]; i++)
        if (mas[i]%i==0) value_I = true;

   

        if (value_I == true)
        {
            for(int j=n; j>i; j--)
                mas[j] = mas[j-1];
            i++;
            n++;    
        }
    }

    //Вывод
    for(int i=0; i<n; i++)
        std::cout << mas[i] << " ";
    
    return 0;


    //3
    int matrix[100][100];
    int n, m;
    std::cin >> n >> m;

    // Ввод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Создание массива для подсчета
    int *count = new int[m];
    for (int j = 0; j < m; ++j) {
        count[j] = 0;
    }

    // Подсчет количества чисел, оканчивающихся на 3, для каждого столбца
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] % 10 == 3) {
                ++count[j];
            }
        }
    }

    // Поиск индекса минимального элемента
    int min_index = 0;
    int min_count = count[0];
    for (int i = 1; i < m; ++i) {
        if (count[i] < min_count) {
            min_index = i;
            min_count = count[i];
        }
    }

    // Замена всех элементов, за исключением элементов найденного столбца
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j != min_index) {
                matrix[i][j] = -17;
            }
        }
    }

    // Вывод результата
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] count; // Удаление памяти после использования

    return 0;



    








}






