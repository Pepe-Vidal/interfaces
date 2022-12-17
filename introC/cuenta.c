#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	int numeros;
	numeros = 0;
	
	while(numeros<=10){
	
	cout << numeros++ <<endl;
	}
	
	numeros=10;
	for(int i = 5;i>=0;i--){
	cout << numeros <<endl;
	numeros-=2;
	}
	
}
