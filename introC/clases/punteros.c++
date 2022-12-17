#include <stdio.h>
#include <iostream>

using namespace std;

void incrementar( int *numero ){

	( *numero )++;
}


int * maximo( int *i ,int *j ) {

	if( *i >= *j )
		return i ;
	else
		return j ;
}

int main( int argc, char *argv[] )
{
 
	int i = 6 ;
 	int j = 9 ;
 	
 	( *maximo ( &i , &j ) )++;
 	

 	//cout << " i vale " << i << endl;
	//cout << " j vale " << j << endl;
	
	int original =9
	
	cout << " original vale " << original << endl;
	
	
}


