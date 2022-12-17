#include <stdio.h>
#include <iostream>

using namespace std;


class Cuenta {

//private:
public:
	float saldo;
	string numCuenta;
	string titular;
	
	
	Cuenta(string titularPasada , string numCuentPasada) {
		numCuenta = numCuentPasada;
		titular = titularPasada;
		saldo = 0;
	}
	
//public:
	void ingresar(float cantidad ){
		saldo += cantidad;
	
	}
	
	bool retirar(float cantidad ){
	
		if (saldo > cantidad){
			saldo -= cantidad;
			return true;
		}
		
		return false;
		
	}
	
	float getsaldo(){
		return saldo;
	}

};

void ingresoCuenta( Cuenta *cI ){

	float cantidad;
	
	cout << "Cantidad a igresar: ";
	cin >> cantidad;
	
	cI->ingresar( cantidad );
}

void retiradaCuenta( Cuenta &cI ){

	float cantidad;
	
	cout << "Cantidad a retirar: ";
	cin >> cantidad;
	
	if (cI.retirar(cantidad))
		cout << "He podido sacar mas dinero del metido" << endl;
	else 
		cout << "No he podido sacar mas de lo que tengo" << endl;
	
}

void mostrarCuenta(Cuenta cI){

	cout << "La cuenta "<< cI.numCuenta << " de " << cI.titular << " tiene " << cI.saldo << endl;
}


int main(int argc, char *argv[])
{
	Cuenta c1("Juan","001");
	Cuenta c2("Paco","002");
	//c.titular = "juan";
	c1.saldo = 10;
	c2.saldo = 20;

	//c1 = c2;
	
	
	mostrarCuenta( c1 );
	mostrarCuenta( c2 );
	
	ingresoCuenta( &c2 );
	
	mostrarCuenta( c1 );
	mostrarCuenta( c2 );
	
	retiradaCuenta( c2 );
	
	mostrarCuenta( c1 );
	mostrarCuenta( c2 );

/*
	c1.ingresar(1000);

	if (c1.retirar(2000))
		cout << "He podido sacar mas dinero del metido" << endl;
	else 
		cout << "No he podido sacar mas de lo que tengo" << endl;


	c1.retirar(500);

	cout << "El saldo de la cuenta es " << c1.titular << " " << c1.numCuenta << " es " 
	<< c1.getsaldo() << endl;
*/

    
}
