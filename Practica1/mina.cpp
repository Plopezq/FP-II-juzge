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
	tPlanoCaracteres caracteres;
	tPlanoColores coloresMatriz3x3;
	//Inicializamos las dos matrices auxiliares;
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			dibuja3x3(mina.planoMina[i][j], caracteres, coloresMatriz3x3, i, j);
		}
	}
	for (int i = 0; i < MAX * 3; i++) {
		for (int j = 0; j < MAX * 3; j++) {
			cout << caracteres.planoCaracteres[i][j];
		}
	}
}
void dibuja3x3(tCasilla casilla, tPlanoCaracteres& caracteres, tPlanoColores& colores, int& i, int& j) {
	int auxI = i * 3;
	int auxJ = j * 3;
	switch (casilla)
	{
	case PIEDRA:
		for (int x = i * 3;  x < x+3; x++) {
			for (int w = j * 3; w < w+3 ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case MURO:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case MINERO:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case TIERRA:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case DINAMITA:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case GEMA:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case SALIDA:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[x][w] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	case LIBRE:
		for (int x = i; x < auxI; x++) {
			for (int w = j; w < auxJ; w++) {
				caracteres.planoCaracteres[i][j] = 'P';
				//colores.planoColores[w][k] = 13;
			}
		}
		break;
	}

}