#include "mina.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

void cargar_Mina(ifstream& fichero, tMina& mina){
	//Lee el plano de la mina y lo guarda en memoria, ADEMÁS actualiza la posicion del minero en la mina
	//Existe la opcion de crear una funcion que transforme un caracter en un tipo
	//enumerado y lo devuelva
	//Supongo que el ifstream ya está abierto y cargado el nivel correcto
	char c;
		fichero >> mina.nFilas >> mina.nColumnas; //Guardo las filas y columnas de la mina
		fichero.get(c); // Para leer el \n 
		for (int i = 0; i < mina.nFilas; i++) { //Leo las filas
			for (int j = 0; j < mina.nColumnas; j++) { //Leo las columnas
				fichero.get(c); 
				switch (c) {
				case 'T':
					mina.planoMina[i][j] = TIERRA;
					break;
				case 'G':
					mina.planoMina[i][j] = GEMA;
					break;
				case 'P':
					mina.planoMina[i][j] = PIEDRA;
					break;
				case 'M':
					mina.planoMina[i][j] = MURO;
					break;
				case 'S':
					mina.planoMina[i][j] = SALIDA;
					break;
				case 'J':
					mina.planoMina[i][j] = MINERO;
					mina.posFila = i;
					mina.posColumna = j;
					break;
				case ' ':
					mina.planoMina[i][j] = LIBRE;
					break;
				}
			}
			fichero.get(c); // Para leer el \n 
		}
}
void dibujar1_1(const tMina& mina){
	system("cls");
	for (int i = 0; i < mina.nFilas; i++ ) {
		for (int j = 0; j < mina.nColumnas; j++) {
			switch (mina.planoMina[i][j])
			{
			case PIEDRA:
				colorFondo(4);
				cout << "@";
				colorFondo(0);
				break;
			case MURO:
				colorFondo(4);
				cout << "X";
				colorFondo(0);
				break;
			case MINERO:
				colorFondo(8);
				cout << "M";
				colorFondo(0);
				break;
			case TIERRA:
				colorFondo(4);
				cout << ".";
				colorFondo(0);
				break;
			case DINAMITA:
				colorFondo(4);
				cout << "D";
				colorFondo(0);
				break;
			case GEMA:
				colorFondo(10);
				cout << "G";
				colorFondo(0);
				break;
			case SALIDA:
				colorFondo(4);
				cout << "S";
				colorFondo(0);
				break;
			case LIBRE:
				colorFondo(4);
				cout << " ";
				colorFondo(0);
				break;
			}

		}
		cout << endl;
	}
}
void dibujar1_3(const tMina& mina) {
	//MATRICES AUXILIARESs
	tPlanoCaracteres caracteres; //Guardamos los caracteres en tamaño 3x3
	tPlanoColores coloresMatriz3x3; //Guardamos los colores en tamaño 3x3

	//Inicializamos las dos matrices auxiliares, la de caracteres y la de colores
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			dibuja3x3(mina.planoMina[i][j], caracteres, coloresMatriz3x3, i, j);
		}
	}

	//Pintamos, utilzando las 2 matrices auxiliares
	for (int i = 0; i < mina.nFilas * 3; i++) {
		for (int j = 0; j < mina.nColumnas * 3; j++) {
			colorFondo(coloresMatriz3x3.planoColores[i][j]);
			cout << setw(2) << caracteres.planoCaracteres[i][j];
			colorFondo(0);
		}
		cout << endl;
	}
}
void dibuja3x3(tCasilla casilla, tPlanoCaracteres& caracteres, tPlanoColores& colores, int i, int j) {
	
	//AQUI NO DEBO MODIFICAR i y j, porque sino altero la lectura en la función anterior.
	for (int s = i * 3; s < (i * 3) + 3; s++) {
		for (int w = j * 3; w < (j * 3) + 3; w++) {
			switch (casilla)
			{
			case PIEDRA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = '@';
				break;
			case MURO:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = 'X';
				break;
			case MINERO:
				colores.planoColores[s][w] = 8;
				caracteres.planoCaracteres[s][w] = 'M';
				break;
			case TIERRA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = '.';
				break;
			case DINAMITA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = 'D';
				break;
			case GEMA:
				colores.planoColores[s][w] = 10;
				caracteres.planoCaracteres[s][w] = 'G';
				break;
			case SALIDA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = 'S';
				break;
			case LIBRE:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = ' ';
				break;
			}
		}
	}
}
void colorFondo(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);     
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

