
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
	bool final = mostrarMenu(juego);
	//Si quiere jugar, cargp juego, sino salgo (ABANDONO)
	if (!final) {
		cargar_juego(juego, juego.nivel);
	}
	else {
		juego.estadoMinero = ABANDONO;
	}
	while (juego.estadoMinero == EXPLORANDO && !final) {
		//system("cls");
		if (juego.opcionMov == 1) { //Introduce por TECLADO
			dibujar(juego);
			jugarTeclado(juego);
		}
		else if (juego.opcionMov == 2) { //Introduce por FICHERO
			ifstream movimientos;
			string aux = "";
			cout << "Introduce el nombre del fichero para los movimientos: " << endl;
			cin >> aux;
			movimientos.open(aux);
			if (movimientos.is_open()) {//Se ha podido abrir
				while (juego.estadoMinero == EXPLORANDO) {
					//system("cls");
					jugarFichero(juego, movimientos);
					dibujar(juego);
				}
			}
			else {
				cout << "No se ha podido abrir el fichero " << endl;
			}
			movimientos.close();
		}

		if (juego.estadoMinero != EXPLORANDO) { //Ya acabo de jugar
			if (juego.estadoMinero == EXITO) {
				if (juego.nivel < NUM_NIVELES) { //Si todavia quedan niveles...
					final = mostrarMenuNivel(juego);
					if (!final) { //Si quiere pasar al nivel siguiente
						final = mostrarMenu(juego);
						if (!final) { //Quiere seguir jugando
							juego.estadoMinero = EXPLORANDO;
						}
						else { //No quiere jugar más, pulsa salir
							juego.estadoMinero = ABANDONO;
						}
					}
				}
			}
			if (juego.estadoMinero == EXPLORANDO) { //Aqui solo entrara si puede seguir jugando
				cargar_juego(juego, juego.nivel);
			}
		}
	}
	if (juego.estadoMinero == ABANDONO) {
		cout << "HAS ABANDONADO, HASTA LA PROXIMA" << endl;
	}
	if (juego.estadoMinero == FRACASO) {
		cout << "HAS MUERTO, GRACIAS POR JUGAR, HASTA LA PROXIMA" << endl;
	}
	if (juego.nivel == NUM_NIVELES) {
		cout << endl;
		cout << "JUEGO COMPLETADO CON EXITO !!! " << endl;
	}
	return 0;
}
bool mostrarMenu(tJuego& juego) {
	bool salir = false;
	system("cls");
	int opt;
	cout << "1. Jugar partida a escala 1:1. " << endl;
	cout << "2. Jugar partida a escala 1:3. " << endl;
	cout << "3. Salir " << endl;
	cout << "Introduce una opcion:  " << endl;
	cin >> opt;
	if (opt == 3) { salir = true; }

	if (!salir){ //SI NO SALE, muestro el siguiente menu
		juego.escalaJuego = opt;
		system("cls");
		int opt2 = 0;
		cout << "1. Introducir movimientos por teclado. " << endl;
		cout << "2. Introducir movimientos por fichero. " << endl;
		cout << "0. Salir " << endl;
		cout << endl;
		cout << "Introduce una opcion:  " << endl;
		cin >> opt2;

		if (opt2 == 1) {
			juego.opcionMov = 1;
		}
		else if (opt2 == 2) {
			juego.opcionMov = 2;
		}
		else if (opt2 == 0) {
			salir = true;
		}
	}
	return salir;
}
bool mostrarMenuNivel(tJuego& juego) {
	system("cls");
	cout << "NIVEL COMPLETADO!!" << endl;
	cout << endl;
	bool salir = false;
	int opt = 0;
	cout << "1. Jugar siguiente nivel" << endl;
	cout << "0. Salir " << endl;
	cout << endl;
	cout << "Introduce una opcion:  " << endl;
	cin >> opt;
	if (opt == 1 && opt <= NUM_NIVELES) {
		juego.nivel++;
		salir = false;
	}
	else if (opt == 0) {		
		salir = true;
	}
	return salir;
}








