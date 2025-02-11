#include <iostream>
using namespace std;

// Структура узла односвязного списка
struct Node {
    int data;     // Данные узла (натуральное число)
    Node* next;   // Указатель на следующий узел
};

// Проверяет, есть ли в числе две одинаковые цифры
bool hasDuplicateDigits(int num) {
    bool digits[10] = {false}; // Массив для отслеживания встреченных цифр
    while (num > 0) {
        int digit = num % 10;  // Получаем последнюю цифру
        if (digits[digit])     // Если цифра уже встречалась
            return true;
        digits[digit] = true;  // Отмечаем цифру
        num /= 10;             // Убираем последнюю цифру
    }
    return false;
}

// Возвращает первую цифру числа
int firstDigit(int n) {
    while (n >= 10) // Пока число больше 10
        n /= 10;     // Убираем последнюю цифру
    return n;
}

// Пузырьковая сортировка списка по первой цифре
void bubbleSort(Node* head) {
    if (!head) return; // Пустой список

    bool swapped;
    Node* ptr1;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lastSorted) {
            int fd1 = firstDigit(ptr1->data);       // Первая цифра текущего узла
            int fd2 = firstDigit(ptr1->next->data); // Первая цифра следующего узла

            if (fd1 > fd2) { // Если порядок нарушен
                swap(ptr1->data, ptr1->next->data); // Меняем данные местами
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lastSorted = ptr1; // Узел уже на своем месте
    } while (swapped);
}

// Удаляет четные числа и дублирует нечетные
void processList(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data % 2 == 0) { // Четное число
            if (prev == nullptr) {    // Удаление головы
                head = current->next;
                delete current;
                current = head;
            } else {                  // Удаление из середины/конца
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else { // Нечетное число
            Node* dup = new Node{current->data, current->next}; // Создаем дубликат
            current->next = dup;      // Вставляем дубликат
            prev = current;           // Переходим к дубликату
            current = dup->next;      // Следующий элемент после дубликата
        }
    }
}

// Выводит список на экран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Освобождает память списка
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Node* head = nullptr; // Голова списка
    Node* tail = nullptr; // Хвост списка (для быстрого добавления)
    int num;

    // Ввод чисел
    cout << "Вводите числа (0 или отрицательное для завершения):\n";
    while (cin >> num && num > 0) {
        Node* newNode = new Node{num, nullptr};
        if (!head) head = tail = newNode; // Первый элемент
        else {
            tail->next = newNode; // Добавляем в конец
            tail = newNode;
        }
    }

    // Проверка наличия чисел с дубликатами цифр
    bool hasDuplicates = false;
    Node* current = head;
    while (current && !hasDuplicates) {
        hasDuplicates = hasDuplicateDigits(current->data);
        current = current->next;
    }

    // Обработка списка
    if (hasDuplicates) {
        bubbleSort(head); // Сортировка по первой цифре
        cout << "Сортировка по первой цифре:\n";
    } else {
        processList(head); // Удаление четных и дублирование нечетных
        cout << "Обработанный список:\n";
    }

    printList(head); // Вывод результата
    deleteList(head); // Очистка памяти

    return 0;
}
