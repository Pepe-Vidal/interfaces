#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int numero, cuenta;
    cuenta = 0;
    numero = 0;

    do
    {
        cin >> numero;
        cuenta += numero;

        cout << "Numero " << numero << endl;

        cout << "cuenta" << cuenta << endl;

    } while (numero < 10 && cuenta < 20);
}