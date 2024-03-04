#include <iostream>
using namespace std;
int main()
{
    int numero;
    do {
        cout << "Numero: ";
        cin >> numero;
        if (numero != 0) {
            cout << "El numero " << numero << " es " << (numero % 2 == 0 ? "par" : "impar") << "." << endl;
        }
    } while (numero != 0);
    cout << "Saliendo..." << endl;
}

