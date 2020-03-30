
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

void mostrarMenu(tJuego& juego);
void mostrarMenu2(tJuego& juego);

int main() {

	tJuego juego;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			juego.mina.planoMina[i][j] = VACIO;
		}
	}
	mostrarMenu(juego);
	mostrarMenu2(juego);        
	cargar_juego(juego, 1);

	while (juego.estadoMinero == EXPLORANDO ) {
		system("cls");
		if (juego.opcionMov == 1) { //Introduce por teclado
			if (juego.escalaJuego == 1) {
				dibujar1_1(juego.mina);
			}
			else if (juego.escalaJuego == 2) {
				dibujar1_3(juego.mina);
			}
			cout << "Gemas: " << juego.contGemas << endl;
			cout << "Movimientos: " << juego.contMov << endl;
			jugarTeclado(juego);
		}
		else if (juego.opcionMov == 2) { //Introduce por fichero

			string aux = "movimientos.txt";
			ifstream movimientos;
	
			movimientos.open(aux);
			if (movimientos.is_open()) {
				jugarFichero(juego, movimientos);
				movimientos.close();
			}


			if (juego.escalaJuego == 1) {
				dibujar1_1(juego.mina);
			}
			else if (juego.escalaJuego == 2) {
				dibujar1_3(juego.mina);
			}
			cout << "Gemas: " << juego.contGemas << endl;
			cout << "Movimientos: " << juego.contMov << endl;
		}
	}
	return 0;
}

void mostrarMenu(tJuego& juego) {
	int opt;
	cout << "1. Jugar partida a escala 1:1. " << endl;
	cout << "2. Jugar partida a escala 1:3. " << endl;
	cout << "0. Salir " << endl;
	cout << "Introduce una opción:  " << endl;
	cin >> opt;
	if (opt == 1) //Escala 1:1
	{
		juego.escalaJuego = 1;
	}
	else if (opt == 2) //Escala 1:3
	{
		juego.escalaJuego = 2;
	}
	else if (opt == 0) //Salir
	{

	}
}

void mostrarMenu2(tJuego& juego) {
	int opt = 0;
	cout << "1. Introducir movimientos por teclado. " << endl;
	cout << "2. Introducir movimientos por fichero. " << endl;
	cout << "0. Salir " << endl;
	cout << endl;
	cout << "Introduce una opción:  " << endl;
	cin >> opt;

	if (opt == 1) {
		juego.opcionMov = 1;
	}
	else if (opt == 2) {
		juego.opcionMov = 2;
	}



}








