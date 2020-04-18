
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

bool mostrarMenu(tJuego& juego);
bool mostrarMenuNivel(tJuego& juego);
const int NUM_NIVELES = 4;
int main() {

	//Creo el juego y inicializo el array
	tJuego juego;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			juego.mina.planoMina[i][j] = VACIO;
		}
	}

	//Si quiere jugar, cargp juego, sino salgo (ABANDONO)
	if (mostrarMenu(juego)) {
		cargar_juego(juego, juego.nivel);
	}
	else {
		juego.estadoMinero = ABANDONO;
	}

	while (juego.estadoMinero == EXPLORANDO) {
		system("cls");
		if (juego.opcionMov == 1) { //Introduce por teclado
			if (juego.escalaJuego == 1) {
				dibujar1_1(juego.mina);
			}
			else if (juego.escalaJuego == 2) {
				dibujar1_3(juego.mina);
			}
			cout << "Gemas totales recogidas: " << juego.contGemas << endl;
			cout << "Numero de movimientos: " << juego.contMov << endl;
			cout << "Dinamitas usadas: " << juego.contTNT << endl;
			jugarTeclado(juego);
		}
		else if (juego.opcionMov == 2) { //Introduce por fichero
				ifstream movimientos;
				string aux = "";
				cout << "Introduce el nombre del fichero para los movimientos: " << endl;
				cin >> aux;
				movimientos.open(aux);
			if (movimientos.is_open()) {//Se ha podido abrir
				while (juego.estadoMinero == EXPLORANDO) {
					system("cls");
					jugarFichero(juego, movimientos);
					if (juego.escalaJuego == 1) {
						dibujar1_1(juego.mina);
					}
					else if (juego.escalaJuego == 2) {
						dibujar1_3(juego.mina);
					}
					cout << "Gemas totales recogidas: " << juego.contGemas << endl;
					cout << "Numero de movimientos: " << juego.contMov << endl;
					cout << "Dinamitas usadas: " << juego.contTNT << endl;
				}
			}
			else {
				cout << "No se ha podido abrir el fichero " << endl;
			}
				movimientos.close();
		}

		if (juego.estadoMinero != EXPLORANDO) { 
			if (juego.estadoMinero == EXITO) {
				system("cls");
				cout << "NIVEL COMPLETADO!!" << endl;
				cout << endl;
				if (juego.nivel < NUM_NIVELES) {
					if (mostrarMenuNivel(juego)) { //Si quiere pasar al nivel siguiente
						juego.estadoMinero = EXPLORANDO;
						//Si quiere seguir jugando, muestro el menu, sino no
						if (!mostrarMenu(juego)) { //No quiere jugar más, pulsa salir
							juego.estadoMinero = ABANDONO;
						}
					}
					else { //No quiere nivel siguiente, pulsa salir
						juego.estadoMinero = ABANDONO;
					}


				}
				if (juego.estadoMinero == EXPLORANDO) { //Aqui solo entrara si hay más niveles disponibles
					cargar_juego(juego, juego.nivel);
				}

			}
			if (juego.estadoMinero == ABANDONO) {
				cout << "HAS ABANDONADO, HASTA LA PROXIMA" << endl;
			}
			if (juego.estadoMinero == FRACASO) {
				cout << "HAS MUERTO, GRACIAS POR JUGAR, HASTA LA PROXIMA" << endl;
			}
		}
	}
	if (juego.nivel == NUM_NIVELES) {
		cout << endl;
		cout << "JUEGO COMPLETADO CON EXITO !!! " << endl;
	}
	return 0;
}

bool mostrarMenu(tJuego& juego) {
	system("cls");
	int opt;
	cout << "1. Jugar partida a escala 1:1. " << endl;
	cout << "2. Jugar partida a escala 1:3. " << endl;
	cout << "3. Salir " << endl;
	cout << "Introduce una opción:  " << endl;
	cin >> opt;

	if (opt != 3){ //NO SALE
		juego.escalaJuego = opt;
		system("cls");
		int opt2 = 0;
		cout << "1. Introducir movimientos por teclado. " << endl;
		cout << "2. Introducir movimientos por fichero. " << endl;
		cout << "0. Salir " << endl;
		cout << endl;
		cout << "Introduce una opción:  " << endl;
		cin >> opt2;

		if (opt2 == 1) {
			juego.opcionMov = 1;
		}
		else if (opt2 == 2) {
			juego.opcionMov = 2;
		}
		else if (opt2 == 0) {
			
			return false;
		}
		return true;
	}
	else {
		return false;
	}


}

bool mostrarMenuNivel(tJuego& juego) {
	
	int opt = 0;
	cout << "1. Jugar siguiente nivel" << endl;
	cout << "0. Salir " << endl;
	cout << endl;
	cout << "Introduce una opción:  " << endl;
	cin >> opt;
	if (opt == 1 && opt <= NUM_NIVELES) {
		juego.nivel++;
		return true;
	}
	else if (opt == 0) {		
		return false;
	}
}








