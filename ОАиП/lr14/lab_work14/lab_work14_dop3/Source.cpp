#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>

using namespace std;

// ������� ��� �������� � ������������� ���-������� ����������������� ���� � �����������
unordered_map<string, string> createReservedWordsMap() {
    unordered_map<string, string> reservedWords;

    // ���������� ������� ������������������ ������� � �� ��������� (�����������)
    reservedWords["if"] = "������� ��������� ���� ����.";
    reservedWords["else"] = "��������� ���� ����, ���� ������� � ��������� if �����.";
    reservedWords["for"] = "��������� �� ���������.";
    reservedWords["while"] = "�������� ��������� ���� ����, ���� ������� �������.";
    reservedWords["do"] = "��������� ���� ���� ���� ���, � ����� ��������� ��� ����������, ���� ������� �������.";
    reservedWords["break"] = "��������� ���������� ���������� ����� ��� ��������� switch.";
    reservedWords["continue"] = "���������� ������� ������� �������� ����� � ��������� � ��������� ��������.";
    reservedWords["switch"] = "�������� ���� ���� ��� ���������� �� ��������� ���������.";
    reservedWords["case"] = "���������� ���� ���� � ��������� switch.";
    reservedWords["default"] = "���������� ���� ���� �� ��������� � ��������� switch, ���� �� ���� case �� ������.";
    reservedWords["return"] = "��������� ���������� ������� �, ��� �������������, ���������� ��������.";
    reservedWords["void"] = "���������, ��� ������� �� ���������� ��������.";
    reservedWords["int"] = "��������� ���������� �������������� ����.";
    reservedWords["float"] = "��������� ���������� ���� � ��������� �������.";
    reservedWords["double"] = "��������� ���������� ���� � ������� ���������.";
    reservedWords["char"] = "��������� ���������� ����������� ����.";
    reservedWords["bool"] = "��������� ���������� ����������� ����.";
    reservedWords["struct"] = "���������� ����� ��� ���������.";
    reservedWords["typedef"] = "������� ��������� ��� ������������� ���� ������.";
    reservedWords["sizeof"] = "���������� ������ ���������� ��� ���� ������.";

    return reservedWords; // ���������� ����������� ���-�������
}

// ������� ��� ������ ��������� �� �����
void displayHelp(const unordered_map<string, string>& reservedWords, const string& word) {
    auto it = reservedWords.find(word); // ���� ����� � ���-�������
    if (it != reservedWords.end()) {
        // ���� ����� �������, ������� ���������
        cout << "��������� ��� '" << word << "': " << it->second << endl;
    }
    else {
        // ���� ����� �� �������, �������� �� ����
        cout << "����� '" << word << "' �� ������� ����� ����������������� ����." << endl;
    }
}

// ������� ��� ���������� ������ ����� � ����������
void addWord(unordered_map<string, string>& reservedWords, const string& word, const string& help) {
    reservedWords[word] = help; // ��������� ����� ����� � ��������� � ���-�������
    cout << "����� '" << word << "' ��������� � ����������: " << help << endl; // �������� � ����������
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ������� � �������������� ���-������� ����������������� ����
    unordered_map<string, string> reservedWords = createReservedWordsMap();

    string input;
    while (true) {
        // ����������� ���� ����� � ������������
        cout << "������� ����������������� ����� (��� 'exit' ��� ������): ";
        cin >> input;
        if (input == "exit") break; // ���� ������� 'exit', ������� �� �����

        auto it = reservedWords.find(input); // ���� ��������� ����� � ���-�������
        if (it != reservedWords.end()) {
            // ���� ����� �������, ������� ���������
            displayHelp(reservedWords, input);
        }
        else {
            // ���� ����� �� �������, ���������� ������������ �������� ���
            cout << "����� �� �������. ������ �������� ���? (��/���): ";
            string response;
            cin >> response;
            if (response == "��") {
                // ���� ������������ �����������, ����������� ��������� ��� ������ �����
                cout << "������� ��������� ��� ����� '" << input << "': ";
                string help;
                cin.ignore();  // ���������� ���������� '\n' � ������ �����
                getline(cin, help); // ��������� ������ � ����������
                addWord(reservedWords, input, help); // ��������� ����� ����� � ��������� � ���-�������
            }
        }
    }

    return 0;
}
