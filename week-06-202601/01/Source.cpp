#include "BilleteraDigital.hpp"
#include "TarjetaCredito.hpp"
#include "Transferencia.hpp"

int main()
{
	Pago* pago;

	
	/*BilleteraDigital* bd = new BilleteraDigital();
	TarjetaCredito* tc = new TarjetaCredito();
	Transferencia* t = new Transferencia();*/

	pago = new BilleteraDigital();
	cout << "Billetera digital: " << pago->comision(10000) << endl;

	pago = new TarjetaCredito();
	cout << "Tarjeta Credito: " << pago->comision(10000) << endl;

	pago = new Transferencia();
	cout << "Transferencia: " << pago->comision(10000) << endl;
	return 0;
}