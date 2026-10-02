#pragma once
#include "Pago.hpp"

class Transferencia : public Pago
{
private:
public:
	Transferencia();
	~Transferencia();
	double comision(double monto) override;
};

Transferencia::Transferencia()
{
}

Transferencia::~Transferencia()
{
}

double Transferencia::comision(double monto)
{
	return 1.20;
}
