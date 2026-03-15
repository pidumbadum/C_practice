#include <iostream>
using namespace std;
#include "Rational.h"
class RationalExeption {};

int NOD(int a, int b) {
	if (a < 0) { a *= 1; }
	if (b < 0) { b *= 1; }
	while (b != 0) {
		int ostatok = a % b;
		a = b;
		b = ostatok;
	}
	return a;
}


//объявление
Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int nam) 
{
	numer = nam;
	denom = 1;
}
Rational::Rational(int num, int den)
{
	numer = num;
	denom = den;
	simplify();
}

//арифметические действия
Rational& Rational::operator += (const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}
Rational Rational::operator + (const Rational& r) const
{
	Rational res(*this);
	return res += r;
}
Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}
Rational Rational::operator -(const Rational& r) const
{
	Rational res(*this);
	return (res += (-r));
}
Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}
Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}
Rational Rational::operator++ (int)
{
	Rational res(*this);
	numer += denom; //почему здесь не нужно прописывать res.numer?
	return res;
}
Rational& Rational::operator *= (const Rational& r)
{
	numer = numer * r.numer;
	denom = denom * r.denom;
	simplify();
	return (*this);
}
Rational Rational::operator * (const Rational& r) const
{
	Rational res(numer, denom);
	return (res *= r);
}
Rational& Rational::operator /= (const Rational& r)
{
	Rational divider(r.denom, r.numer);
	return(*this *= divider);
}
Rational Rational::operator / (const Rational& r) const
{
	Rational res(numer, denom);
	return res /= r;
}
Rational Rational::sqrt() const
{
	int numer1 = numer;
	int denom1 = denom;

	for (int j = 0; j < 3; j++)
	{
		denom1 = (denom1 + denom / denom1) / 2;
	}
	for (int j = 0; j < 3; j++)
	{
		numer1 = (numer1 + numer / numer1) / 2;
	}
	Rational Xn(numer1, denom1);
	return Xn;
}

//сравнение 
bool Rational::operator ==(const Rational& r) const
{
	// return (numer == r.numer) && (denom == r.denom); - не прокатит для 1/3 и 3/9
	
	return (numer * r.denom == r.numer * denom);

}
bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}
bool Rational::operator > (const Rational& r) const
{
	return (numer * r.denom > r.numer * denom);
}
bool Rational::operator >= (const Rational& r) const
{
	return (numer * r.denom >= r.numer * denom);
}
bool Rational::operator < (const Rational& r) const
{
	return !(*this > r);
}
bool Rational::operator <= (const Rational& r) const
{
	return !(*this >= r);
}

// перевод в другие типы
Rational::operator int() const{ return numer / denom; }
Rational::operator double() const { return (double(numer) / denom); }

istream& operator >>(istream& in, Rational& r) // как работает это
{
	in >> r.numer >> r.denom;
	if (r.denom == 0) { throw RationalExeption(); }
	r.simplify(); //методом тыка
	return in; 
}
ostream& operator <<(ostream& out, const Rational& r)
{
	if (r.numer == r.denom) {
		out << 1;
	}
	else{out << r.numer << "/" << r.denom;}
	return out;
}

void Rational::simplify() {
	int nod = NOD(numer, denom);
	if (nod != 0) {
		numer /= nod;
		denom /= nod;
	}
	if (denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}

