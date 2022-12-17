#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int n1, n2, n3;
    printf("Introduce el numero 1\n");
    cin >> n1;
    printf("Introduce el numero 2\n");
    cin >> n2;
    printf("Introduce el numero 3\n");
    cin >> n3;

    if (n1 > n2 && n1 > n3)
    {
        cout << "El primer numero es mayor" << endl;
    }else{
        cout << "El primer numero no es mayor" << endl;
    }
}