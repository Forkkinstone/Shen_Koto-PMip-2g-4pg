#include <iostream>
#include <string>
#include <fstream>

bool Read(int& n, std::string words[5120])
{
    std::ifstream in("input.txt");
    if(!in.is_open())
    {
        std::cerr << "File not opened" << std::endl;
        return false;
    }

    n = 0;
    while(!in.eof())
    {
        in >> words[n];
        n++;
    }

    return true;
}

void Write(int& n, std::string words[5120])
{
    for(int i=0; i<n; i++)
        std::cout << "<" << words[i] << ">" << std::endl;
}

std::string toLowerCase(std::string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}

char toLower(char c)
{
    if('A' <= c && c <= 'Z')
        c += 32;
    return c;
}

bool isVowel(char c)
{
    c = toLower(c);
    std::string vowels = "aeiouy";
    if(vowels.find(toLower(c)) != std::string::npos)
        return true;
    return false;
     
}

bool isWordWithEqualVowels(int& n, std::string words[5120])
{
    for(int i=0; i<n; i++)
    {
        std::string vowels = "aeiouy";
        for(int j=0; j<vowels.length(); j++)
        {
            int cnt = 0;
            for(int k=0; k<words[i].length(); k++)
                if(toLower(words[i][k]) == vowels[j])
                    cnt++;
            if(cnt >= 2)
                return true;

        }
    }
    return false;
}

void RemoveConsonant(int n, std::string words[5120])
{
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<words[i].length(); j++)
                if(!isVowel(words[i][j]))
                {
                    words[i].erase(j, 1);
                    j--;
                }
        }
}

bool isNotLess3Vowels(const std::string& s)
{
    int cnt = 0;
    for(int i=0; i<s.length(); i++)
        if(isVowel(s[i]))
            cnt++;
    return cnt >= 3;
}

void DuplicateVowels(std::string& s)
{
    for(int i=0; i<s.length(); i++)
        if(isVowel(s[i]))
        {
            s.insert(i, 1, s[i]);
            i++;
        }
}

void Sort(int n, std::string words[5120])
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(toLowerCase(words[i]) < toLowerCase(words[j]))
                std::swap(words[i], words[j]);

}

int main()
{
    int n;
    std::string words[5120];

    Read(n, words);

    if(isWordWithEqualVowels(n, words))
        RemoveConsonant(n, words);
    else 
    {
        for(int i = 0; i<n; i++)
            if(isNotLess3Vowels(words[i]))
                DuplicateVowels(words[i]);

    }

    Sort(n, words);

    Write(n, words);
    

    return 0;




}