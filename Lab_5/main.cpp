#include <iostream>
int main ()
{
    int N;
    int i;
    int sum = 0;
    const int i_min;
    std::cin >> N >> i_min;
    for (i=i_min; i<=N; i++) 
    if (i%10!=1)
    {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
    

}




