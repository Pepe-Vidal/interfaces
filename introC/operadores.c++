#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Complejo {
public:
    float real;
    float imaginaria;
    
    Complejo(){
	}
    
    Complejo( float r , float i){

		real = r;
		imaginaria = i;

	}
	
	Complejo operator+ ( Complejo d){

		return Complejo( real + d.real , imaginaria + d.imaginaria );
	}


	Complejo operator+ (float d){

		return Complejo( real + d , imaginaria );
	}
	
	
	bool operator< ( Complejo d){
	
		return modulo() < d.modulo() ;

	}
	
	bool operator> ( Complejo d){
	
		return !( ( *this ) < d );
	

	}
	
	
	float modulo(){
	
		return sqrtf(powf (imaginaria,2) + powf (real,2));
	}


};


void mostrar(Complejo c){
    cout << "( " << c.real << " + " << c.imaginaria << "i )" ;
}

Complejo sumar(Complejo c, Complejo d){


	return Complejo( c.real + d.real , c.imaginaria + d.imaginaria );

}

Complejo operator+ (float d,Complejo c){


	return Complejo( c.real + d , c.imaginaria );

}

int main (int argc, char *argv[] ) {
    Complejo c;
    c.real = 9;
    c.imaginaria = 2;

    mostrar(c);
    cout << endl;
    
    Complejo d( 8 , -6 );

    mostrar(d);
    cout << endl;
    
    Complejo suma;
    
    suma = sumar(c,d);
    mostrar(suma);
    cout << endl;
    
    suma = c + d;
    mostrar(suma); 
    cout << endl;
    
    suma = 2 + c;
    mostrar(suma);
    cout << endl;
    
    suma = c + 2;
    mostrar(suma);
    cout << endl;
    
    
    if ( c > d ) cout << "c es mayor " << endl;
    if ( c < d ) cout << "d es mayor " << endl;
    
}

