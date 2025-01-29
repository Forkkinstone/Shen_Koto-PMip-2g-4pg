#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) 
{
    Node *newNode = (Node*)malloc(sizeof(Node)); //Выделение памяти для нового узла
    newNode -> data = data; //Запись данных в узел
    newNode -> next = NULL; //Изначально следующий указатель равен NULL
    return newNode; //Возврат указателя на новый узел 
}

bool hasDuplicateDigits(int number) 
{
    int digitCount[10] = {0}; //Массив для подсчёта числа каждой цифры
    
    while(number > 0) 
    {
        int digit = number % 10; //Получение последней цифры
        digitCount[digit]++; // Увеличение счётчика для этой цифры
        
        if(digitCount[digit] > 1) //Если цифра встречается более одного раза
        {
            return true; //Найдена дубликатная цифра
        }

        number /= 10; //Удаление последней цифры
    }
    
    return false; //Дубликатов нет
}

void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data); //Создание нового узла

    if(*head == NULL)
    {
        //Если список пуст
        *head = newNode; //Новый узел становится гловой списка
    }
    else
    {
        Node *temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp -> next; //Поиск конца списка
        }

        temp -> next = newNode; //Присоединение нового узла в конец
    }
}

void sortByFirstDigit(Node *head) //Простая сортировка вставками по первой цифре числа
{
    if(head == NULL || head -> next == NULL)
        return;

    Node *sorted = NULL; //Начало отсортированного списка

    while(head != NULL)
    {
        Node *current = head; //Текущий узел для вставки
        head = head -> next; //Переход к следующему узлу

        if(sorted == NULL || (current -> data / 10) < (sorted -> data / 10))
        {
            current -> next = sorted; //Вставка в начало отсортированного списка
            sorted = current; //обновление головы отсортированного списка
        }
        else
        {
            Node *temp = sorted;

            while(temp -> next != NULL && (temp -> next -> data / 10) <= (current -> data / 10))
            {
                temp = temp -> next; //Поиск места вставки
            }

            current -> next = temp -> next; //Вставка текущего узла
            temp -> next = current; 
            
        }
    }

    //Обновление головы изменённого списка
    head = sorted;
}

void processList(Node **head)
{
    if(*head == NULL) return; //Если список пуст

    bool hasDuplicates = false; //Флаг для проверки дубликатов

    Node *temp = *head;

    while(temp != NULL)
    {
        if(hasDuplicateDigits(temp -> data))
        {
            hasDuplicates = true; //Если есть дубликаты, устанавливаем флаг
            break; //Прерываем проверку
        }

        temp = temp -> next; //Переход к следующему узлу
    }

    if(hasDuplicates)
    {
        sortByFirstDigit(*head); //Сортируем по первой цифре
    }
    else
    {
        Node *current = *head;
        Node *newHead = NULL;

        while(current != NULL)
        {
            if(current -> data % 2 != 0) //Если число нечётное
            {
                insertEnd(&newHead, current -> data); //Дублируем его
                insertEnd(&newHead, current -> data);
            }

            current = current -> next; //Переход к следующему узлу
        }
        *head = newHead; //Обновление исходного списка
    }
}

void printList(Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head -> data); //Вывод данных узла
        head = head -> next; //Переход к следующему узлу
    }

    printf("\n");
}

void freeList(Node *head)
{
    while(head != NULL)
    {
        Node *temp = head; //Временный указатель на текущий узел
        head = head -> next; //Переход к следующему узлу
        free(temp); //Освобождение памяти
    }
}

int main()
{
    Node *head = NULL; //Инициализация головы списка

    //Ввод последовательности натуральных чисел
    int number;
    printf("Введите последовательность натуральных чисел (0 для завершения):\n");

    while(1)
    {
        scanf("%d", &number); //Чтение числа
        
        if(number == 0) break; //Завершение ввода

        insertEnd(&head, number); //Вставка числа в список
    }

    //Обработка списка
    processList(&head);

    //Вывод результата
    printf("Результат:\n");
    printList(head);

    //Освобождение памяти
    freeList(head);
    
    return 0;
}