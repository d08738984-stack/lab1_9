#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
using namespace std;

// Завдання 1B - власна реалізація insert (вар.14)
char* my_insert(const char* str, size_t pos, const char* s, size_t n);

// Завдання 2B - перевірка валідності рядка
bool isValid(const string& str);

// Завдання 2A - підрахунок слів, які починаються і закінчуються однією буквою
int countSameFirstLast(const string& str);

// Завдання 2D - обробка файлу
void processFile(const string& filename);

#endif
