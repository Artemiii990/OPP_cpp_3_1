#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String {
private:
    char* str;
    size_t len;

public:
    String() : len(80) {
        str = new char[len + 1];
        if (str == nullptr) {
            cout << "Помилка виділення пам'яті!" <<endl;
        }
        memset(str, ' ', len);
        str[len] = '\0';
    }

    // Конструктор довільного розміру
    String(size_t size) : len(size) {
        str = new char[len + 1];
        if (str == nullptr) {
            cout << "Помилка виділення пам'яті!" << endl;
        }
        memset(str, ' ', len);
        str[len] = '\0';
    }

    // Конструктор з ініціалізацією рядком від користувача
    String(const char* input) : len(strlen(input)) {
        str = new char[len + 1];
        if (str == nullptr) {
            cout << "Помилка виділення пам'яті!" << endl;
        }
        strcpy(str, input);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Введення рядка з клавіатури
    void input() {
        string temp;
        getline(cin, temp);
        delete[] str;
        len = temp.length();
        str = new char[len + 1];
        if (str == nullptr) {
            cout << "Помилка виділення пам'яті!" << endl;
        }
        strcpy(str, temp.c_str());
    }

    // Виведення рядка на екран
    void output() const {
       cout << str << endl;
    }
};


int main() {
    system("chcp 65001");


    String str1;
    cout << "Enter the string number 2, with max height 50: ";
    String str2(50);
    str2.input();
    cout << "Enter the string number 3: ";
    String str3;
    str3.input();
    String str4("Hello, world!");



    cout << "Result of string number 1:"<< endl;
    str1.output();
    cout << "Result of string number 2:"<< endl;
    str2.output();
    cout << "Result of string number 3:"<< endl;
    str3.output();
    cout << "Result of string number 4:"<<endl;
    str4.output();

}
