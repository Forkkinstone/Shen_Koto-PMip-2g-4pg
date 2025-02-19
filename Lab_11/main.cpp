#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* dummy;

    bool isPalindrome(int num) {
        if (num < 10) return false; // Однозначные числа не считаем палиндромами для исключения удаления
        int original = num;
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return original == reversed;
    }

    int firstDigit(int num) {
        while (num >= 10) {
            num /= 10;
        }
        return num;
    }

public:
    DoublyLinkedList() {
        dummy = new Node(-1);
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    ~DoublyLinkedList() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete dummy;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        Node* tail = dummy->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = dummy;
        dummy->prev = newNode;
    }

    int checkOrder() {
        if (dummy->next == dummy || dummy->next->next == dummy) return 1;

        bool isNonDecreasing = true;
        bool isNonIncreasing = true;

        Node* current = dummy->next;
        Node* nextNode = current->next;

        while (nextNode != dummy) {
            if (current->data > nextNode->data) isNonDecreasing = false;
            if (current->data < nextNode->data) isNonIncreasing = false;
            current = nextNode;
            nextNode = nextNode->next;
        }

        if (isNonDecreasing) return 1;
        if (isNonIncreasing) return -1;
        return 0;
    }

    void removePalindromes() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            if (isPalindrome(current->data)) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            current = nextNode;
        }
    }

    void duplicateNumbersEndingWithZero() {
        Node* current = dummy->next;
        while (current != dummy) {
            Node* nextNode = current->next;
            if (current->data % 10 == 0) {
                Node* newNode = new Node(current->data);
                newNode->prev = current;
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
                nextNode = newNode->next; // Пропустить новый элемент
            }
            current = nextNode;
        }
    }

    void bubbleSort() {
        if (dummy->next == dummy) return;

        bool swapped;
        do {
            swapped = false;
            Node* current = dummy->next;
            while (current->next != dummy) {
                Node* nextNode = current->next;
                if (firstDigit(current->data) > firstDigit(nextNode->data)) {
                    swap(current->data, nextNode->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

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
    while (cin >> num && num > 0) {
        list.append(num);
    }

    int order = list.checkOrder();
    if (order != 0) {
        list.removePalindromes();
        list.duplicateNumbersEndingWithZero();
    } else {
        list.bubbleSort();
    }

    cout << "Result: ";
    list.print();

    return 0;
}

