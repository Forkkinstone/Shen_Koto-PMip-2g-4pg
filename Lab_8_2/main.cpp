#include <iostream>
#include <string>
#include <fstream>

//Дана строка, содержащая английский текст. Если в тексте есть слово, в котоpом есть две одинаковые гласные буквы, 
//то удалить из слов текста согласные, в противном случае пpодублиpовать в словах, содеpжащих не менее 3-х гласных, 
//гласные буквы. Полученные слова вывести в алфавитном поpядке.

const int MAX_WORDS = 5120;

bool Read(int& n, int& cnt, std::string words[MAX_WORDS]) 
{
    std::ifstream in("input.txt");

    if (!in.is_open()) 
    {
        std::cerr << "File not opened" << std::endl;
        return false;
    }

    n = 0;

    while (in >> words[n] && n < MAX_WORDS) 
    {
        n++;
    }

    return true;
}


void DebugWrite(std::string& word)
{
    std::string newWord;

    for (char c : word)
    {
        if(!std::ispunct(c))
        newWord += c;
    }

    word = newWord;
}


bool isVowel(char c) 
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}


bool hasDuplicateVowels(const std::string& word) 
{
    int vowelCount[26] = {0};
    for (char c : word) 
    {
        if (isVowel(c)) 
        {
            vowelCount[tolower(c) - 'a']++;
            if (vowelCount[tolower(c) - 'a'] >= 2) 
            {
                return true;
            }
        }
    }

    return false;

}


void RemoveConsonants(int n, std::string words[MAX_WORDS]) 
{
    for (int i = 0; i < n; i++) 
    {
        std::string newWord;
        for (char c : words[i]) 
        {
            if (isVowel(c) || c == ' ' || c == ',') 
            { 
                newWord += c;
            }
        }

    words[i] = newWord;

    }
}


void DuplicateVowels(std::string& word) 
{
    std::string newWord;

    for (char c : word) 
    {
        newWord += c;
        if (isVowel(c)) 
        {
            newWord += c; // Duplicate vowel
        }
    }

    word = newWord;

}


void Sort(int n, std::string words[MAX_WORDS]) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (words[i] > words[j]) 
            {
                std::swap(words[i], words[j]);
            }
        }
    }
}


bool isNotLessThan3Vowels(const std::string& word) 
{
    int count = 0;
    for (char c : word) 
    {
        if (isVowel(c)) 
        {
            count++;
        }
    }

return count >= 3;

}


void Write(int& n, std::string words[5120])
{
    for (int i = 0; i < n; i++) 
    {
        if (!words[i].empty()) 
        {
            DebugWrite(words[i]);
            std::cout << "<" << words[i] << ">" << std::endl;
        }
    }
}

int main() 
{

int n;
int cnt;
int countLetters[MAX_WORDS] = {0};
std::string words[MAX_WORDS];

if (!Read(n, cnt, words)) 
{
    return -1;
}

bool hasEqualVowels = false;

for (int i = 0; i < n; i++) 
{
    if (hasDuplicateVowels(words[i])) 
    {
        hasEqualVowels = true;
        break;
    }
}

if (hasEqualVowels) 
{
    RemoveConsonants(n, words);
} 

else 
{
    for (int i = 0; i < n; i++) 
    {
        if (isNotLessThan3Vowels(words[i])) 
        {
            DuplicateVowels(words[i]);
        }
    }
}


Sort(n, words);

Write(n, words);

return 0;

}
