#include "Varparm.h"
using namespace std;
using namespace Varparm;
int main()
{
    int i1 = ivarparm(0);
    int i2 = ivarparm(1, 2);
    int i3 = ivarparm(2, 4, 5);
    int i4 = ivarparm(6, 7, 5, 4, 3, 2, 1);

    int s1 = ivarparm(0);
    int s2 = svarparm(1, 2);
    int s3 = svarparm(2, 4, 5);
    int s4 = svarparm(6, 7, 5, 4, 3, 2, 11);

    double  f1 = fvarparm(FLT_MAX);
    double  f2 = fvarparm(1.1f, FLT_MAX);
    double  f3 = fvarparm(2.2f, 3.3f, FLT_MAX);
    double  f4 = fvarparm(1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, FLT_MAX);

    double  d1 = dvarparm(DBL_MAX);
    double  d2 = dvarparm(1.1, DBL_MAX);
    double  d3 = dvarparm(2.2, 3.3, DBL_MAX);
    double  d4 = dvarparm(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, DBL_MAX);
    return 0;
}
