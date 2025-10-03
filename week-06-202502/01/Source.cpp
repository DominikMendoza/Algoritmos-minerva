#include "BilleteraDigital.hpp"
#include "Transferencia.hpp"
#include "TarjetaCredito.hpp"

int main()
{
	PasarelaPago* pp;
	double monto = 1000.0;
	pp = new BilleteraDigital();

	cout << "BD Comision: " << pp->comision(monto) << endl;

	pp = new TarjetaCredito();

	cout << "TC Comision: " << pp->comision(monto) << endl;

	pp = new Transferencia();

	cout << "T Comision: " << pp->comision(monto) << endl;

	system("pause>0");
	return 0;
}