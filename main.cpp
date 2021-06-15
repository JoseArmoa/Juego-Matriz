#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "funciones.h"



int main()
{
    srand(time(0));
    int opcion, pilas;
    char matriz[6][6];
    char Usuario [30];
    cargarMatriz(matriz, 6);





    cout <<"        *****************************"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"       *          MATRIX             *"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"        *****************************"      <<endl<<endl<<endl;

    cout <<"1- Jugar"<<endl;
    cout <<"2- Estadisticas"<<endl;
    cout <<"3- Creditos"<<endl;
    cout <<"4- Salir"<<endl;




    cout <<"Ingrese una ocpion: "<<endl;
    cin >>opcion;

    while (opcion != 4)
    {
        switch(opcion)
        {
        case 1:
            system("cls");
            cargarDatos(Usuario);

        {


        } break;
        case 2:
        {} break;
        case 3:
        {} break;
        case 4: {

        }break;

        }

        cout <<"Ingrese una ocpion: "<<endl;
        cin >>opcion;
    }


    return 0;
}
