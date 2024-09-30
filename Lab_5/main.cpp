#include <iostream>
int main ()
{
    int N;
    int i;
    int sum = 0;
    int i_min;
    std::cin >> N >> i_min;

    for (i=i_min; i<=N; i++) 
    
        if (i%10!=1)
        {
            sum += i;
        }

    std::cout << "sum: " << sum << std::endl;

    for (i=i_min; i<=N; i++) 

        if (i%10==1)
        {
            std::cout << "min_1: " << i << std::endl;
            std::cout << "num_1: " << i-i_min + 1 << std::endl;
            break;
        }
    
    return 0;
    

}




