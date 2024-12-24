#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>
#define LIMIT 100 // ������������ ���������� ����� ��� ������� ��������
//��������� �������
using namespace std;
void inputInfo();
void outputInfo();
void searchInfo();
void deleteCountry();
void writeInfo();
void readInfo();
// ���������
struct Goverment
{
	char name[16];
	char capital[16];
	unsigned int population;
	unsigned int area;
	char president[16];
};

Goverment country[LIMIT]; //������ country �� �������� country
int current_size = 0; // ������� ������ �������

int main()
{
	SetConsoleOutputCP(1251); // ��� ������������� ��������� ��� ������ � ������
	SetConsoleCP(1251);
	int choice;
	do {
		cout << "\n������� ������� ������ ����������: \n";
		cout << "0. ����� �� ����������\n";
		cout << "1. ���� ��������� ��������� � ����������\n";
		cout << "2. ����� ��������� ��������� � ���������� ����\n";
		cout << "3. �������� �������� ����������������� ����������\n";
		cout << "4. ����� ����������\n";
		cout << "5. ������ ���������� � ����\n";
		cout << "6. ������ ������ �� �����\n";
		cin >> choice;
		switch (choice)
		{
		case 1: { //���� ��������� ��������� � ����������
			inputInfo();
			break;
		}
		case 2: { //����� ��������� ��������� � ���������� ����
			outputInfo();
			break;
		}
		case 3: { //�������� �������� ����������������� ����������
			deleteCountry();
			break;
		}
		case 4: { //����� ����������
			searchInfo();
			break;
		}
		case 5: { //������ ���������� � ����
			writeInfo();
			break;
		}
		case 6: { //������ ������ �� �����
			readInfo();
			break;
		}
		case 0: { //����� �� ���������
			exit(0); 
			break;
		}
		default: {
			cout << "������� ������������ ��������. " << endl;
			break;
		}
		}
	} while (choice != 0);
}

void inputInfo()
{
	if (current_size < LIMIT) { //���� ������ �� ������� �� ������� ���������, �� ������ �����. ����������
		cout << "������� ��������: " << endl;
		cin >> country[current_size].name;
		cout << "������� �������: " << endl;
		cin >> country[current_size].capital;
		cout << "������� ����������� ���������: " << endl;
		cin >> country[current_size].population;
		cout << "������� ������� ���������� (� ��^2): " << endl;
		cin >> country[current_size].area;
		cout << "������� ������� ���������� ������: " << endl;
		cin >> country[current_size].president;
		current_size++;
		cout << "������� ��������� ������. " << endl;
	}
	else { //����� ������� ��������� � ������������
		cout << "��������� �����������!" << endl;
	}
}

void outputInfo()
{
	for (int i = 0; i < current_size; i++) { //���������� ������� ���������� � �������
		cout << "\n������ �" << i + 1 << endl;
		cout << "��������: " << country[i].name << endl;
		cout << "�������: " << country[i].capital << endl;
		cout << "����������� ���������: " << country[i].population << endl;
		cout << "������� ������: " << country[i].area << endl;
		cout << "��������� ������: " << country[i].president << endl;
	}
}

void searchInfo() {
	char country_name[20]; //���������� ��� ������ ������
	cout << "�� ����� ������ �� ������ ����� ����������? " << endl;
	cin >> country_name;
	for (int i = 0; i < 1; i++) {
		if (!strcmp(country_name, country[i].name)) { //���� ��������� ������ �������, �� ������� ���������� � ���
			cout << "���������� � ��������� ������: " << country_name << endl;
			cout << "�������: " << country[i].capital << endl;
			cout << "����������� ���������: " << country[i].population << endl;
			cout << "������� ������: " << country[i].area << endl;
			cout << "��������� ������: " << country[i].president << endl;
		}
		else { //����� ������� ��������� �� ������
			cout << "������ ���� ������� �������" << endl;
		}
	}
}

void deleteCountry() {
	char country_name[20]; //���������� ��� ������ ������
	cout << "������� ������, ������� ������ ������� �� ���������: " << endl;
	cin >> country_name;
	for (int i = 0; i < current_size; i++) {
		if (!strcmp(country_name, country[i].name)) { //���� ��������� ������ �������, �� ������� �� �� ���������
			for (int j = i; j < current_size - 1; j++) {
				country[j] = country[j + 1];
			}
			current_size--;
			cout << "����������� ���������� �������. " << endl;
		}
		else {  //����� ������� ��������� �� ������
			cout << "������ �� ���� �������" << endl;
		}
	}
}

void writeInfo() {
	ofstream ofile("countries.txt"); // �������� ������� ������ ofstream ��� ������
	if (ofile.fail()) {  // � ������ ������ �������� �����
		cout << "���� �� ������� �������!" << endl;
		exit(1);
	}
	for (int i = 0; i < current_size; i++) { //���������� ���������� � ����
		ofile << country[i].name << " " << country[i].capital << " " << country[i].population << " " << country[i].area << " " << country[i].president << " " << endl;
	}
	ofile.close(); //�������� �����
	cout << "���������� � ������� ������� �������� � ����";
}

void readInfo() {
	ifstream ifile("countries.txt"); // �������� �������� ������ ifstream ��� ������
	if (ifile.fail()) { // � ������ ������ �������� �����
		cout << "���� �� ������� �������!" << endl;
		exit(1);
	}

	current_size++; //����������� ������� ������� ��� ������� ������ ������
	for (int i = 0; i < current_size; i++) { //������ ���������� � ������ �� �����
		ifile >> country[i].name >> country[i].capital >> country[i].population >> country[i].area >> country[i].president;
		
	}
	ifile.close(); //�������� �����
	cout << "���������� �� ����� ������� ��������� � �������� � ���������";

}
