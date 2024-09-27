#include <iostream>

int main()
{
int Sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool Comparator(int a, int b) {
    if (a % 10 != b % 10) return a % 10 < b % 10;
    if (a % 10 == b % 10 && Sum(a) != Sum(b)) return Sum(a) < Sum(b);
    if (a % 10 == b % 10 && Sum(a) == Sum(b)) return a < b;
}

void Lab6_2() {

    cout << "Input array lenth:" << endl;

    int n; cin >> n;
    std::vector<int> posl(n);

    for (int i = 0; i < n; i++) {
        cin >> posl[i];
    }

    std::sort(posl.begin(), posl.end(), Comparator);

    for (int a : posl) {
        cout << a << " ";
    }
    cout << "" << endl;
}
}