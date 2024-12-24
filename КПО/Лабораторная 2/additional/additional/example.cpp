#include <iostream>
#include <Windows.h>
using namespace std;
// структура
struct SANATORIUM
{
    char name[40]; // название санатория
    char location[40]; // местоположение
    char profile[40]; //профиль
    unsigned int amount_package; //количество путевок
};
// прототипы функций
void sortStructures(SANATORIUM sanat[], int num);
void findSanat(SANATORIUM sanat[], char ask_sanat[]);
void outputSanatoriums(SANATORIUM sanat[], int num);
//определяем структуру для санаториев и информации и о них
SANATORIUM sanat[5] = {
    {"Пралеска", "Беларусь", "Профиль A", 13},
    {"Зеленый бор", "Беларусь", "Профиль Б", 7},
    {"Нарочь", "Беларусь", "Профиль A", 2},
    {"Криница", "Беларусь", "Профиль A", 9},
    {"Буг", "Беларусь", "Профиль Б", 6}
};
// главная функция
int main()
{
    SetConsoleOutputCP(1251); // для распознавания кириллицы при записи в массив
    SetConsoleCP(1251);
    char ask_sanat[40]; // переменная для запроса профиля
    //ввод данных в массив структуры
    

    sortStructures(sanat, 5); //сортируем элементы
    outputSanatoriums(sanat, 5);
    cout << "Какой санаторий вас интересует? " << endl;
    cin >> ask_sanat;
    findSanat(sanat, ask_sanat); //ищем нужный санаторий
    return 0;
}
// функция для сортировки санаториев по алфавиту
void sortStructures(SANATORIUM sanat[], int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) { 
            if (strcmp(sanat[j].name, sanat[j + 1].name) > 0) { // сравниваем строки названий санаториев
                swap(sanat[j].name, sanat[j + 1].name);
            }
        }
    }
}
//вывод санаториев в виде таблицы
void outputSanatoriums(SANATORIUM sanat[], int num) {
    // первая строка таблицы
    cout << "Лечебный профиль" << "\t \t";
    cout << "Название" << "\t \t";
    cout << "Местоположение" << endl;
    // вторая строка таблицы
    cout << "Санатории по профилю А" << "\t \t";
    for (int i = 0; i < num; i++) {
        if (strcmp(sanat[i].profile, "Профиль A") == 0) {
            cout << sanat[i].name << "\t \t \t";
            cout << sanat[i].location << endl << "\t \t \t \t";
        }
    }
    // третья строка таблицы
    cout << "\rСанатории по профилю Б" << "\t \t";
    for (int i = 0; i < num; i++) {
        if (strcmp(sanat[i].profile, "Профиль Б") == 0) {
            cout << sanat[i].name << "\t \t";
            cout << sanat[i].location << endl << "\t \t \t \t";
        }
    }
    cout << "\r"; //возвращение каретки в начало строки
}
// поиск путевок по названию санатория
void findSanat(SANATORIUM sanat[], char ask_sanat[]) {
    bool found = false; // флаг для отслеживания, был ли найден санаторий
    for (int i = 0; i < 5; i++) {
        if (strcmp(sanat[i].name, ask_sanat) == 0) {
            cout << "Количество доступных путевок: " << sanat[i].amount_package << endl;
            found = true;
            break; // если нашли санаторий, то выходим из цикла
        }
    }
    if (!found) { // если санаторий не был найден
        cout << "Санаторий не был найден" << endl;
    }
}