//


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Complex
{
public:
Complex(int, int);
void add(int, int);
void multiply(int, int);
void print();

private:

int real;
int imaginary;



};




int main()
{

Complex complex1(5, 7);
complex1.print();
complex1.multiply(2, -2);
complex1.print();
Complex complex2[3] = {{5,7}, {2,-2}, {10,20}};
complex2[0].print();
complex2[2].print();
comlpex2[2].multiply(42, -21)

return 0;

}

//method definitions

Complex::Complex(int newr, int newi)
{
real = newr
imaginary = newi
}

void Complex::add(int addR, int addI)
{

real = real + addR;
imaginary = imaginary + addI;

}

void Complex::multiply(int multR, int multI)
{

int initReal = real, initImag = imaginary;

real = initReal*multR - initImag*multI;
imaginary = initReal*multI + initImag*multR;
}

void Complex::print()
{

cout << "The result is " << real << " + (" << imaginary << ")i";

}
