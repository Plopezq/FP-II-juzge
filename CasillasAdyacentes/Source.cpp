#include <iostream>
#include <fstream>
#include <iomanip>      // std::setw
using namespace std;

const int MAX_FILAS = 50;
const int MAX_COLUMNAS = 50;
const int incF[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int incC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };


typedef struct {
	int matriz[MAX_FILAS][MAX_COLUMNAS];
	int nfila, ncolumna;
} tMatriz;

bool dentro_matriz(tMatriz m, int x, int y) {
	if (x >= 0 && x < m.nfila && y >= 0 && y < m.ncolumna) {
		return true;
	}
	else {
		return false;
	}
	// Este c�digo es similar a 
	// return (x >= 0 && x < m.nfila && y >= 0 && y < m.ncolumna)
}

int main() {

	tMatriz m;
	// Inicializo la matriz por ejemplo a 4 filas y 5 columnas y a numeros consecutivos
	m.nfila = 4;
	m.ncolumna = 5;
	int elem = 0;
	for (int i = 0; i < m.nfila; i++) {
		for (int j = 0; j < m.ncolumna; j++) {
			m.matriz[i][j] = elem;
			elem++;
		}
	}

	// Visualizo la matriz
	for (int i = 0; i < m.nfila; i++) {
		for (int j = 0; j < m.ncolumna; j++) {
			cout << setw(2) << m.matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	
	// Exploramos las casillas adyacentes a todas las casillas de la matriz--DINAMITA
	for (int i = 0; i < m.nfila; i++) {
		for (int j = 0; j < m.ncolumna; j++) {
			cout << "Exploramos casillas adyacentes a la casilla [" << i << "][" << j << "]: ";
			for (int dir = 0; dir < 8; dir++) {
				if (dentro_matriz(m, i + incF[dir], j + incC[dir])) {
					cout << m.matriz[i + incF[dir]][j + incC[dir]] << " ";
				}
			}
			cout << endl;
		}
	}

	
	// Vamos a explorar dos elementos por cada radial
	cout << "   Exploramos dos coronas " << endl;

	for (int i = 0; i < m.nfila; i++) {
		for (int j = 0; j < m.ncolumna; j++) {
			cout << "Exploramos casillas adyacentes a la casilla [" << i << "][" << j << "]: ";
			for (int dir = 0; dir < 8; dir++) {
				int cont = 1;
				while (dentro_matriz(m, i + (incF[dir] * cont), j + (incC[dir] * cont)) && cont < 3) {
					cout << m.matriz[i + (incF[dir] * cont)][j + (incC[dir] * cont)] << " ";
					cont++;
				}
				cout << "- ";
			}
			cout << endl;
		}
	}

	// Vamos a explorar tres elementos por cada radial
	cout << "   Exploramos tres coronas " << endl;
	for (int i = 0; i < m.nfila; i++) {
		for (int j = 0; j < m.ncolumna; j++) {
			cout << "Exploramos casillas adyacentes a la casilla [" << i << "][" << j << "]: ";
			for (int dir = 0; dir < 8; dir++) {
				int cont = 1;
				while (dentro_matriz(m, i + (incF[dir] * cont), j + (incC[dir] * cont)) && cont < 4) {
					cout << m.matriz[i + (incF[dir] * cont)][j + (incC[dir] * cont)] << " ";
					cont++;
				}
				cout << "- ";
			}
			cout << endl;
		}
	}


	system("pause");

	return 0;
}