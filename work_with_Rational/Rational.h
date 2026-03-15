#include <iostream>
using namespace std; //было бы славно упомянуть про необзодимость этих строк в презе

class Rational
{
private:
	// упрощение
	void simplify();
	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);

public:
	int numer;
	int denom;

	Rational();
	Rational(int n);
	Rational(int n, int d);

	//арифметические действия
	Rational& operator += (const Rational& r);
	// первый & вернет не копию, а ссылку на существующий объект
	// второй & делает тоже самое, но это надо для экономии памяти 
	Rational operator + (const Rational& r) const;
	Rational operator -() const; // const в конце гарантирует, что мы не поменяем 
								//само число, к которому применяеm сложение, при a + b не должно меняться a.
	Rational operator -(const Rational& r) const;
	Rational& operator -= (const Rational& r); 
	Rational& operator *= (const Rational& r);
	Rational operator * (const Rational& r) const;
	Rational sqrt() const;
	Rational& operator /= (const Rational& r);
	Rational operator / (const Rational& r) const;

	Rational& operator ++();
	Rational operator ++(int);
	
	//сравнение
	bool operator == (const Rational& r) const;
	bool operator != (const Rational& r) const;
	bool operator > (const Rational& r) const;
	bool operator >= (const Rational& r) const;
	bool operator < (const Rational& r) const;
	bool operator <= (const Rational& r) const;

	operator int() const;
	operator double() const;
};

