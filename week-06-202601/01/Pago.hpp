#pragma once
#include <iostream>
using namespace std;
class Pago
{
private:

public:
	Pago();
	~Pago();
	virtual double comision(double monto) = 0;
};

Pago::Pago()
{
}

Pago::~Pago()
{
}