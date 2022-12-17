#include <stdio.h>
#include <iostream>

using namespace std;

void incrementar( int *numero ){

	( *numero )++;
}

void decrementar( int &numero ){

	( numero )--;
}

int * maximo( int *i ,int *j ) {

	if( *i >= *j )
		return i ;
	else
		return j ;
}

int & minimo( int &i ,int &j ) {

	if( i <= j )
		return i ;
	return j ;
}

int main( int argc, char *argv[] )
{
 
	int i = 9;
	int j = 6;
	
	( minimo( i , j ) )--;
	
	int &v = minimo( i , j );
	v--;
	
	cout << "i vale " << i << endl;
	cout << "j vale " << j << endl;
	
	
}
