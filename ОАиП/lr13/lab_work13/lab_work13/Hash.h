using namespace std;
#define HASHDEL (void*) -1  // Макрос для определения значения удаленного элемента
// Структура объекта
struct Object {
    void** data; // Указатель на массив указателей на данные
    int size; // Размер массива
    int N; // Количество элементов в массиве
    int(*getKey)(void*); // Указатель на функцию получения ключа из данных
    Object(int, int(*)(void*));      // Конструктор
    bool insert(void*);      // Функция вставки элемента в массив
    int searchInd(int key);     // Функция поиска индекса элемента по ключу
    void* search(int key);     // Функция поиска элемента по ключу
    void* deleteByKey(int key);    // Функция удаления элемента по ключу
    bool deleteByValue(void*);      // Функция удаления элемента по значению
    void scan(void(*f)(void*));      // Функция сканирования элементов с применением функции к каждому
};

static void* DEL = (void*)HASHDEL;  // Статическая переменная для обозначения удаленного элемента
Object create(int size, int(*getkey)(void*));  // Функция создания объекта
#undef HASHDEL  // Удаление макроса для значения удаленного элемента
