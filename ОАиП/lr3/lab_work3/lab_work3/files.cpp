#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; // буфер для хранения считываемого из файла текста
    ofstream fout1("FILE1.txt"), fout2("FILE2.txt"); // создание объектов fout класса ofstream для записи 
    fout1 << "park\n"; // запись строки в файл
    fout1 << "how much wood would a woodchuck chuck \n";
    fout1 << "red wood maple\n";
    fout1 << "woodland \n";
    fout1 << "forest red";
    fout1.close();
    ifstream fin1("FILE1.txt"), fin2("FILE2.txt"); // создание объектов fin класса ifstream для чтения 
    if (!fin1.is_open() || !fin2.is_open()) {
        cout << "Файл не может быть открыт!\n";
        return 1;
    }
    while (fin1.getline(buff, sizeof(buff))) {
        int counter_words = 1; // по умолчанию считается, что в строке 1 слово

        for (int i = 0; buff[i] != '\0'; i++) {
            if (buff[i] == ' ' && buff[i + 1] != '\0') { //если после пробела не \0
                counter_words++; // то увеличить счетчик
            }
        }
        if (counter_words > 2) { //если число слов > 2
            fout2 << buff << endl; //добавить его в файл 2
            
        }
    }
    fin1.close(); //закрытие файлов
    fout2.close();

    int counter_vowels = 0, max_vowels = 0, i = 0;
    char vword[50];
    fin2.getline(buff, sizeof(buff)); //п
    while (buff[i] != '\0' && buff[i] != -52) {
        int index = i; //переопредляем позицию слова
        int length = 0; // переопределяем длину слова
        counter_vowels = 0; //обнуляем счетик гласных каждую итерацию
        while (buff[i] != ' ') { //пока слово не закончилось
            length++; //увеличиваем его длину
            if (buff[i] == 'e' || buff[i] == 'u' || buff[i] == 'o' || buff[i] == 'i' || buff[i] == 'a') { //если симвод - гласная
                counter_vowels++; //увеличить счетчик
            }
            i++;
        }
        if (counter_vowels > max_vowels) { 
            max_vowels = counter_vowels;  //если счетчик макс. гласных переопределен
            for (int j = 0; j < length; j++) {
                vword[j] = buff[index++]; //перезаписываем искомое слово
            }
            vword[length] = '\0'; //устанавливаем нуль-символ в конец строки
        }
        i++;
    }
    fin2.close();
    cout << "Данные записаны в FILE2 " << endl; //вывод соответствующего сообщения
    cout << "Слова с максимальным числом гласных: " << vword << endl; //вывод слова с максимальным количеством гласных во втором файле

    return 0;
}
