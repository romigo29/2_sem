#include <iostream>
#include <fstream>
using namespace std;
void toFile(int, ofstream&, int, int*);

void toFile(int digit, ofstream& ofile, int current, int* row) {

    if (current == digit) {  //Если текущая цифра совпала с изначальной, то закачиваем подбор цифр
        for (int i = 0; i < digit; i++) {
            ofile << row[i]; //Записываем их в файл
        }
        ofile << endl;
        return;
    }

    for (int i = 0; i <= digit; i++) {  //Разряд числа не должен превышать исходную цифру
        row[current] = i;  //Записываем в первый разряд новую цифру
        toFile(digit, ofile, current + 1, row); //После записи числа увеличиваем левый разряд числа на 1
    }

}

int main()
{

    setlocale(LC_ALL, "rus");
    int A;
    cout << "Введите цифру A: ";
    cin >> A;

    while (A < 0 || A > 9) {
        cout << "Введено не число, попробуйте еще раз: ";
        cin >> A;
    }
  
    ofstream ofile("row.txt"); //Создаем файл ofstream для записи
    if (ofile.fail()) {  //В случае ошибки открытия файла
        cout << "Файл не удалось открыть!" << endl;
        exit(1);
    }

    int* row = new int[A]; //Выделение динамической памяти для массива чисел
    toFile(A, ofile, 0, row);

    ofile.close();
    cout << "Числа записаны в файл!";
    delete[] row;
    return 0;
}

