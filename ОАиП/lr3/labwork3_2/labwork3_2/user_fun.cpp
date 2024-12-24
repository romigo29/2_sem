#include <iostream> 
#include <fstream>  
#include <string>
#include <cctype>  
using namespace std;
void inFile(const char str[], const char str2[]); // функция записи строки в файл
void fromFile(); // функция чтения из файла

int main() {
    setlocale(LC_ALL, "Russian");
    char str1[100], str2[100];
    cout << "Введите строку 1 \n"; // ввод строки 1 с клавиатуры
    cin.getline(str1, sizeof(str1));
    cout << "Введите строку 2 \n"; // ввод строки 2 с клавиатуры
    cin.getline(str2, sizeof(str2));
    inFile(str1, str2);
    fromFile();
    cout << endl;
    return 0;
}
// для записи строки в файл
void inFile(const char str1[], const char str2[]) {
    ofstream ofile("test.txt"); // создание объекта класса ofstream для записи 
    if (ofile.fail())  // проверка открытия файла
    {
        cout << "Ошибка открытия файла\n ";
        exit(1);
    }
    ofile << str1 << endl; // запись строки в файл
    ofile << str2;
    ofile.close();
    cout << "Строка записана в файл\n";
}
// для чтения различных из файла
void fromFile() {
    ifstream ifile("test.txt"); // создание объекта класса ifstream для чтения 

    if (ifile.is_open()) {
        char line1[100], line2[100];

        ifile.getline(line1, sizeof(line1)); //получение первой строки
        int i = 0, imin = 100;
        char shortest_word[100]; //короткое слово в строке
        while (line1[i] != '\0') { // пока не конец строки
            int index = i; //устанавливаем точку отсчета начало слова
            int length = 0;  //длина слова
            while (line1[i] != ' ' && line1[i] != '\0') { //пока слово не закончится
                length++; //увеличиваем его длину
                i++;
            }
            if (length < imin) { //если минимальный размер переопределен
                imin = length;
                for (int j = 0; j < imin; j++) { //меняем короткое слово по индексу
                    shortest_word[j] = line1[index++];
                }
                shortest_word[length] = '\0'; // устанавливаем нуль-символ в конец слова
            }
            i++;
        }

        ifile.getline(line2, sizeof(line2));  //получение второй строки
        char longest_word[100];  // длинное слово в строке
        int imax = 0;  //максимальный размер слова в строке
        i = 0; // переопределние счетчика
        while (line2[i] != '\0' && line2[i] != -52) { // пока не конец строки
            int index = i; //устанавливаем точку отсчета начало слова
            int length = 0;  //длина слова
            while (line2[i] != ' ' && line2[i] != '\0') { //пока слово не закончится
                length++; //увеличиваем его длину
                i++;
            }
            if (length > imax) { // если макс. размер переопределен
                imax = length;
                for (int j = 0; j < imax; j++) { //меняем длинное слово по индексу
                    longest_word[j] = line2[index++];
                }
                longest_word[length] = '\0'; // устанавливаем нуль-символ в конец слова
            }
            i++;
        }

        cout << "Самое короткое слово из первой строки: " << shortest_word << endl;
        cout << "Самое длинное слово из второй строки: " << longest_word;
    }
    else {
        cout << "Ошибка открытия файла\n";
    }
}
