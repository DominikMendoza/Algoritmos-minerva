#pragma once
#include "PasarelaPago.hpp"

class BilleteraDigital : public PasarelaPago
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
	return 0.032 * monto + 0.5;
}
