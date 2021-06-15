#include <iostream>
using namespace std;
#include "funciones.h"
void cargarMatriz(char m[][6], int tam){
    int i, x, n;
    for(i=0; i < tam; i++){
        for(x=0; x<tam; x++){

            n = (rand()%10)+48;
            m[i][x]= n;

        }

    }

}

void cargarDatos(char nombre[]){
    cout << "Ingrese nombre de Usuario: ";
    cin.ignore();
    cin.getline(nombre, 30);

}

