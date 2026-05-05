#include "string_utils.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

// ============ ЗАВДАННЯ 1B ============
// Власна реалізація insert (pos, const char* s, size_t n)
char* my_insert(const char* str, size_t pos, const char* s, size_t n)
{
    size_t lenStr = strlen(str);
    size_t lenS = strlen(s);

    // Якщо n більше за довжину s, беремо всю s
    if (n > lenS)
        n = lenS;

    // Нова довжина
    size_t newLen = lenStr + n;

    // Виділяємо пам'ять
    char* result = new char[newLen + 1];

    // Копіюємо частину до pos
    size_t i = 0;
    for (; i < pos && i < lenStr; i++)
        result[i] = str[i];

    // Вставляємо n символів з s
    for (size_t j = 0; j < n; j++, i++)
        result[i] = s[j];

    // Копіюємо решту з str
    for (size_t k = pos; k < lenStr; k++, i++)
        result[i] = str[k];

    result[newLen] = '\0';
    return result;
}

// ============ ЗАВДАННЯ 2B ============
// Перевірка, чи рядок коректний (немає пробілів на початку/в кінці, не порожній)
bool isValid(const string& str)
{
    if (str.empty()) return false;
    if (str[0] == ' ') return false;
    if (str[str.length() - 1] == ' ') return false;
    return true;
}

// ============ ЗАВДАННЯ 2A ============
// Підрахунок слів, які починаються і закінчуються однією буквою
int countSameFirstLast(const string& str)
{
    int count = 0;
    bool inWord = false;
    string word;

    for (size_t i = 0; i <= str.length(); i++)
    {
        char c = (i < str.length()) ? str[i] : ' ';

        if (c == ' ')  // кінець слова
        {
            if (inWord && word.length() > 0)
            {
                char first = tolower(word[0]);
                char last = tolower(word[word.length() - 1]);

                if (first == last)
                    count++;
            }
            inWord = false;
            word = "";
        }
        else  // символ слова
        {
            inWord = true;
            word += c;
        }
    }

    return count;
}

// ============ ЗАВДАННЯ 2D ============
// Обробка файлу
void processFile(const string& filename)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "Помилка: не вдалося відкрити файл " << filename << endl;
        return;
    }

    string outfile = "result_" + filename;
    ofstream fout(outfile);

    string line;
    int lineNum = 1;

    fout << "Результати обробки файлу " << filename << ":\n";
    fout << "=========================================\n";

    while (getline(fin, line))
    {
        cout << "\nРядок " << lineNum << ": \"" << line << "\"" << endl;

        if (!isValid(line))
        {
            cout << "  → НЕКОРЕКТНИЙ рядок (порожній або має пробіли на початку/в кінці)" << endl;
            fout << "Рядок " << lineNum << ": НЕКОРЕКТНИЙ\n";
        }
        else
        {
            int count = countSameFirstLast(line);
            cout << "  → Кількість слів, що починаються і закінчуються однією буквою: " << count << endl;
            fout << "Рядок " << lineNum << ": " << count << " слів\n";
        }
        lineNum++;
    }

    fin.close();
    fout.close();

    cout << "\nРезультати збережено у файл: " << outfile << endl;
}
