#pragma once
#include "Function.h"
#include <iostream>
using namespace std;


class Hiperbola : public Function
{
	double k;
	double x;
public:
	Hiperbola();
	Hiperbola(double x1);
	Hiperbola(double x1, double k1);

	double y();
	double min(int a, int b);
	double max(int a, int b);
};