#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"



int main()
{
    srand(time(0));
    int opcion, pilas;
    int matrizNumeros [6][6];
    char matrizCaracteres[6][6];
    char Usuario [30];
    cargarMatrizNum(matrizNumeros, 6);
    cargarMatrizCaract(matrizCaracteres,matrizNumeros, 6);





    cout <<"        *****************************"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"       *          MATRIX             *"      <<endl;
    cout <<"       *                             *"      <<endl;
    cout <<"        *****************************"      <<endl<<endl<<endl;

    cout <<"1- Jugar"<<endl;
    cout <<"2- Estadisticas"<<endl;
    cout <<"3- Creditos"<<endl;
    cout <<"4- Salir"<<endl;




    cout <<"Ingrese una opcion: "<<endl;
    cin >>opcion;

    while (opcion != 4)
    {
        switch(opcion)
        {
        case 1:
            pilas = 3;
            system("cls");
            cargarDatos(Usuario);
            rlutil::cls();
            while(pilas > 0){

            matrizCaracteres[0][1] = 0;

            mostrarJuego(matrizCaracteres,Usuario,pilas);
            comienzoJuego(matrizCaracteres,matrizNumeros,pilas);

            }



        {


        } break;
        case 2:
        {} break;
        case 3:
        {} break;
        case 4: {

        }break;

        }

        cout <<"Ingrese una opcion: "<<endl;
        cin >>opcion;
    }


    return 0;
}
