#include <iostream>
using namespace std;

int main()
{
    int x;
    int i;

    cout << "Enter x and i (0 < x < 10^9): ";
    cin >> x;
    if (x > 0 && x < 1000000000)
    {
    cout << "Enter i: ";
    cin >> i;
        if (i > 0)
        {

        x |= (1 << i);

        cout << "Result: " << x << endl;
        }
        else
        {
           cout << "You entered incorrect values\n"; 
        }
    }
    else
    {
        cout << "You entered incorrect values\n";
    }
    return 0;

}