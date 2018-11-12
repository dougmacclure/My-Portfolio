#ifndef SPECIALARRAY_H
#define SPECIALARRAY_H
#include <fstream>

using namespace std;

class SpecialArray
{
friend ostream & operator<<(ostream&, const SpecialArray&);
int position;
static const int MAX = 75;//static allows a place in memory for MAX since class defn is just a pattern, and doesn't allocate memory for data members
double array[MAX];

public:
SpecialArray();
void insertValue(double);
double removeValue();
SpecialArray operator+(const SpecialArray &)const;
SpecialArray operator+(const double & )const;
SpecialArray & operator+=(const double &);


};

#endif
