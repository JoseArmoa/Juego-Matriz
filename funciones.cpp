#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "matrizcolor.h"

void cargarMatrizNum(int m[][6], int tam)
{
    int i, x, n;
    for(i=0; i < tam; i++)
    {
        for(x=0; x<tam; x++)
        {

            n = rand()%10;
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

void seleccionColor(int &c){

    cout <<"1- Azul" <<endl;
    cout <<"2- Rojo" <<endl;
    cout <<"3- Blanco" <<endl;
    cout <<endl;
    cout <<"-----------------------------" <<endl;
    cout <<endl;
    cout <<"Elije un color: ";
    cin >>c;

}


void mostrarJuego(int m[][6], char v[], int &p, int c, int pts)
{
    rlutil::locate(2, 1);
    cout << v ;

    rlutil::locate(30, 1);
    cout <<"Puntos: " << pts;

    rlutil::locate(60,1 );
    vida(p);




    switch(c){
    case 1:
        mostrarAzul(m);
        break;

    case 2:
        mostrarRojo(m);
        break;

    case 3:
        mostrarBlanco(m);
        break;

    }





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
        cout << vida << " " << vida;
        break;

    case 1:
        cout << vida;
        break;

    }

}



void comienzoJuego(int mn[][6], int &p){

    int fila, columna, direccion, fila2, fila3, columna2, columna3;
    char operador;
    bool r;


        cout << "Ingrese Numero de fila: ";
        cin  >> fila;

        cout << "Ingrese Numero de columna: ";
        cin  >> columna;

        cout << "Ingrese  Operacion a validar: ";
        cin  >> operador;

        cout << "Ingrese direccion: ";
        cin  >> direccion;

        fila--;
        columna--;

        cargarDireccion(direccion, fila, columna, fila2, columna2, fila3, columna3);


        r = validarDatos(mn,fila,columna, fila2, columna2, fila3, columna3);


        if(r)
        {
           r = validarOperacion(mn, fila, columna, fila2, columna2, fila3, columna3, operador);
           if(r){
                    cout << "True";
                    rlutil::anykey();
                } else {
                    cout <<"La operacion no es valida."<<endl;
                    cout <<"!A perdido una pila!!! :("<<endl;
                    rlutil::anykey();
                    p--;
                }
        }
        else
        {
            cout <<"La operacion no es valida."<<endl;
            cout <<"!A perdido una pila!!! :("<<endl;
            rlutil::anykey();
            p--;
        }




}


bool validarDatos(int mc[][6], int x, int y, int f2, int c2, int f3, int c3){





    if ((mc[x][y] >= 0 && mc[x][y] <= 9) && (mc[f2][c2] >= 0 && mc[f2][c2] <= 9) && (mc[f3][c3] >= 0 && mc[f3][c3] <= 9 )   ){
        return true;
    } else {
        return false;
    }


}




void cargarDireccion( int d, int x, int y, int &f2, int &c2, int &f3, int &c3){

   switch(d){

    case 8:
        f2 = x - 1;
        c2 = y;
        f3 = x - 2;
        c3 = y;
         break;

    case 6:
        f2 = x;
        c2 = y + 1;
        f3 = x;
        c3 = y + 2;
         break;

    case 2:
        f2 = x + 1;
        c2 = y;
        f3 = x + 2;
        c3 = y;
         break;

    case 4:
        f2 = x;
        c2 = y - 1;
        f3 = x;
        c3 = y - 2;
          break;


    }

}

bool validarOperacion(int m[][6], int f, int c, int f2, int c2, int f3, int c3, char o){
        int r;
        switch(o){
            case '+':
                r = m[f][c] + m[f2][c2];
                if (r == m[f3][c3]){
                    return true;
                    } else {
                    return false;
                    }
            break;

            case '-':
                r = m[f][c] - m[f2][c2];
                if (r == m[f3][c3]){
                    return true;
                    } else {
                    return false;
                    }
                break;

            case '*':
                r = m[f][c] * m[f2][c2];
                if (r == m[f3][c3]){
                    return true;
                    } else {
                    return false;
                    }
                break;

            case '/':
                r = m[f][c] / m[f2][c2];
                if (r == m[f3][c3]){
                    return true;
                    } else {
                    return false;
                    }
                break;

            case '%':
                r = m[f][c] % m[f2][c2];
                if (r == m[f3][c3]){
                    return true;
                    } else {
                    return false;
                    }
                break;
        }
}
