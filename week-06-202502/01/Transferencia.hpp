#pragma once
#include "PasarelaPago.hpp"

class Transferencia : public PasarelaPago
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
	return 1.2;
}
