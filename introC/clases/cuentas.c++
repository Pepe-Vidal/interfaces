#include <stdio.h>
#include <iostream>

using namespace std;

string nombres[5]={"juan","perico","andres","fulano","vengano"};
string numCuentas[5]={"100","101","102","103","104"};

class Cuenta {

//private:
public:
	float saldo;
	string numCuenta;
	string titular;
	
	Cuenta() {
	}
	
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

Cuenta *cuentas[5];


void inicializarNull(Cuenta *cuentasP[5]){

	for(int i = 0; i < 5 ; i++) {
		cuentasP[i] = NULL;
	}

}


void inicializar(Cuenta *cuentasP[5]){

	for(int i = 0; i < 3 ; i++) {
		
		cuentasP[i] = new Cuenta();
	
		cuentasP[ i ]->saldo = i;
		cuentasP[ i ]->numCuenta = numCuentas[ i ];
		cuentasP[ i ]->titular = nombres[ i ];
	}

}


void mostrarCuenta(Cuenta *cuentasP[5]){
	
	for(int i = 0; i < 5 ; i++ ) {
	
		if(cuentasP[i] != NULL){
		cout << "La cuenta "<< cuentasP[i]->numCuenta << " de " << cuentasP[i]->titular << "tiene " << cuentasP[i]->saldo << endl;
		}
			
	}
	
} 

int main(int argc, char *argv[])
{
	inicializarNull(cuentas);
	inicializar(cuentas);
	mostrarCuenta(cuentas);
	
	/*
	for(int i ; i < 5 ; i++) {
		cuentas[ i ].ingresar( i );
		cuentas[ i ].numCuenta = numCuentas[ i ];
		cuentas[ i ].titular = nombres[ i ];
	}
	
	
	for(int i ; i < 5 ; i++ ) {
		mostrarCuenta( cuentas[ i ] );
	}
    */
}
