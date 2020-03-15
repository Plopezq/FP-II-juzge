#include<stdio.h>
#include<iostream>


using namespace std;

const int MAX = 30;

//Cabeceras
typedef enum { LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA }tCasilla;
typedef tCasilla tPlano[MAX][MAX];
typedef struct {
	tPlano planoMina;
	int nFilas, nColumnas; //Numero de filas y columnas del array bidimensional (de la mina)
	int posFila, posColumna; //Posicion donde se encuentra el minero.
}tMina;



int main() {




	return 0;
}