// Задача 2: Быстрая сортировка с вводом данных от пользователя
#include <iostream>
#include <vector>
#include <limits> // Для очистки некорректного ввода
using namespace std;

// Функция разделения (схема Хоара)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

// Рекурсивная сортировка
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    
    // Проверка корректности ввода размера
    while (!(cin >> n) || n <= 0) {
        cout << "Mistake! Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements separated by a space: ";
    
    // Ввод элементов с проверкой
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {
            cout << "Mistake! Enter an integer for the element " << i+1 << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    
    return 0;
}