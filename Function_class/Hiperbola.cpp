#include "Hiperbola.h"

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

double Hiperbola::y() const {
	return k / x;
}
double Hiperbola::min(int a, int b) const {
	cout << "У класической гиперболы нет точек минимума. ";
	return y();

}
double Hiperbola::max(int a, int b) const {
	cout << "У класической гиперболы нет точек максимум. ";
	return y();
}