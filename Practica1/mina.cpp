#include "mina.h"
using namespace std;

void cargar_Mina(ifstream& fichero, tMina& mina){
	//Supongo que el ifstream ya est� abierto y cargado el nivel correcto
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
				cout << "@";
				break;
			case MURO:
				cout << "X";
				break;
			case MINERO:
				cout << "M";
				break;
			case TIERRA:
				cout << ".";
				break;
			case DINAMITA:
				cout << "D";
				break;
			case GEMA:
				cout << "G";
				break;
			case SALIDA:
				cout << "S";
				break;
			case LIBRE:
				cout << " ";
				break;
			}

		}
		cout << endl;
	}
}
void dibujar1_3(const tMina& mina) {
	for (int i = 0; i < mina.nFilas; i++) {
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < mina.nColumnas; j++) {
				switch (mina.planoMina[i][j])
				{
				case PIEDRA:

					cout << "@@@";
					break;
				case MURO:
					cout << "XXX";
					break;
				case MINERO:
					cout << "MMM";
					break;
				case TIERRA:
					cout << "...";
					break;
				case DINAMITA:
					cout << "DDD";
					break;
				case GEMA:
					cout << "GGG";
					break;
				case SALIDA:
					cout << "SSS";
					break;
				case LIBRE:
					cout << "   ";
					break;
				}
				
			}
			cout << endl;
		}
			
	}
}
void dibuja3x3(tCasilla casilla, tPlanoCaracteres caracteres, tPlanoColores colores, int i, int j) {
	for (int w = 0; w < MAX*3; w++)
	{
		for (int k = 0; k < MAX*3; k++)
		{

		}
	}
}