#include "mina.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

void cargar_Mina(ifstream& fichero, tMina& mina){
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
char getChar(tElemento ele) { //tElemento = tCasilla
	char aux = ' ';
	switch (ele)
	{
	case PIEDRA:
		aux = '@';
		break;
	case MURO:
		aux = 'X';
		break;
	case MINERO:
		aux = 'M';
		break;
	case TIERRA:
		aux = '.';
		break;
	case GEMA:
		aux = 'G';
		break;
	case SALIDA:
		aux = 'S';
		break;
	case LIBRE:
		aux = ' ';
		break;

	case DINAMITA:
		aux = 'T';
		break;
	}
	return aux;
}
void dibujar1_1(const tMina& mina){
	for (int i = 0; i < mina.nFilas; i++ ) {
		for (int j = 0; j < mina.nColumnas; j++) {
			switch (mina.planoMina[i][j])
			{
			case PIEDRA:
				colorFondo(4);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case MURO:
				colorFondo(4);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case MINERO:
				colorFondo(8);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case TIERRA:
				colorFondo(4);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case DINAMITA:
				colorFondo(6);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case GEMA:
				colorFondo(10);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case SALIDA:
				colorFondo(1);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
				colorFondo(0);
				break;
			case LIBRE:
				colorFondo(4);
				cout << setw(2) << getChar(mina.planoMina[i][j]);
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
	cout << endl;
}
void dibuja3x3(tElemento casilla, tPlanoCaracteres& caracteres, tPlanoColores& colores, int i, int j) {
	//AQUI NO DEBO MODIFICAR i y j, porque sino altero la lectura en la función anterior.
	for (int s = i * 3; s < (i * 3) + 3; s++) {
		for (int w = j * 3; w < (j * 3) + 3; w++) {
			switch (casilla)
			{
			case PIEDRA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case MURO:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case MINERO:
				colores.planoColores[s][w] = 8;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case TIERRA:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case DINAMITA:
				colores.planoColores[s][w] = 6;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case GEMA:
				colores.planoColores[s][w] = 10;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case SALIDA:
				colores.planoColores[s][w] = 1;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			case LIBRE:
				colores.planoColores[s][w] = 4;
				caracteres.planoCaracteres[s][w] = getChar(casilla);
				break;
			}
		}
	}
}
ostream& operator<<(ostream& out, tElemento const& e)
{
	out << getChar(e);
	return out;
}
void colorFondo(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);     
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
bool dentroPlano(tMina const& mina, int x, int y) { //Comprueba si una posicion esta dentro del plano
	bool dentro = false;
	if (x >= 0 && x < mina.nFilas && y >= 0 && y < mina.nColumnas) {
		dentro = true;
	}
	return dentro;
}

