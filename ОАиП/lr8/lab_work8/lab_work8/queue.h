#include <iostream>
using namespace std;

struct Queue  {   // создаем очередь 
	int number;
	Queue* next;
};
void createQueue( Queue** begin, Queue ** end, int size, int first);
void displayQueue(Queue *begin);
void deleteQueue(Queue** begin);
void displayQueueAndSize(Queue* begin, int size);

