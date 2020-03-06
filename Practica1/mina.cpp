#include<Windows.h>
#include "mina.h"
using namespace std;

void cargar_Mina(ifstream& fichero, tMina& mina){
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
				//colorFondo(15);
				cout << "@";
				//colorFondo(0);
				break;
			case MURO:
				//colorFondo(0);
				cout << "X";
				//colorFondo(15);
				break;
			case MINERO:
				//colorFondo(15)
				cout << "M";
				//colorFondo(15)
				break;
			case TIERRA:
				//colorFondo(15);
				cout << ".";
				//colorFondo(15);
				break;
			case DINAMITA:
				//colorFondo(15);
				cout << "D";
				//colorFondo(15);
				break;
			case GEMA:
				//colorFondo(15);
				cout << "G";
				//colorFondo(15)
				break;
			case SALIDA:
				//colorFondo(15);
				cout << "S";
				//colorFondo(15);
				break;
			case LIBRE:
				//colorFondo(15);
				cout << " ";
				//colorFondo(15);
				break;
			}
		}
		cout << endl;
	}
}
void dibujar1_3(const tMina& mina) {
	//Declarar aqui el array de chars y el de colores
	tPlanoCaracteres caracteres;
	tPlanoColores colores;
	for (int i = 0; i < MAX * 3; i++) {
		for (int j = 0; j < MAX * 3; j++) {
			dibuja3x3(mina.planoMina[i][j], caracteres, colores, i, j);
		}
	}
	tPlanoColores colores;
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			dibuja3x3(mina.planoMina[i][j],);
		}
		cout << endl;
	}
}
void dibuja3x3(tCasilla casilla, tPlanoCaracteres caracteres, tPlanoColores colores, int i, int j) {
	for (int w = 0; w < 3; w++) {
		for (int s = 0; s < 3; s++) {
			switch (casilla)
			{
			case PIEDRA:
				caracteres[i + w][j + s];
				break;
			case MURO:

				break;
			case MINERO:

				break;
			case TIERRA:

				break;
			case DINAMITA:

				break;
			case GEMA:

				break;
			case SALIDA:

				break;
			case LIBRE:

				break;
			}
		}
	}
}
void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}