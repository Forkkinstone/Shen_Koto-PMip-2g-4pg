#include <iostream>

int main ()
{
    
    int N; 
    const int x_max = 1'000'000'000;
    std::cin >> N;

    while (N >= 0) {

            N = abs(N % 10); 
            N = N / 10
            
            std::cout << N << "\n";
    }
    return 0;


    
    
    
    
    
    
    
    
    
    // std::list <int> List = {2415, 84563, 925178, 9832, 98356, 4578, 8194, 914276, 734251, 893561, 845362, 916743823, 8935271, 12341, 39241764, 62372};
    // int sum = 0; // Изначально сумма равна нулю 

    // for (auto v: List) // Перебор значений из списка = v
    // {
    //     if (v % 10 != 1) // Условие 
    //     {
    //         std::cout << v << "\n";
    //         sum += v;
            

    //     }

    // }
    // std::cout << sum << "!\n"; // Вывод суммы

    // return 0;





}