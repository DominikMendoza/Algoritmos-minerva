#pragma once
#include "Pago.hpp"

class TarjetaCredito : public Pago
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
	return 0.032 * monto + 0.5;
}
