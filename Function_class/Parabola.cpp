#include "Parabola.h"

Parabola::Parabola() {
	a = b = c = x = 0;
}

Parabola::Parabola(double x1){
	Parabola();
}
Parabola::Parabola(double x1, double a1) {
	Parabola();
	x = x1;
	a = a1;
}
//Parabola::Parabola(double x1, double a1, double b1);
//Parabola::Parabola(double x1, double a1, double b1, double c1);