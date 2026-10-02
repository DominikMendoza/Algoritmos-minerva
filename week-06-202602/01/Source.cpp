#include "BilleteraDigital.hpp"
#include "TarjetaDeCredito.hpp"
#include "Transferencia.hpp"

int main() {
	Pago* metodoDePago;
	double monto;

	cout << "Ingrese monto: ";
	cin >> monto;

	metodoDePago = new BilleteraDigital();
	cout << "Comision con Billetera digital: " << metodoDePago->comision(monto) << endl;

	metodoDePago = new TarjetaDeCredito();
	cout << "Comision con Tarjeta de credito: " << metodoDePago->comision(monto) << endl;

	metodoDePago = new Transferencia();
	cout << "Comision con Transferencia: " << metodoDePago->comision(monto) << endl;
	system("pause>0");
	return 0;
}