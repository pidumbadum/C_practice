#include "Hiperbola.h"
class HiperbolaExeption {};

Hiperbola::Hiperbola() {
	k = 0;
	x = 1;
}
Hiperbola::Hiperbola(double x1) {
	k = 0;
	x = x1;
}
Hiperbola::Hiperbola(double x1, double k1) {
	x = x1;
	k = k1;
}

double Hiperbola::y() {
	return k / x;
}
double Hiperbola::min(int a, int b)  {
	cout << "У класической гиперболы нет точек минимума. ";
	if (a == 0 || b == 0 || a == b) { throw HiperbolaExeption(); }
	if (k / a < k / b) { return k / a; }
	else return k / b;
}
double Hiperbola::max(int a, int b)  {
	cout << "У класической гиперболы нет точек максимума. ";
	if (a == 0 || b == 0 || a == b) { throw HiperbolaExeption(); }
	if (k / a > k / b) { return k / a; }
	else return k / b;
}