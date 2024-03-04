#include <iostream>
using namespace std;
int main()
{
	int contador = 0, numero = 0, mayor = 0;
	while (contador <= 9)
	{
		cout << "Ingrese el numero de ventas: " << endl;
		cin >> numero; 			contador++;
		if (mayor < numero) {
			mayor = numero;
		}
	}
	cout << "El mayor numero de ventas es: " << numero;
}
