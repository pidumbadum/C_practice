#pragma once
class Rational
{
private:
	// упрощение
	void simplify();

public:
	int numer;
	int denom;

	Rational();
	Rational(int n);
	Rational(int n, int d);

	Rational& operator += (const Rational& r);
	// первый & вернет не копию, а ссылку на существующий объект
	// второй & делает тоже самое, но это надо для экономии памяти 
	Rational operator + (const Rational& r) const;
	Rational operator -() const; // const в конце гарантирует, что мы не поменяем 
								//само число, к которому применяеm сложение, при a + b не должно меняться a.
	/*Rational operator -(const Rational& r) const;*/
	Rational& operator -= (const Rational& r); 
	

};

