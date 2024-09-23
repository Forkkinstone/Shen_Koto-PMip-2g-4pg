#include <iostream>
using namespace std;
int main() 

{
    short num;
    cin >> num;
    
    if (num<=10000)
    {
        cout << num % 10 << "\n";
    }
    else
    {
        cout << "You entered an incorrect value" << "\n";
    }

    return 0;
}