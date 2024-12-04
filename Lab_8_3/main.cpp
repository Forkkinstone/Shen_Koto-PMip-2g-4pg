#include <iostream>
#include <string>
#include <fstream>

const int MAX_WORDS = 5120;

// Функция для проверки, является ли символ гласной
bool isVowel(char c) 
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

// Функция для обработки строки и поиска слов с одинаковыми гласными подряд
void ProcessText(const std::string& inputLine, std::string& outputLine) 
{
    std::string word;
    outputLine.clear();
    for (char c : inputLine) 
    {
        // Если символ - не буква, то обрабатываем слово и добавляем символ в выходную строку
        if (!isalpha(c)) 
        {
            if (!word.empty()) 
            {
                // Проверка на наличие двух одинаковых гласных подряд
                std::string modifiedWord = word;
                bool found = false;
                for (size_t i = 0; i < word.length() - 1; i++) 
                {
                    if (isVowel(word[i]) && tolower(word[i]) == tolower(word[i + 1])) 
                    {
                        found = true;
                        break;
                    }
                }
                // Если нашли, переводим слово в верхний регистр и добавляем найденные буквы
                if (found) 
                {
                    std::string vowelsFound;
                    for (size_t i = 0; i < word.length() - 1; i++) 
                    {
                        if (isVowel(word[i]) && tolower(word[i]) == tolower(word[i + 1])) 
                        {
                            vowelsFound += toupper(word[i]);
                        }
                    }

                    modifiedWord = modifiedWord + " (" + vowelsFound + ")";

                    for (char& ch : modifiedWord) 
                    {
                        ch = toupper(ch);
                    }
                }

                outputLine += modifiedWord; // Добавляем слово в выходную строку
                word.clear(); // Сбрасываем текущее слово
            }

            outputLine += c; // Добавляем символ (разделитель или знак препинания)

        } 
        
        else 
        {
            word += c; // Собираем слово
        }
    }

    // Обработка последнего слова в строке
    if (!word.empty()) 
    {
        std::string modifiedWord = word;
        bool found = false;
        for (size_t i = 0; i < word.length() - 1; i++) 
        {
            if (isVowel(word[i]) && tolower(word[i]) == tolower(word[i + 1])) 
            {
                found = true;
                break;
            }
        }

        if (found) 
        {
            std::string vowelsFound;
            for (size_t i = 0; i < word.length() - 1; i++) 
            {
                if (isVowel(word[i]) && tolower(word[i]) == tolower(word[i + 1])) 
                {
                    vowelsFound += toupper(word[i]);
                }
            }

            modifiedWord += " (" + vowelsFound + ")";
            for (char& ch : modifiedWord) 
            {
                ch = toupper(ch);
            }
        }

        outputLine += modifiedWord; // Добавляем последнее слово в выходную строку
    }

}




int main() 
{
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) 
    {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string inputLine;

    while (std::getline(inputFile, inputLine)) 
    {
        std::string outputLine;
        ProcessText(inputLine, outputLine);
        outputFile << outputLine << std::endl; // Записываем в output.txt
    }

    inputFile.close();

    outputFile.close();

    return 0;
    
}
