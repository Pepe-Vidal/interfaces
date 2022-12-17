#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int notas[10];

float calcularMedia(int notas[10]){

    int media;
	for (int i = 0; i < 10; i++)   
		media += notas[i];
	
    return (float) media/10;
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < 10; i++)   
		notas[i] = random() % 11;
    
    for (int i = 0; i < 10; i++)
		cout << notas[i] << " ";
    
    cout << endl << calcularMedia(notas) <<endl;
    
}



