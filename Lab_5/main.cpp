#include <iostream>
int main ()
{
    // int N;
    // int i;
    // int sum = 0;
    // int i_min;
    // std::cin >> N >> i_min;

    // for (i=i_min; i<=N; i++) 
    
    //     if (i%10!=1)
    //     {
    //         sum += i;
    //     }

    // std::cout << "sum: " << sum << std::endl;

    // for (i=i_min; i<=N; i++) 

    //     if (i%10==1)
    //     {
    //         std::cout << "min_1: " << i << std::endl;
    //         std::cout << "num_1: " << i-i_min + 1 << std::endl;
    //         break;
    //     }
    
    // return 0;

    int N;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> N; 
    int mina = INT_MAX;

    while (N > 0)
    {
        int a = N%10;
        if (a<mina)
        {
            mina = a;
        }
        N /= 10;
    }
    std::cout << "The minimum figure is: " << mina << std::endl;

    return 0;

    

}




