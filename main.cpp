#include <iostream>
#include <string>
#include <cstring>
#include "string_utils.h"

using namespace std;

void task1();
void task2();

int main()
{
    int choice;

    do
    {
        cout << "\n===================================\n";
        cout << "1 - Завдання 1 (метод insert, вар.14)\n";
        cout << "2 - Завдання 2 (String37)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Вихід.\n";
            break;
        default:
            cout << "Помилка!\n";
        }

    } while (choice != 0);

    return 0;
}

void task1()
{
    string str;
    cout << "Введіть рядок: ";
    getline(cin, str);

    string insertStr;
    cout << "Введіть рядок для вставки: ";
    getline(cin, insertStr);

    size_t pos;
    cout << "Введіть позицію вставки: ";
    cin >> pos;

    size_t n;
    cout << "Введіть кількість символів для вставки: ";
    cin >> n;
    cin.ignore();

    // СТАНДАРТНИЙ МЕТОД string::insert (вар.14)
    string result1 = str;
    result1.insert(pos, insertStr.c_str(), n);
    cout << "\nРезультат (метод string::insert): " << result1 << endl;

    // ВЛАСНА ФУНКЦІЯ
    char* cstr1 = new char[str.length() + 1];
    strcpy(cstr1, str.c_str());

    char* cstr2 = new char[insertStr.length() + 1];
    strcpy(cstr2, insertStr.c_str());

    char* result2 = my_insert(cstr1, pos, cstr2, n);
    cout << "Результат (власна функція): " << result2 << endl;

    delete[] cstr1;
    delete[] cstr2;
    delete[] result2;
}

void task2()
{
    string filename;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> filename;

    processFile(filename);
}
