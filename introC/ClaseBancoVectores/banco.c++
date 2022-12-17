#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

#define BORRARPANTALLA for (int i = 0; i < 10 ; i++) cout << endl;
#define TAMVECTOR 5 

string nombres[TAMVECTOR]={"juan", "perico","andres",
                            "fulano","vengano"};
string numCuentas[TAMVECTOR]={"100","101","102","103","104"};

class Cuenta {

public:
     float saldo;
     string numCuenta;
     string titular;

    Cuenta(){};
    Cuenta(string tit, string numc) {
        numCuenta = numc;
        titular = tit;
        
        saldo = 0 ;
    }

    void ingresar(float cantidad){
        
        saldo += cantidad;
                 
    }
    
    float dameSaldo(){
        return saldo;
    }
    
    bool retirar(float cant) {
    
        if (cant <= saldo)
            saldo -=cant;
        else
            return false;
            
        return true;
    
    }

};

Cuenta * cuentas[TAMVECTOR];
vector<Cuenta> cuentasV;

void ingresoCuenta( Cuenta *cI  ) {

    float cantidad;
    
    cout << "cantidad a ingresar:";
    cin >> cantidad;
    

    cI->ingresar(cantidad);
}

void retirarCuenta( Cuenta *cI  ) {

    float cantidad;
    
    cout << "cantidad a retirar:";
    cin >> cantidad;
    
	if(!cI->retirar(cantidad)){
		cout << "No tienes dinero suficiente:";
	}
    
}

void saldoCuenta( Cuenta *cI  ) {

	cout << "La cuenta "<< cI->numCuenta << " tiene " << cI->saldo << " euros." << endl ;
	
}


void mostrar(Cuenta c) {

    cout << "Titular: " << c.titular ;
    cout << " NumC: " << c.numCuenta ;
    cout << " saldo: " << c.dameSaldo() << endl;
    
}



void mostrarTodasCuentas(Cuenta *cuentasP[TAMVECTOR]) {
    
    for (int i=0; i < TAMVECTOR; i++){
		if(cuentasP[i] != NULL){
			cout << cuentasP[i]->numCuenta << "\t" ;
			
		}
	}
    cout << endl;
    
    for (int i=0; i < TAMVECTOR; i++){
		if(cuentasP[i] != NULL){
			cout << cuentasP[i]->titular << "\t" ;
			
		}
	}
    cout << endl;
    
    for (int i=0; i < TAMVECTOR; i++){
		if(cuentasP[i] != NULL){
			cout << cuentasP[i]->saldo << "\t" ;
			
		}
    }
    cout << endl;


}


void inicializar(Cuenta *cuentasP[TAMVECTOR]) {

    for (int i= 0 ; i< 3 ; i++) {
        Cuenta * nueva ;
        nueva = new Cuenta();
        cuentas[i] = nueva;

        (*cuentasP[i]).saldo = 0;
        cuentasP[i]->titular = nombres[i];
        cuentasP[i]->numCuenta = numCuentas[i];
    }

}

void inicializarV(vector<Cuenta> & cuentasPasadas) {

    for (int i= 0 ; i< 3 ; i++) {
        Cuenta nueva ;

        nueva.saldo = 0;
        nueva.titular = nombres[i];
        nueva.numCuenta = numCuentas[i];
        
        
        cuentasV.push_back(nueva);
    }
}

void mostrarTodasCuentasV(vector<Cuenta>  cuentasPasadas) {
    
    for (int i= 0 ; i< cuentasPasadas.size() ; i++) {
        
        mostrar(cuentasPasadas[i]);
                
    }

}

void menu(void){


   BORRARPANTALLA
   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        b - Borrar Cuenta " << endl;
   cout << "        g - Agregar Cuentas " << endl;
   cout << "        5 - Salir a MSDOS " << endl;
   BORRARPANTALLA
}

Cuenta * seleccionarCuenta(Cuenta *cuentasP[TAMVECTOR]) {


	mostrarTodasCuentas(cuentasP);
	string num;
    
    cout << "Numero de cuenta:";
    cin >> num;

    for (int i= 0 ; i< TAMVECTOR ; i++) {
        
        if((cuentasP[i] != NULL) && (cuentasP[i]->numCuenta == num))
        	return cuentasP[i];
    }
    
    return NULL;
}

bool borrarCuenta(Cuenta *cuentasP[TAMVECTOR], Cuenta * cuentaSel) {


	mostrarTodasCuentas(cuentasP);
	/*string num;
    
    cout << "Que cuenta quieres borrar:";
    cin >> num;
*/
    for (int i= 0 ; i< TAMVECTOR ; i++) {
        
        if((cuentasP[i] != NULL) && (cuentasP[i] == cuentaSel)){
        	delete cuentasP[i];
        	cuentasP[i] = NULL;
        	cuentaSel = NULL;
        	
        	return true;
        }
    }
    
    return false;
}

void crearCuenta(Cuenta *cuentasP[TAMVECTOR]) {

    for (int i= 0 ; i< TAMVECTOR ; i++) {
    
    	if(cuentasP[i] == NULL){
			Cuenta * nueva ;
		    nueva = new Cuenta();
		    cuentas[i] = nueva;

		    cuentasP[i]->saldo = 0;
		    cuentasP[i]->titular = nombres[i];
		    cuentasP[i]->numCuenta = numCuentas[i];
		   
		   break;
    	}
    }

}



int main(int argc, char *argv[])
{

	inicializarV(cuentasV);
	mostrarTodasCuentasV(cuentasV);


return 0 ;

	char opcion;
	Cuenta * cuentaSelecionada = NULL;
	
	for(int i = 0; i < TAMVECTOR ; i++) 
		cuentas[i] = NULL;
	
	inicializar(cuentas);
	mostrarTodasCuentas(cuentas);
	
	opcion = '0';

	while(opcion != '5'){
	
		menu();
		cin >> opcion;
		
		switch (opcion){
		
			case '1': cuentaSelecionada = seleccionarCuenta(cuentas);
				break;
				
			case '2': 
				if( cuentaSelecionada != NULL ){
					ingresoCuenta( cuentaSelecionada  );
				}
				break;
			
			case '3':
				if( cuentaSelecionada != NULL ){
					retirarCuenta( cuentaSelecionada  );
				}
				break;
				
			case '4': 
				if( cuentaSelecionada != NULL ){
					saldoCuenta( cuentaSelecionada  );
				}
				break;
				
			case 'b': borrarCuenta(cuentas, cuentaSelecionada);
				break;
				
			case 'g': crearCuenta(cuentas);
				break;
				
			case '5': exit(0);
				break;
			
		};
	}

}

