#pragma once
#include "PasarelaPago.hpp"

class TarjetaCredito : public PasarelaPago
{
private:

public:
	TarjetaCredito();
	~TarjetaCredito();
	double comision(double monto) override;

};

TarjetaCredito::TarjetaCredito()
{
}

TarjetaCredito::~TarjetaCredito()
{
}

double TarjetaCredito::comision(double monto)
{
	return min(0.022 * monto, 8.0);
}
