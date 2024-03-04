#include <iostream>
using namespace std;
int main()
{
    int numero;
    cout << "Ingrese un numero de cinco dígitos: ";
    cin >> numero;
    if (numero >= 10000 && numero <= 99999) {
        int digito1 = numero / 10000;
        int digito2 = (numero / 1000) % 10;
        int digito3 = (numero / 100) % 10;
        int digito4 = (numero / 10) % 10;
        int digito5 = numero % 10;
        cout << digito1 << "   " << digito2 << "   " << digito3 << "   " << digito4 << "   " << digito5 << endl;
    }
    else {
        cout << "El numero ingresado no tiene cinco dígitos." << endl;
    }
}
