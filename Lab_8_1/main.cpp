#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

const int N_Max = 2000;
const int Word_Max_Length = 100;

// Чтение данных из файла
bool Read(std::string uniqueWords[], int& wordCount)
{
    std::ifstream in("input.txt");

    if (!in.is_open())
    {
        std::cerr << "File not found";
        return false;
    }

    std::string word;
    while (in >> word)
    {
        // Удаляем недопустимые символы и переводим в нижний регистр
        std::string cleanedWord;
        for (char ch : word)
        {
            if (isalpha(ch))
            {
                cleanedWord += tolower(ch);
            }
        }

        // Проверка уникальности и добавление слова
        if (!cleanedWord.empty())
        {
            bool isUnique = true;
            for (int i = 0; i < wordCount; i++)
            {
                if (uniqueWords[i] == cleanedWord)
                {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique && wordCount < N_Max)
            {
                uniqueWords[wordCount++] = cleanedWord;
            }
        }
    }

    return true;
}

// Проверка, содержит ли слово запрещенные буквы
bool ContainsForbiddenLetters(const std::string& word, const char forbiddenLetters[])
{
    for (char ch : word)
    {
        if (ch == forbiddenLetters[0] || ch == forbiddenLetters[1] || ch == forbiddenLetters[2])
        {
            return true; // Содержит запрещенную букву
        }
    }
    return false; // Не содержит запрещенных букв
}

// Запись результата
void Write(int n, std::string longestWords[], int longestWordCount)
{
    std::ofstream out("output.txt");
    for (int i = 0; i < n && i < longestWordCount; i++)
    {
        out << "<" << longestWords[i] << "> " << longestWords[i].length() << std::endl;
    }
    out.close();
}

// Сортировка массива по длине слов
void SortByLength(std::string words[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (words[i].length() < words[j].length())
            {
                std::swap(words[i], words[j]); // Обмен слов
            }
        }
    }
}

int main()
{
    std::string uniqueWords[N_Max];
    int wordCount = 0;

    if (!Read(uniqueWords, wordCount))
        return -1;

    // Задаем запрещенные буквы
    const char forbiddenLetters[3] = { 'a', 'e', 'i' };

    // Фильтруем слова, не содержащие запрещенные буквы
    std::string validWords[N_Max];
    int validWordCount = 0;
    for (int i = 0; i < wordCount; i++)
    {
        if (!ContainsForbiddenLetters(uniqueWords[i], forbiddenLetters))
        {
            validWords[validWordCount++] = uniqueWords[i];
        }
    }

    // Сортируем validWords по длине
    SortByLength(validWords, validWordCount);

    // Записываем результаты (например, 10 самых длинных слов)
    Write(10, validWords, validWordCount);

    return 0;
}
