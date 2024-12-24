#include <iostream>
using namespace std;
int (*psum) (int, int);

int sum(int, int);
int sum(int a, int b) {
    return a + b;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    bool flag1 = false; // 00 
    bool flag2 = true; // 01
    char eng_second = 'o'; // 6F - ASCII
    char rus_second = 'о'; // ee - // Windows - 1251
    wchar_t eng_first = L'R'; // 52 00 - utf - 16
    wchar_t rus_first = L'Р'; //d0 ff - utf - 16
    short x_pos = 30; // 1e 00
    short x_neg = -30; // e2 ff
    /*
    30 = 0000 0000 0001 1110
    -30 = 1000 0000 0001 1110 пк = 1111 1111 1110 0001 ок = 1111 1111 1110 0010 дк
    */
    short largest_short = 0x7fff; //ff 7f
    short smallest_short = 0x8000; //00 80
    unsigned short largest_unsigned_short = 0xffff; // ff ff
    unsigned short smallest_unsigned_short = 0x0000; // 00 00 
    /*
    65535 = 1111 1111 1111 1111
    0 = 0000 0000 0000 0000
    */
    int y_pos = 31; // 1f 00 00 00
    int y_neg = -31; //e1 ff ff ff
    /*
    2147483647 = 0111 1111 1111 1111 1111 1111 1111 1111
    -2147483648 = 1111 1111 1111 1111 1111 1111 1111 1111 = 1000 0000 0000 0000 0000 0000 0000 0000 = 
    1000 0000 0000 0000 0000 0000 0000 0001
    */
    int largest_int = 0x7fffffff; // ff ff ff 7f
    int smallest_int = 0x80000000; //00 00 00 80
    unsigned int largest_unsigned_int = 0xffffffff; //ff ff ff ff
    unsigned int smallest_unsigned_int = 0; // 00 00 00 00
    long z_pos = 32; // 20 00 00 00
    long z_neg = -32; // e0 ff ff ff
    /*
    32 = 0000 0000 0000 0000 0000 0000 0010 0000
    -32 = 1000 0000 0000 0000 0000 0000 0010 0000 = 1111 1111 1111 1111 1111 1111 1101 1111
    1111 1111 1111 1111 1111 1111 1110 0000
    */
    long long_longest = 0x7fffffff; // ff ff ff 7f
    long long_shortest = 0x80000000; //00 00 00 80
    unsigned long unsigned_long_longest = 0xffffffff; //ff ff ff ff
    unsigned long unsigned_shortortest = 0x00000000; //00 00 00 00
    float float_pos = 22.0; // 00 00 b0 41
    float float_neg = -22.0; //00 00 b0 c1
    /*  
    22.0 = 10110.0 = 1.0110 * 10^4 (показатель 127 + 4 = 131)
    0.100 0001 1.011 0000 0000 0000 0000 0000 = 
    -22.0 (меняется знак)
    1.100 0001 1.011 0000 0000 0000 0000 0000
    */
    float inf_pos = float_pos / 0; // inf
    float inf_neg = float_neg / 0; // -inf
    float uncertainty = inf_pos + inf_neg; // -nan(ind)


    char* peng_second = &eng_second; // 0x0093fab3
    char* peng_second1 = peng_second + 3; //0x0093fab6

    wchar_t* peng_first = &eng_first; // 0x0093fa98
    wchar_t* peng_first1 = peng_first + 3; // 0x0093fa9e

    short* px_pos = &x_pos; //0x0093fa80
    short* px_pos1 = px_pos + 3; //0x0093fa86

    int* py_pos = &y_pos; // 0x0093fa38
    int* py_pos1 = py_pos + 3; // 0x0093fa44

    float* pfloat_pos = &float_pos; //0x0093f9a8
    float* pfloat_pos1 = pfloat_pos + 3; //0x0093f9b4

    double num = 2.3E-2;
    double* pnum = &num; //0x0093f8f0
    double* pnum1 = pnum + 3; //0x0093f908

    psum = sum; //0x0032117c
    psum(23, 4);
    //&psum = 0x00e3a188
    return 0;
}

