#include <iostream>
#include <string>
#include <fstream>

const int N_Max = 2000;

bool Read(int& n, int& cnt, std::string words[N_Max])
{
    std::ifstream in("input.txt");
    if(!in.is_open())
    {
        std::cerr << "File not found";
        return false;
    }

    in >> n;
    cnt = 0;

    while(!in.eof())
    {
        in >> words[cnt];
        cnt++;
    }

    return true;
}

void Write(int cnt, std::string words[N_Max])
{
    for(int i=0; i<cnt; i++)
        std::cout << "<" << words[i] << ">" << std::endl;
}

void ClearWords(int cnt, std::string words[N_Max])
{
    for(int i=0; i<cnt; i++)
        for(int j=0; j<words[i].length(); j++)
        {
            if(!isalpha(words[i][j]))
            {
                words[i].erase(j, 1);
                j--;
            }
        }
}

bool isValidWord(const std::string& word, const char* forbidden_letters) {
    for (size_t i = 0; i < word.length(); i++) {
        if (strchr(forbidden_letters, tolower(word[i])))
            return false;
    }
    return true;
}

int main()
{
    int n;
    int cnt;
    std::string words[N_Max];

    if(!Read(n, cnt, words))
    return -1;

    ClearWords(cnt, words);

    // Чтение запрещенных букв
    char forbidden_letters[3];
    std::cin >> forbidden_letters[0] >> forbidden_letters[1] >> forbidden_letters[2];

    // Массив для хранения уникальных слов
    std::string unique_words[N_Max];
    int unique_count = 0;

    // Поиск всех допустимых слов
    for (int i = 0; i < cnt; i++) {
        if (isValidWord(words[i], forbidden_letters)) {
            bool is_duplicate = false;
            for (int j = 0; j < unique_count; j++) {
                if (words[i] == unique_words[j]) {
                    is_duplicate = true;
                    break;
                }
            }
            if (!is_duplicate) {
                unique_words[unique_count++] = words[i];
            }
        }
    }

    // Сортировка слов по длине
    for (int i = 0; i < unique_count - 1; i++) {
        for (int j = i + 1; j < unique_count; j++) {
            if (unique_words[i].length() < unique_words[j].length()) {
                std::swap(unique_words[i], unique_words[j]);
            }
        }
    }

    // Запись результата в файл
    std::ofstream out("output.txt");
    for (int i = 0; i < unique_count && i < N_Max; i++) {
        out << unique_words[i] << std::endl;
    }




    Write(cnt, words);

    return 0;



}