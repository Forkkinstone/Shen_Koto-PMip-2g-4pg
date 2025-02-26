#include <iostream>
using namespace std;

// Структура узла двусвязного списка
struct Node {
    int data; // Данные узла
    Node* prev; // Указатель на предыдущий узел
    Node* next; // Указатель на следующий узел 
    Node(int val) : data(val), prev(nullptr), next(nullptr) {} // Конструктор инициализирует данные и указатели
};

class DoublyLinkedList {
private:
    Node* dummy; // Сторожевой узел для упрощения операций
    // Проверка, является ли чило палиндромом
    bool isPalindrome(int num) {
        if (num < 10) return false; // Исключаем однозначные числа 
        int original = num;
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10; // Реверс числа
            num /= 10;
        }
        return original == reversed;
    }
    // Получение первой цифры числа 
    int firstDigit(int num) {
        while (num >= 10) {
            num /= 10; // Делим до получения первой цифры 
        }
        return num;
    }

public:
    // Конструктор создаёт кольцевой сторожевой узел 
    DoublyLinkedList() {
        dummy = new Node(-1);
        dummy->prev = dummy; // Замыкаем указатели 
        dummy->next = dummy;
    }

    //Деструктор для освобождения памяти 
    ~DoublyLinkedList() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            delete current; // Удаляем все узлы
            current = nextNode;
        }
        delete dummy; // Удаляем сторожевой узел 
    }

    // Добавление элемента в конец списка 
    void append(int val) {
        Node* newNode = new Node(val);
        Node* tail = dummy->prev; //Хвост списка
        tail->next = newNode; //Вставка между хвостом и dummy
        newNode->prev = tail;
        newNode->next = dummy;
        dummy->prev = newNode; //Обновление хвоста 
    }

    // Проверка порядка элементов в списке 
    int checkOrder() {
        // Пустой или один элемент считается упорядоченным 
        if (dummy->next == dummy || dummy->next->next == dummy) return 1;

        bool isNonDecreasing = true; // Флаг неубывания
        bool isNonIncreasing = true; // Флаг невозрастания

        Node* current = dummy->next;
        Node* nextNode = current->next;

        // Проход по всем элементам 
        while (nextNode != dummy) {
            if (current->data > nextNode->data) isNonDecreasing = false;
            if (current->data < nextNode->data) isNonIncreasing = false;
            current = nextNode;
            nextNode = nextNode->next;
        }

        if (isNonDecreasing) return 1;
        if (isNonIncreasing) return -1;
        return 0; // Неупорядоченный 
    }

    // Удаление чисел-палиндромов 
    void removePalindromes() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            if (isPalindrome(current->data)) {
                // Перелиновка соседних узлов 
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current; // Удаление текущего узла
            }
            current = nextNode;
        }
    }

    // Дублирование чисел, оканчивающихся на 0
    void duplicateNumbersEndingWithZero() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            if (current->data % 10 == 0) {
                Node* newNode = new Node(current->data);
                // Вставка нового узла после текущего 
                newNode->prev = current;
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
                nextNode = newNode->next; // Пропуск нового узла
            }
            current = nextNode;
        }
    }

    // Сортировка пузырьком по первой цифре 
    void bubbleSort() {
        if (dummy->next == dummy) return; // Пустой список 

        bool swapped;
        do {
            swapped = false;
            Node* current = dummy->next;
            while (current->next != dummy) {
                Node* nextNode = current->next;
                // Сравнение первых цифр
                if (firstDigit(current->data) > firstDigit(nextNode->data)) {
                    swap(current->data, nextNode->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    // Вывод списка
    void print() {
        Node* current = dummy->next;
        while (current != dummy) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int num;

    cout << "Enter natural numbers (end with 0 or non-number): ";
    while (cin >> num && num > 0) { // Ввод чисел до 0 или ошибки
        list.append(num);
    }

    int order = list.checkOrder();
    if (order != 0) {
        // Если упорядочен, удаляем палиндромы и дублируем числа с 0
        list.removePalindromes();
        list.duplicateNumbersEndingWithZero();
    } else {
        // Иначе сортируем по первой цифре
        list.bubbleSort();
    }

    cout << "Result: ";
    list.print();

    return 0;
}

