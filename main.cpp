#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"


int main()
{
    srand(time(0));
    int opcion, pilas, color;
    int matrizNumeros [6][6];
    char Usuario [30];
    cargarMatrizNum(matrizNumeros, 6);



    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::RED);
    rlutil::saveDefaultColor();


    rlutil::cls();


    cout <<"        *****************************"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"       *          MATRIX             *"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"        *****************************"      <<endl<<endl<<endl;


    cout <<"----------------------"<<endl;
    cout <<"1- Jugar"<<endl;
    cout <<"2- Estadisticas"<<endl;
    cout <<"3- Creditos"<<endl;
    cout <<"0- Salir"<<endl;

    cout <<"----------------------"<<endl;


    cout <<"Ingrese una opcion: "<<endl;
    cin >>opcion;

    while (opcion != 0)
    {
        switch(opcion)
        {
        case 1:
            pilas = 3;
            system("cls");
            cargarDatos(Usuario);
            rlutil::cls();
            seleccionColor(color);
            rlutil::cls();

            while(pilas !=0){
                matrizNumeros[2][3]= 99;

                mostrarJuego(matrizNumeros,Usuario, pilas, color);
                comienzoJuego(matrizNumeros,pilas);
                rlutil::cls();
            }


            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        }

        cout <<"Ingrese una opcion: "<<endl;
        cin >>opcion;
    }


    return 0;
}
