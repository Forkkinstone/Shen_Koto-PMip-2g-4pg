#include <iostream>
using namespace std;
// #define X_MAX 1'000'000'000

int main()
{
    int x;
    int i;
    const int x_max = 1'000'000'000;

    cout << "Enter x and i: ";
    cin >> x;
    if (x > 0 && x < x_max)
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