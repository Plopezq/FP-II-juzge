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
				//PONER COLOR
				cout << "@";
				break;
			case MURO:
				//PONER COLOR
				cout << "X";
				break;
			case MINERO:
				//PONER COLOR
				cout << "M";
				break;
			case TIERRA:
				//PONER COLOR
				cout << ".";
				break;
			case DINAMITA:
				//PONER COLOR
				cout << "D";
				break;
			case GEMA:
				//PONER COLOR
				cout << "G";
				break;
			case SALIDA:
				//PONER COLOR
				cout << "S";
				break;
			case LIBRE:
				//PONER COLOR
				cout << " ";
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

	//Inicializamos las dos matrices auxiliares;
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			dibuja3x3(mina.planoMina[i][j], caracteres, coloresMatriz3x3, i, j);
		}
	}
	//Pintamos, utilzando las 2 matrices auxiliares
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << caracteres.planoCaracteres[i][j];
		}
		cout << endl;
	}
}
void dibuja3x3(tCasilla casilla, tPlanoCaracteres& caracteres, tPlanoColores& colores, int i, int j) {
	
	//AQUI NO DEBO MODIFICAR i y j
	for (int s = i * 3; s < (i * 3) + 3; s++) {
		for (int w = j * 3; w < (j * 3) + 3; w++) {
			switch (casilla)
			{
			case PIEDRA:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'P';
				break;
			case MURO:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'M';
				break;
			case MINERO:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'Y';
				break;
			case TIERRA:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'T';
				break;
			case DINAMITA:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'D';
				break;
			case GEMA:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'G';
				break;
			case SALIDA:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'X';
				break;
			case LIBRE:
				//PONER COLOR
				caracteres.planoCaracteres[s][w] = 'L';
				break;
			}
		}
	}
}




