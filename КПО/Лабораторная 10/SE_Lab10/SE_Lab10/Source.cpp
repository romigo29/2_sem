#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // ���������� ���������� ����� ����� � std::vector ������ ���������.
	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1); // ������� ���������� ���������, ������ 3
	cout << "�����: " << target1 << " ����������: " << num_items1 << endl; // ������-��������� ��� �������� ���������� ������� �.
	int num_items3 = count_if(v.begin(), v.end(), [](int i)
		{
			return i % 3 == 0; 
		});
	cout << "���������� ���������, ������� 3 : " << num_items3 << endl;
	cout << "\n ������ , ������ ����������" << endl; // ������-���������, ������ ���������� 
	for (auto i : v) [i]() {
		if (i % 3 == 0) cout << i << " "; 
		}
	();

		cout << "\n������ � �����������" << endl; // ����� �������� ������� �. �������� ����� ���������� ��� �������� � ������� �������
	for (auto i : v)[](auto i) {
		if (i % 3 == 0) cout << i << " ";
		}(i);

	cout << endl << "������ ��� ����������" << endl; // ����� �������� ������� �. // �������� ���������� ����� ������ ���������� ��� ���� ��������� ������ ��� ���������� �
	for (auto i : v) [i] {
		if (i % 3 == 0) cout << i << " "; 
		}();
}