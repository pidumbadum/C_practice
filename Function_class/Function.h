#pragma once
#include <iostream>
class FunctionExeption {};
class Function
{
	int x;
public:
	Function() { x = 0; };
	Function(int x1) { x = x1; }

	virtual double y() { return x; }
	virtual double min(int a, int b) { return 0; }
	virtual double max(int a, int b) { return 0; }
};