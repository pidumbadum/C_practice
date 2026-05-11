#pragma once
#include <iostream>
class Function
{
	int x;
public:
	virtual double y() const { return x; };
	virtual double min(int a, int b) const { return 0; };
	virtual double max(int a, int b) const { return 0; };
};

