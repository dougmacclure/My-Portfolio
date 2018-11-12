#include <iostream>
#include <iomanip>

#include "SpecialArray.h"

using namespace std;

int main()
{

SpecialArray s1, s3, s2;

cout << s1 << endl;
s1.insertValue(99);
s2.insertValue(7);
cout << s2 << s1;

s3 = s2 + 0.5432543;

cout << s3 << endl;

s2 += s3;


return 0;
}
