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

    int a;          //Число 1
    int b;          //Число 2
    
    std::cout << "Enter a: ";
    std::cin >> a;
 
    short aLng0 = 0;
    short aLng1 = 0;
    short aLng2 = 0;
    short aLng3 = 0;
    short aLng4 = 0;
    short aLng5 = 0;
    short aLng6 = 0;
    short aLng7 = 0;
    short aLng8 = 0;
    short aLng9 = 0;
 
    while (a) {       //Считаем сколько цифр в числе
        if (a%10==0)
        {
            a = a/10;
            aLng0++;
            std::cout << "<0> - " << aLng0 << std::endl;
            
        }
        else if (a%10==1)
        {
            a = a/10;
            aLng1++;
            std::cout << "<1> - " << aLng1 << std::endl;
            
        }
        else if (a%10==2)
        {
            a = a/10;
            aLng2++;
            std::cout << "<2> - " << aLng2 << std::endl;
            
        }
        else if (a%10==3)
        {
            a = a/10;
            aLng3++;
            std::cout << "<3> - " << aLng3 << std::endl;
            
        }
        else if (a%10==4)
        {
            a = a/10;
            aLng4++;
            std::cout << "<4> - " << aLng4 << std::endl;
            
        }
        else if (a%10==5)
        {
            a = a/10;
            aLng5++;
            std::cout << "<5> - " << aLng5 << std::endl;
            
        }
        else if (a%10==6)
        {
            a = a/10;
            aLng6++;
            std::cout << "<6> - " << aLng6 << std::endl;
            
        }
        else if (a%10==7)
        {
            a = a/10;
            aLng7++;
            std::cout << "<7> - " << aLng7 << std::endl;
            
        }
        else if (a%10==8)
        {
            a = a/10;
            aLng8++;
            std::cout << "<8> - " << aLng8 << std::endl;
            
        }
        else
        {
            a = a/10;
            aLng9++;
            std::cout << "<9> - " << aLng9 << std::endl;
            
        }
    
    }
    

    
 
 
    

}




