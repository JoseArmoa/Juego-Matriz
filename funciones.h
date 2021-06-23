#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


//Definiciones
void cargarMatrizNum(int [][6], int); //Genera matriz aleatoria de 6x6 con num enteros.
void cargarMatrizCaract(char [][6],int [][6] ,int ); //Transforma matriz de enteron en caracteres para poder mostrar y modificar.
void cargarDatos (char []); //Carga el nombre del jugador en un vector de caracteres.
void mostrarJuego (char[][6],char [], int &, int); //Muestra la pantalla del Juego.
void vida(int ); //Muestra las vidas disponibles.
void comienzoJuego(char [][6], int [][6], int & ); //Codigo del Juego.
bool validarDatos (char [][6], int, int, int);
//bool validarEcuacion(int [][6], int, int, int);
void cargarDireccion(int, int, int , int&, int&, int&, int&);
void seleccionColor(int &);

#endif // FUNCIONES_H_INCLUDED
