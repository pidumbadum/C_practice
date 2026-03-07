//qwest: 
//(const Rational& r) что за r и зачем &

#include "Rational.h"

int NOD(int a, int b) {
	while (b != 0) {
		int ostatok = a % b;
		a = b;
		b = ostatok;
	}
	return a;
}

Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int namber) {
	numer = namber;
	denom = 1;
}
Rational::Rational(int num, int den)
{
	numer = num;
	denom = den;
}
Rational& Rational::operator += (const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
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
//Rational& Rational::operator -(const Rational& r) const
//{
//	Rational res(*this);
//	return (res += (-r));
//}
Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}

void Rational::simplify() {
	int nod = NOD(numer, denom);
	if (nod != 0) {
		numer /= nod;
		denom /= nod;
	}
	
}
