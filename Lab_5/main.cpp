#include <iostream>
int main ()
{
    int N;
    int i;
    int sum = 0;
    std::cin >> N;
    for (i=1; i<=N; i++) 
    if (i%10!=1)
    {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
    

}




