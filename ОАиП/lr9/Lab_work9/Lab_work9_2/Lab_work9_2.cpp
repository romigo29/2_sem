#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

//Структура, содержащая информацию о студентах
struct Student {
	char last_name[NAME_SIZE];  //имя 
	char name[NAME_SIZE];  //фамилия
	char surname[NAME_SIZE];  //отчество
	int birth_year ; //др
	unsigned short course; //курс
	unsigned short group; //группа
	int grades[5];

	Student* next;  //следующий человек в списке
	Student* prev;  //предыдущий человек в списке
};
//Структура для хранения среднего балла по группам по каждому предмету
struct GroupStats {
	short groupNumber;  //Номер группы
	short totalGrades[5];  //Сумма баллов по каждому предмету
	short amount; // Количество студентов в группе
};

void clearBuf() {
	cin.ignore(cin.rdbuf()->in_avail());  //очистка буфера для корректного ввода
	cin.clear();
}
bool isEmpty(Student** phead) {
	return *phead == NULL;
}
//Добавление элемента в конец списка
void insertElement(Student* e, Student** phead, Student** plast) {
	Student* p = *plast;  //Временный указатель на конец списка
	if (*plast == NULL) {  //Если список пуст
		e->next = NULL;
		e->prev = NULL;
		*plast = e;  //Устанавливаем начало списка на добавленный элемент
		*phead = e;  //Устанавливаем конец списка на добавленный элемент
	}
	else {  //Если в списке есть элементы
		p->next = e;  //Указываем, что следующий элемент в существующем спике - это добавленный элемент
		e->next = NULL;  //Следюущий нулевой
		e->prev = p;  //Предыдущий уже находившийся в списке
		*plast = e;  //Конец список перенаправляем на добавленный элемент
	}
}
// Создание элемента и ввод его значений с клавиатуры
Student* setElement() {
	Student* temp = new Student(); 
	if (!temp) {
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

	cout << "Введите фамилию: ";
	clearBuf();
	cin.getline(temp->last_name, NAME_SIZE, '\n');

	cout << "Введите имя: ";
	clearBuf();
	cin.getline(temp->name, NAME_SIZE, '\n');

	cout << "Введите отчество: ";
	clearBuf();
	cin.getline(temp-> surname, NAME_SIZE, '\n');

	cout << "Введите год рождения: ";
	clearBuf();
	cin >> temp->birth_year;

	cout << "Введите курс: ";
	clearBuf();
	cin >> temp->course;

	cout << "Введите группу: ";
	clearBuf();
	cin >> temp->group;

	cout << "Введите оценки (5): ";
	for (int i = 0; i < 5; i++) {
		cin >> temp->grades[i];
	}

	cout << endl;

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//Вывод списка на экран
void outputList(Student** phead, Student** plast) {
	Student* t = *phead;  //Указатель на начало списка
	while (t) {  //Пока указатель не NULL, выводим список
		cout << t->last_name << ' ' << t->name << ' ' << t->surname << ' ' << t->birth_year << ' ' << t->course << ' ' << t->group << endl;
		cout << "Оценки: " << t->grades[0] << ' ' << t->grades[1] << ' ' << t->grades[2] << ' ' << t->grades[3] << ' ' << t->grades[4] << endl;
		t = t->next;
	}
	cout << "" << endl;
}
void sortList(Student** phead, Student** plast) {
	if ((*phead)->next == nullptr) {
		// Список содержит только один элемент, сортировка не требуется
		return;
	}

	Student* current = (*phead)->next; // Начинаем со второго элемента
	while (current != nullptr) {
		Student* temp = current;
		while (temp->prev != nullptr && (temp->course < temp->prev->course ||
			(temp->course == temp->prev->course && strcmp(temp->last_name, temp->prev->last_name) < 0))) {
			// Сравниваем курсы и фамилии и меняем местами студентов в списке
			Student* prevNode = temp->prev;
			Student* nextNode = temp->next;
			temp->prev = prevNode->prev;
			temp->next = prevNode;
			prevNode->prev = temp;
			prevNode->next = nextNode;
			if (nextNode != nullptr) {
				nextNode->prev = prevNode;
			}
			if (temp->prev != nullptr) {
				temp->prev->next = temp;
			}
			else {
				// Обновляем указатель на начало списка
				*phead = temp;
			}
		}
		current = current->next;
	}

	*plast = *phead;
}
//Нахождение среднего балла в каждой группе по каждому предмету 
void getAverage(Student** phead, Student** plast, unsigned int n) {

	GroupStats* groups = new GroupStats[n];
	for (int i = 0; i < n; i++) {
		groups[i].groupNumber = i + 1;
		groups[i].amount = 0;
		for (int j = 0; j < 5; j++) {
			groups[i].totalGrades[j] = 0;
		}
	}

	Student* temp = *phead;
	while (temp != nullptr) {
		int groupIndex = temp->group - 1;  // Индекс группы в массиве
		groups[groupIndex].amount++;
		for (int i = 0; i < 5; i++) {
			groups[groupIndex].totalGrades[i] += temp->grades[i];
		}
		temp = temp->next;
	}

	cout << "Средние баллы группы по каждому предмету: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Группа " << groups[i].groupNumber << ": ";
		for (int j = 0; j < 5; j++) {
			double average = groups[i].amount > 0 ? static_cast<double>(groups[i].totalGrades[j]) / groups[i].amount : 0.0;
			cout << fixed << setprecision(2) << average << " ";
		}
		cout << endl;
	}
	delete[] groups;
}
void getMinAndMax(Student** phead, Student** plast) {
	Student* temp = *phead;
	Student* youngest = temp;
	Student* oldest = temp;

	while (temp != nullptr) {
		if (temp->birth_year > youngest->birth_year) {
			youngest = temp;
		}
		if (temp->birth_year < oldest->birth_year) {
			oldest = temp;
		}
		temp = temp->next;
	}

	cout << "Самый младший студент: " << youngest->last_name << " " << youngest->name << " " << youngest->surname << " (" << youngest->birth_year << ")" << std::endl;
	cout << "Самый старший студент: " << oldest->last_name << " " << oldest->name << " " << oldest->surname << " (" << oldest->birth_year << ")" << std::endl;
}

void getBestStudent(Student** phead, Student** plast) {

	Student* bestStudent = *phead;
	Student* temp = *phead;
	while (temp != nullptr) {
		int tempSum = 0;
		for (int i = 0; i < 5; i++) {
			tempSum += temp->grades[i];
		}
		int bestSum = 0;
		for (int i = 0; i < 5; i++) {
			bestSum += bestStudent->grades[i];
		}
		if (tempSum > bestSum) {
			bestStudent = temp;
		}
		temp = temp->next;
	}

	cout << "Лучший студент:" << endl;
	cout << bestStudent->last_name << " " << bestStudent->name << " " << bestStudent->surname << endl;
	cout << "Год рождения: " << bestStudent->birth_year << endl;
	cout << "Курс: " << bestStudent->course << endl;
	cout << "Группа: " << bestStudent->group << endl;
	cout << "Оценки: ";
	for (int i = 0; i < 5; i++) {
		cout << bestStudent->grades[i] << " ";
	}
	cout << endl;
}
//главная функция
int main() {
	Student* head = NULL;  //создание указателя на начало списка
	Student* last = NULL;  //создание указателя на конец списка
	unsigned int n;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Сколько хотите ввести студентов? - ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		insertElement(setElement(), &head, &last);
	}

	if (isEmpty(&head)) {
		cout << "Список пуст. Невозможно производить дальнейшие действия." << endl;
	}
	else {
		cout << "Полученный список: " << endl;
		sortList(&head, &last);
		outputList(&head, &last);
		getAverage(&head, &last, n);
		getMinAndMax(&head, &last);
		getBestStudent(&head, &last);
	}
}

