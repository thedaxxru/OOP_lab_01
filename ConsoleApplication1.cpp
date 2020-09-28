// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, (WORD)((background << 4) | text));
}
void SetColor(ConsoleColor text)
{
    SetColor(text, Black);
}

void ColorDefault()
{
    SetColor(White, Black);
}

int getValue(string str) {
    cout << str << ": ";
    int a;
    cin >> a;
    return a;
};
bool contains(int* mass, int v, int size)
{
    for (int i = 0; i < size; i++) {
        if (mass[i] == v) {
            return true;
        }
    } 
    return false;
}
int main() {
    int size = 0;
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    size = getValue("Дай размер");
    int *mas1, *mas2, *mas3;
    mas1 = new int[size];
    mas2 = new int[size];
    mas3 = new int[size * 2];
    for (int i = 0; i < size; i++) {
        mas1[i] = 1 + rand() % 100;
        mas2[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < size; i++) {
        if (contains(mas2, mas1[i], size))
            SetColor(Green);
        else
            SetColor(Red);
        cout << mas1[i] << setw(10);// << mas2[i] << endl;

        if (contains(mas1, mas2[i], size))
            SetColor(Green);
        else
            SetColor(Red);
        cout << mas2[i] << endl;

        ColorDefault();
    }
    cout << endl << endl;
    cout << "НОВЫЙ МАССИВ"<< endl;
    for (int i = 0; i < size; i++) {
        mas3[i] = mas1[i];
    }
    for (int j = 0; j < size; j++) {
        mas3[j + size] = mas2[j];
    }
    
    for (int i = 0; i < size * 2; i++) {
        cout  << mas3[i] << "_";
    }
    cout << endl << endl;

    delete mas1;
    delete mas2;
}


