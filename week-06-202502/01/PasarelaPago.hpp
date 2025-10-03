#pragma once
#include <iostream>
#include <string>

using namespace std;

class PasarelaPago
{
private:

public:
	PasarelaPago();
	~PasarelaPago();
	virtual double comision(double monto);

};

PasarelaPago::PasarelaPago()
{
}

PasarelaPago::~PasarelaPago()
{
}

double PasarelaPago::comision(double monto)
{
	return 0.0;
}
