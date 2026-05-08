#pragma once
#include "Pago.hpp"

class BilleteraDigital : public Pago
{
private:
public:
	BilleteraDigital();
	~BilleteraDigital();
	double comision(double monto) override;
};

BilleteraDigital::BilleteraDigital()
{
}

BilleteraDigital::~BilleteraDigital()
{
}

double BilleteraDigital::comision(double monto)
{
	return min(0.022 * monto, 8.0);
}
