#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int val) {
        if (!head) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool hasDuplicateDigits() {
        Node* current = head;
        while (current) {
            if (containsDuplicateDigits(current->data)) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void sortByFirstDigit() {
        if (!head) return;

        // Smoothing sort implementation by first digit
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current && current->next) {
                if (getFirstDigit(current->data) > getFirstDigit(current->next->data)) {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    void modifyList() {
        if (!head) return;

        Node* current = head;
        Node* newHead = nullptr; // New list for odd numbers

        while (current) {
            if (current->data % 2 != 0) { // Odd number
                appendToList(newHead, current->data);
                appendToList(newHead, current->data); // Duplicate
            }
            current = current->next;
        }
        head = newHead; // Update head to new modified list
    }

private:
    bool containsDuplicateDigits(int number) {
        std::unordered_set<int> digits;
        while (number > 0) {
            int digit = number % 10;
            if (digits.find(digit) != digits.end()) {
                return true; // Duplicate found
            }
            digits.insert(digit);
            number /= 10;
        }
        return false;
    }

    void appendToList(Node*& head, int val) {
        if (!head) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    int getFirstDigit(int number) {
        while (number >= 10) {
            number /= 10;
        }
        return number;
    }
};

int main() {
    LinkedList list;
    int number;

    std::cout << "Enter a sequence of natural numbers (enter -1 to stop):" << std::endl;
    while (std::cin >> number && number != -1) {
        if (number > 0) { // Ensure the input is a natural number
            list.append(number);
        } else {
            std::cout << "Please enter a natural number." << std::endl;
        }
    }

    if (list.hasDuplicateDigits()) {
        list.sortByFirstDigit();
        std::cout << "Sorted list by first digit:" << std::endl;
    } else {
        list.modifyList();
        std::cout << "Modified list (even numbers removed, odd numbers duplicated):" << std::endl;
    }

    list.display();

    return 0;
}
