#include "mina.h"


using namespace std;

void cargar_mina(istream& fichero, tMina& mina) {
	//Lee el plano de la mina y lo guarda en memoria, ADEMÁS actualiza la posicion del minero en la mina
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
			case '-':
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
		aux = '-';
		break;
	}
	return aux;
}
void dibujar1_1(const tMina& mina) {
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			cout << getChar( mina.planoMina[i][j] );
		}
		cout << endl;
	}
	cout << endl;
}
void dibujar3_1(const tMina& mina) {
	//MATRICES AUXILIARESs
	tPlanoCaracteres caracteres;//Guardamos los caracteres en tamaño 3x3

	//Inicializamos las dos matrices auxiliares, la de caracteres y la de colores
	for (int i = 0; i < mina.nFilas; i++) {
		for (int j = 0; j < mina.nColumnas; j++) {
			dibuja3x3(mina.planoMina[i][j], caracteres, i, j);
		}
	}

	//Pintamos, utilzando las 2 matrices auxiliares
	for (int i = 0; i < mina.nFilas * 3; i++) {
		for (int j = 0; j < mina.nColumnas * 3; j++) {
			cout << caracteres.planoCaracteres[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void dibuja3x3(tElemento casilla, tPlanoCaracteres& caracteres, int i, int j) {
	//AQUI NO DEBO MODIFICAR i y j, porque sino altero la lectura en la función anterior.
	for (int s = i * 3; s < (i * 3) + 3; s++) {
		for (int w = j * 3; w < (j * 3) + 3; w++) {
			caracteres.planoCaracteres[s][w] = getChar(casilla);
		}
	}
}
ostream& operator<<(ostream& out, tElemento const& e)
{
	/* Para escribir los valores del tipo enumerado.
	El operador se sobrecarga para el tipo enumerado, no para la matriz.
	La matriz se muestra con las funciones siguientes. */
	out << getChar(e);
	return out;
}

bool dentroPlano(tMina const& mina, int x, int y) {
	//Comprueba si una posicion esta dentro del plano
	bool dentro = false;
	if (x >= 0 && x < mina.nFilas && y >= 0 && y < mina.nColumnas) {
		dentro = true;
	}
	return dentro;
}

