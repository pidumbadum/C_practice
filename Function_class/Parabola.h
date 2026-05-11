#pragma once
#include "Function.h"
#include <iostream>
using namespace std;


class Parabola : public Function
{
	double a, b, c, x;
public:
	Parabola();
	Parabola(double x1);
	Parabola(double x1, double a1);
	//Parabola(double x1, double a1, double b1);
	//Parabola(double x1, double a1, double b1, double c1);

	//double y();
	//double min(int a, int b);
	//double max(int a, int b);
};