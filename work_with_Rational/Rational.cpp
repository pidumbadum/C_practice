#include <iostream>
using namespace std;
#include "Rational.h"
class RationalExeption {};

static int NOD(int a, int b) {
	if (a < 0) { a = -a; }
	if (b < 0) { b = -b; }
	while (b != 0) {
		int ostatok = a % b;
		a = b;
		b = ostatok;
	}
	return a;
}
static int NOK(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (a < 0) { a = -a; }
	if (b < 0) { b = -b; }

	int gcd = NOD(a, b);

	return (a / gcd) * b;
}
static void check_multiply(int a, int b) {
	if (a == 0 || b == 0) return;

	bool overflow = false;

	if (a > 0 && b > 0) {
		if (a > INT_MAX / b) overflow = true;
	}
	else if (a < 0 && b < 0) {
		if (a < INT_MAX / b) overflow = true;  
	}
	else {
		if (a > 0) { 
			if (b < INT_MIN / a) overflow = true;
		}
		else {
			if (a < INT_MIN / b) overflow = true;
		}
	}

	if (overflow) {
		throw RationalExeption();
	}
}
static void check_plus(int a, int b) {
	if (a < 0 && b < 0) {
		if (a < INT_MIN - b) {
			//cout << "\nПереполнение int\n";
			throw RationalExeption();
		}
	}
	else if (a > 0 && b > 0) {
		if (a > INT_MAX - b) {
			//cout << "\nПереполнение int\n";
			throw RationalExeption();
		}
	}
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
// Конструктор из double 
Rational::Rational(double val) {
	// union позволяет записать биты одного типа данных, а прочитать как другой, прикол 
	union { double d; unsigned long long b; } u; 
	// дабл записан, теперь на него можно посомтреть и как на длинный инт
	u.d = val;

	//дальше достаю знак, экспоненту, мантиссу, побитовыми сдвигами и умножением на маску(останется только нужное)
	unsigned long long sign = (u.b >> 63) & 1;
	unsigned long long exp = (u.b >> 52) & 0x7FF;
	unsigned long long mant = u.b & 0xFFFFFFFFFFFFFull;

	//Ноль?
	if (exp == 0 && mant == 0) {
		numer = 0; denom = 1; return;
	}

	//Получаем мантиссу целиком со спрятанной еденицей и степень двойки 
	// значение = (-1)^знак × 2^(exp - 1023) × 1.мантисса
	unsigned long long M = (1ULL << 52) | mant;
	int E = (int)exp - 1023 - 52;
	unsigned long long num, den;

	if (E >= 0) {
		// Число >= 1: сдвигаем мантиссу влево
		num = M << E;
		den = 1;
	}
	else {
		// Число < 1: степень уходит в знаменатель
		int shift = -E;
		num = M;
		den = 1ULL << shift;
	}
	//проверяем чектное или несетное, если четное сносим двойку одну
	while (((num & 1) == 0 && (den & 1) == 0) || num > INT_MAX || den > INT_MAX) {
		num >>= 1;
		den >>= 1;
	}

	numer = sign ? -(long long)num : (long long)num;
	denom = (long long)den;

	simplify();
}

//арифметические действия
Rational& Rational::operator += (const Rational& r) {
	int nok_denoms = NOK(denom, r.denom);
	check_multiply(numer, (nok_denoms / denom));
	check_multiply(r.numer, (nok_denoms / r.denom));
	int a = numer * (nok_denoms / denom);
	int b = r.numer * (nok_denoms / r.denom);
	check_plus(a, b);
	numer = (numer * (nok_denoms/denom) + r.numer * (nok_denoms/r.denom));
	denom = nok_denoms;
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
	check_multiply(numer, r.numer);
	check_multiply(denom, r.denom);
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
Rational Rational::sqrt() const {
	if (numer < 0) {
		cout << "Ошибка: корень из отрицательной дроби не определён\n";
		throw(RationalExeption());
	}

	int r = numer;                
	while (true) {
		int q = numer / r;
		if (r <= q) break;
		r = (r + q) / 2;
	}
	int root_num = r;

	int d = denom;            
	while (true) {
		int q = denom / d;
		if (d <= q) break;
		d = (d + q) / 2;
	}
	int root_den = d;

	return Rational(root_num, root_den); 

}

//Арифметические операции с интами
Rational& Rational::operator *= (const int r) {
	Rational a(r);
	*this *= a;
	return (*this);
}
Rational Rational::operator * (const int r) const {
	Rational res(numer, denom);
	return res *= r;
}
Rational& Rational::operator += (const int r) {
	Rational a(r);
	*this += a;
	return *this;
}
Rational Rational::operator + (const int r) const {
	Rational res(numer, denom);
	return res += r;
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
bool Rational::operator < (const int& r) const
{
	Rational a(r);
	return !(*this > a);
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