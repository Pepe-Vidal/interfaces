#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int numeros[50];

bool repetido(int numeros[50]){

	
	
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < 50; i++)   
		numeros[i] = random() % 11;
    
    for (int i = 0; i < 50; i++)
		cout << numeros[i] << " ";
    
    consecutivo(numeros);
    
}
