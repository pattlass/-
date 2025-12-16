#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// функция1, установка цвета фона консоли
void setConsoleColor(const string& color) {
    if (color == "black") system("color 07");
    else if (color == "blue") system("color 17");
    else if (color == "green") system("color 27");
    else if (color == "red") system("color 47");
    else if (color == "yellow") system("color 67");
    else if (color == "white") system("color 77");
    else system("color 0F"); // по умолчанию
}

// функция2, загрузка и сохранение данных
void loadAndSave() {
    setlocale(LC_ALL, "Russian");

    const string filename = "settings.txt";

    string instrument;
    string color;

    ifstream fin(filename);

    // если файл существует
    if (fin.is_open()) {
        fin >> instrument >> color;
        fin.close();

        // установка цвета сразу после загрузки
        setConsoleColor(color);

        cout << "Сохранённые данные:\n";
        cout << "Любимый музыкальный инструмент: " << instrument << "\n";
        cout << "Цвет фона консоли: " << color << "\n\n";

        cout << "Хотите изменить данные? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый музыкальный инструмент (одно слово на англ): ";
            cin >> instrument;

            cout << "Введите цвет фона (black, blue, green, red, yellow, white): ";
            cin >> color;

            ofstream fout(filename);
            fout << instrument << " " << color;
            fout.close();

            cout << "Данные обновлены!\n";
        }
    }
    // если файл не найден
    else {
        cout << "Файл не найден. Введите данные впервые.\n";

        cout << "Введите любимый музыкальный инструмент (одно слово на англ): ";
        cin >> instrument;

        cout << "Введите цвет фона (black, blue, green, red, yellow, white): ";
        cin >> color;

        ofstream fout(filename);
        fout << instrument << " " << color;
        fout.close();

        cout << "Данные сохранены!\n";

        setConsoleColor(color);
    }
}

int main() {
    loadAndSave();
    return 0;
}
