using namespace std;
#define HASHDEL (void*) -1  // ������ ��� ����������� �������� ���������� ��������
// ��������� �������
struct Object {
    void** data; // ��������� �� ������ ���������� �� ������
    int size; // ������ �������
    int N; // ���������� ��������� � �������
    int(*getKey)(void*); // ��������� �� ������� ��������� ����� �� ������
    Object(int, int(*)(void*));      // �����������
    bool insert(void*);      // ������� ������� �������� � ������
    int searchInd(int key);     // ������� ������ ������� �������� �� �����
    void* search(int key);     // ������� ������ �������� �� �����
    void* deleteByKey(int key);    // ������� �������� �������� �� �����
    bool deleteByValue(void*);      // ������� �������� �������� �� ��������
    void scan(void(*f)(void*));      // ������� ������������ ��������� � ����������� ������� � �������
};

static void* DEL = (void*)HASHDEL;  // ����������� ���������� ��� ����������� ���������� ��������
Object create(int size, int(*getkey)(void*));  // ������� �������� �������
#undef HASHDEL  // �������� ������� ��� �������� ���������� ��������
