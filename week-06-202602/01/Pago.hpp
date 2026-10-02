#pragma once
#include <iostream>
using namespace std;
class Pago
{
private:
public:
	Pago();
	~Pago();
	virtual double comision(double monto);
};

Pago::Pago()
{
}

Pago::~Pago()
{
}

double Pago::comision(double monto)
{
	return 0.0;
}
