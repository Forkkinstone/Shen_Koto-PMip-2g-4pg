#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    int i, min, pos, sum, n;
    cin >> n;
    if (n>0)
    {
    vector <int> a(n);
    for (i = 1; i < n; i++)
    {
        if (a[i]%10==1)
        {
            pos = i;
            min = a[i];
            sum = min;
            break;
        }
        if (pos == -1)
        {
            cout << "Not found any number!\n";
            return 0;
        }
    }

    for (i=pos+1; i<n; i++)
    {
        if (a[i]%10==0)
        {
            sum += a[i];
            if (a[i]<min)
            {
                min=a[i];
                pos = i;
            }
        }


    }

    }




}