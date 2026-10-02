#pragma once
#include "Pago.hpp"

class TarjetaDeCredito : public Pago
{
private:
public:
	TarjetaDeCredito();
	~TarjetaDeCredito();
	double comision(double monto) override;
};

TarjetaDeCredito::TarjetaDeCredito()
{
}

TarjetaDeCredito::~TarjetaDeCredito()
{
}

double TarjetaDeCredito::comision(double monto)
{
	return 0.032 * monto + 0.5;
}
