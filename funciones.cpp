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

    rlutil::locate(56, 10);
    cout << "*******************"<<endl;
    rlutil::locate(56, 11);
    cout << "*  MOVIMIENTOS:   *" << endl;
    rlutil::locate(56, 12);
    cout << "*******************"<<endl;
    rlutil::locate(56, 13);
    cout << "*  ARRIBA: 8      *"<<endl;
    rlutil::locate(56, 14);
    cout << "*  ABAJO: 2       *"<<endl;
    rlutil::locate(56, 15);
    cout << "*  DERECHA : 6    *"<<endl;
    rlutil::locate(56, 16);
    cout << "*  IZQUIERDA: 4   *" << endl;
    rlutil::locate(56, 17);
    cout << "*******************"<<endl;


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



void comienzoJuego(int mn[][6], int &p , int &pts){

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
                    sumarPuntos(mn,pts,fila,columna,fila2,columna2,fila3,columna3);
                    cout << "Felicidades ha sumado puntos";
                    ponerNulo (mn,fila,columna,fila2,columna2,fila3,columna3);

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

   if(x > 5 || y > 5){
        return false;
    }

    if(f2 > 5 || c2 > 5){
        return false;
    }

    if(f3 > 5 || f3 > 5){
        return false;
    }



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


void sumarPuntos (int m[][6], int &p , int f , int c , int f2 , int c2 , int f3 , int c3){
                p += m[f][c]+ m[f2][c2] + m[f3][c3];


}


void ponerNulo (int m[][6], int f , int c , int f2 , int c2 , int f3 , int c3 ){
                m [f][c] = 99;
                m [f2][c2] = 99;
                m [f3][c3] = 99;
}



void mostrarEstadisticas (int vec[], string nombres[] , int i[] ){
        rlutil::locate(1,1);
        cout << "Jugador";
        rlutil::locate(30,1);
        cout << "Puntaje";
        rlutil::locate(1,2);
        cout << nombres [i [0]];
        rlutil::locate(30,2);
        cout << vec  [0];
        rlutil::locate(1,3);
        cout << nombres [i [1]];
        rlutil::locate(30,3);
        cout << vec [1];
        rlutil::locate(1,4);
        cout << nombres [i [2]];
        rlutil::locate(30,4);
        cout << vec [2];
        rlutil::locate(1,5);
        cout << nombres [i [3]];
        rlutil::locate(30,5);
        cout << vec [3];
        rlutil::locate(1,6);
        cout << nombres [i [4]];
        rlutil::locate(30,6);
        cout << vec [4];
        rlutil::locate(1,7);
        cout << nombres [i [5]];
        rlutil::locate(30,7);
        cout << vec [5];
        rlutil::locate(1,8);
        cout << nombres [i [6]];
        rlutil::locate(30,8);
        cout << vec [6];
        rlutil::locate(1,9);
        cout << nombres [i [7]];
        rlutil::locate(30,9);
        cout << vec [7];
        rlutil::locate(1,10);
        cout << nombres [i [8]];
        rlutil::locate(30,10);
        cout << vec [8];
        rlutil::locate(1,11);
        cout << nombres [i [9]];
        rlutil::locate(30,11);
        cout << vec [9];





        rlutil::anykey();
        rlutil::cls();

}



void cargarEstadisticas (int  p[] , int  v, int tam , string c[] , char n[]){
       int i;
       for (i=0 ; i<tam ; i++){
            if (p[i]==0){
                p[i]= v;
                c[i]=n;
                break;
            }

       }

}



void ordenarVector(int v[], int t , int n[]){
    int i, x, aux;
    for(i = 0; i<t; i++){
        for(x=0; x<t-1; x++){
            if(v[x] < v[x+1]){
                aux = v[x+1];
                v[x+1] = v [x];
                v[x]= aux;
                aux = n[x+1];
                n[x+1] = n[x];
                n [x] = aux;

            }
        }

    }

}



void nombre(string m[]){
    char v[30] = {"No hay datos"};
    int i, x;
    for(i=0; i<10; i++){
        for(x=0; x<30; x++){

            m[i]= v;

        }

    }


}


void mostrarCreditos(){


        cout << "***********************************************"<<endl;
        cout << "*   PROJECTO CREADO POR ESTUDIANTES DE FRGP   *"<<endl;
        cout << "*   LOS INTEGRANTES DEL GRUPO SON:            *"<<endl;
        cout << "*   SOSA ALEJANDRO (24566)                    *"<<endl;
        cout << "*   ARMOA JOSE (22337)                        *"<<endl;
        cout << "*   CABRERA FEDERICO (23144)                  *"<<endl;
        cout << "***********************************************"<<endl;

        rlutil::anykey();
        rlutil::cls();


}
