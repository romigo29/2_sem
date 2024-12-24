#include <iostream> 
#include <fstream>  
#include <string>
#include <cctype>  
using namespace std;
void inFile(const char str[], const char str2[]); // ������� ������ ������ � ����
void fromFile(); // ������� ������ �� �����

int main() {
    setlocale(LC_ALL, "Russian");
    char str1[100], str2[100];
    cout << "������� ������ 1 \n"; // ���� ������ 1 � ����������
    cin.getline(str1, sizeof(str1));
    cout << "������� ������ 2 \n"; // ���� ������ 2 � ����������
    cin.getline(str2, sizeof(str2));
    inFile(str1, str2);
    fromFile();
    cout << endl;
    return 0;
}
// ��� ������ ������ � ����
void inFile(const char str1[], const char str2[]) {
    ofstream ofile("test.txt"); // �������� ������� ������ ofstream ��� ������ 
    if (ofile.fail())  // �������� �������� �����
    {
        cout << "������ �������� �����\n ";
        exit(1);
    }
    ofile << str1 << endl; // ������ ������ � ����
    ofile << str2;
    ofile.close();
    cout << "������ �������� � ����\n";
}
// ��� ������ ��������� �� �����
void fromFile() {
    ifstream ifile("test.txt"); // �������� ������� ������ ifstream ��� ������ 

    if (ifile.is_open()) {
        char line1[100], line2[100];

        ifile.getline(line1, sizeof(line1)); //��������� ������ ������
        int i = 0, imin = 100;
        char shortest_word[100]; //�������� ����� � ������
        while (line1[i] != '\0') { // ���� �� ����� ������
            int index = i; //������������� ����� ������� ������ �����
            int length = 0;  //����� �����
            while (line1[i] != ' ' && line1[i] != '\0') { //���� ����� �� ����������
                length++; //����������� ��� �����
                i++;
            }
            if (length < imin) { //���� ����������� ������ �������������
                imin = length;
                for (int j = 0; j < imin; j++) { //������ �������� ����� �� �������
                    shortest_word[j] = line1[index++];
                }
                shortest_word[length] = '\0'; // ������������� ����-������ � ����� �����
            }
            i++;
        }

        ifile.getline(line2, sizeof(line2));  //��������� ������ ������
        char longest_word[100];  // ������� ����� � ������
        int imax = 0;  //������������ ������ ����� � ������
        i = 0; // �������������� ��������
        while (line2[i] != '\0' && line2[i] != -52) { // ���� �� ����� ������
            int index = i; //������������� ����� ������� ������ �����
            int length = 0;  //����� �����
            while (line2[i] != ' ' && line2[i] != '\0') { //���� ����� �� ����������
                length++; //����������� ��� �����
                i++;
            }
            if (length > imax) { // ���� ����. ������ �������������
                imax = length;
                for (int j = 0; j < imax; j++) { //������ ������� ����� �� �������
                    longest_word[j] = line2[index++];
                }
                longest_word[length] = '\0'; // ������������� ����-������ � ����� �����
            }
            i++;
        }

        cout << "����� �������� ����� �� ������ ������: " << shortest_word << endl;
        cout << "����� ������� ����� �� ������ ������: " << longest_word;
    }
    else {
        cout << "������ �������� �����\n";
    }
}
