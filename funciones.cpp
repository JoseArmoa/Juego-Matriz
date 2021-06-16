#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

void cargarMatriz(char m[][6], int tam)
{
    int i, x, n;
    for(i=0; i < tam; i++)
    {
        for(x=0; x<tam; x++)
        {

            n = (rand()%10)+48;
            m[i][x]= n;

        }

    }

}

void cargarDatos(char nombre[])
{
    cout << "Ingrese nombre de Usuario: ";
    cin.ignore();
    cin.getline(nombre, 30);


}



void mostrarJuego(char m[][6], char v[], int p)
{
    rlutil::locate(2, 1);
    cout << v ;

    rlutil::locate(60,1 );
    vida(p);


    mostrarMatriz(m);





}



void vida(int n)
{

    char vida [4];
    vida [0] = 254;
    vida [1] = 254;
    vida [2] = 250;
    vida [3] = '\0';



    switch(n)
    {
    case 3:
        cout << vida << " " << vida << " " << vida;
        break;
    case 2:
        break;

    case 1:
        break;

    }

}

void mostrarMatriz(char m [][6]){
    int i, x, y , b;
    y = 3;

    for(i=0; i<6; i++){
        x = 30;
        for(b=0; b<6; b++){

            rlutil::locate(x,y);
            cout << m[i][b] << " " ;
            x+=2;
        }
        y+=1;

        cout << endl;
    }

}





