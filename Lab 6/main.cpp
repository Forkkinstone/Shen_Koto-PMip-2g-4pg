#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Функция для получения суммы цифр числа
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n; // Число элементов последовательности
    
    cin >> n;
    
    vector<int> sequence(n);
    
    // Ввод последовательности
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    
    bool contains_sum_12 = false;
    
    // Проверка наличия чисел с суммой цифр, равной 12
    for (int num : sequence) {
        if (digitSum(num) == 12) {
            contains_sum_12 = true;
            break;
        }
    }
    
    // Упорядочивание последовательности по неубыванию
    sort(sequence.begin(), sequence.end());
    
    if (!contains_sum_12) {
        cout << "Не найдено чисел с суммой цифр, равной 12" << endl;
        
        // Вывод упорядоченной последовательности
        for (auto num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        // Вывод исходной последовательности
        for (auto num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct NumberCompare {
    bool operator()(const int a, const int b) const {
        int prod_a = digitProduct(a);
        int prod_b = digitProduct(b);
        if (prod_a != prod_b) {
            return prod_a < prod_b;
        }
        int sum_a = digitSum(a);
        int sum_b = digitSum(b);
        if (sum_a != sum_b) {
            return sum_a < sum_b;
        }
        return a < b;
    }
};

int digitProduct(int number) {
    int product = 1;
    while (number > 0) {
        product *= number % 10;
        number /= 10;
    }
    return product;
}

int digitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    // Сортируем по неубыванию произведения цифр числа
    sort(numbers.begin(), numbers.end(), NumberCompare());
    
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}



