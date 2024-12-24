#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; // ����� ��� �������� ������������ �� ����� ������
    ofstream fout1("FILE1.txt"), fout2("FILE2.txt"); // �������� �������� fout ������ ofstream ��� ������ 
    fout1 << "park\n"; // ������ ������ � ����
    fout1 << "how much wood would a woodchuck chuck \n";
    fout1 << "red wood maple\n";
    fout1 << "woodland \n";
    fout1 << "forest red";
    fout1.close();
    ifstream fin1("FILE1.txt"), fin2("FILE2.txt"); // �������� �������� fin ������ ifstream ��� ������ 
    if (!fin1.is_open() || !fin2.is_open()) {
        cout << "���� �� ����� ���� ������!\n";
        return 1;
    }
    while (fin1.getline(buff, sizeof(buff))) {
        int counter_words = 1; // �� ��������� ���������, ��� � ������ 1 �����

        for (int i = 0; buff[i] != '\0'; i++) {
            if (buff[i] == ' ' && buff[i + 1] != '\0') { //���� ����� ������� �� \0
                counter_words++; // �� ��������� �������
            }
        }
        if (counter_words > 2) { //���� ����� ���� > 2
            fout2 << buff << endl; //�������� ��� � ���� 2
            
        }
    }
    fin1.close(); //�������� ������
    fout2.close();

    int counter_vowels = 0, max_vowels = 0, i = 0;
    char vword[50];
    fin2.getline(buff, sizeof(buff)); //�
    while (buff[i] != '\0' && buff[i] != -52) {
        int index = i; //������������� ������� �����
        int length = 0; // �������������� ����� �����
        counter_vowels = 0; //�������� ������ ������� ������ ��������
        while (buff[i] != ' ') { //���� ����� �� �����������
            length++; //����������� ��� �����
            if (buff[i] == 'e' || buff[i] == 'u' || buff[i] == 'o' || buff[i] == 'i' || buff[i] == 'a') { //���� ������ - �������
                counter_vowels++; //��������� �������
            }
            i++;
        }
        if (counter_vowels > max_vowels) { 
            max_vowels = counter_vowels;  //���� ������� ����. ������� �������������
            for (int j = 0; j < length; j++) {
                vword[j] = buff[index++]; //�������������� ������� �����
            }
            vword[length] = '\0'; //������������� ����-������ � ����� ������
        }
        i++;
    }
    fin2.close();
    cout << "������ �������� � FILE2 " << endl; //����� ���������������� ���������
    cout << "����� � ������������ ������ �������: " << vword << endl; //����� ����� � ������������ ����������� ������� �� ������ �����

    return 0;
}
