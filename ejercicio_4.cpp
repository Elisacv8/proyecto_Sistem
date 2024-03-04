#include <iostream>
using namespace std;

int main() {
    const int tamano = 10;  
    //1
    cout << "Patron 1:\n";
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    //2
    cout << "Patron 2:\n";
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";
    //3
    cout << "Patron 3:\n";
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * (tamano - i) - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    //4
    cout << "Patron 4:\n";
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
