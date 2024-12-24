#include <iostream>
using namespace std;

typedef unsigned short hours;
typedef unsigned short minutes;
typedef unsigned short seconds;
struct Timer {
	hours hour;
	minutes minute;
	seconds second;
};

Timer time1 = { 0, 10, 60 };
Timer time2 = { 1, 00, 30 };
Timer time3 = { 3, 10, 10 };
Timer time4 = { 3, 10, 10};

//перегрузка ==
bool operator == (Timer time3, Timer time4) {
	return (time3.hour == time4.hour && time3.minute == time4.minute && time3.second == time4.second);
}
//перегрузка +
int operator + (Timer timer1, Timer timer2) {
	int result = (timer1.hour + timer2.hour) * 3600 + (timer1.minute + timer2.minute) * 60 + (timer1.second + timer2.second);
	return result;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Общее время первых двух таймеров: " << time1 + time2 << " секунд/а" << endl;

	if (time3 == time4) {
		cout << "Время на таймере 3 равно времени на таймере 4" << endl;
	}
	else {
		cout << "Время на таймере 3 отличается от времени на таймере 4" << endl;
	}
	return 0;
}