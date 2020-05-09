
#include<conio.h>
#include<stdio.h>

#include "puntuaciones.h"
using namespace std;

bool mostrarMenu(tJuego& juego);
bool mostrarMenuNivel(tJuego& juego);


int main() {
	//Creo el juego y inicializo el array
	tJuego juego;
	tPuntuaciones marcador;
	inicializar_marcador(marcador);
	cargar_marcador(marcador);
	ordenarNombre(marcador); //Ordena jugadores por nombre
	//int pos = 0;
	//string nombre = "Persona4";
	//buscar(nombre, marcador, pos);
	for (int i = 0; i < marcador.num_jugadores; i++) { //Ordena los niveles de todos los jugadores
		ordenarNivel(marcador, i);
	}
	string aux = "pablo";

	insertar(marcador, aux, 3);

	//mostrar_minas_usuario(marcador, 2);
	//mostrar_alfabetico(marcador);
	mostrar_datos_usuario(marcador);

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			juego.mina.planoMina[i][j] = VACIO;
		}
	}
	bool final = mostrarMenu(juego);
	//Si quiere jugar, cargo juego, sino salgo (ABANDONO) y non entro en el while
	if (!final) {
		cargar_juego(juego, juego.nivel);
	}
	else {
		juego.estadoMinero = ABANDONO;
	}
	while (juego.estadoMinero == EXPLORANDO && !final) {
		dibujar(juego);
		jugar(juego);
		//dibujar(juego);
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
	int opt = 9;
	int opt2 = 9;
	while (opt != 1 && opt != 2 && opt != 3) { //Para evitar valores no deseados
		system("cls");
		cout << "1. Jugar partida a escala 1:1. " << endl;
		cout << "2. Jugar partida a escala 1:3. " << endl;
		cout << "3. Salir " << endl;
		cout << "Introduce una opcion:  " << endl;
		cin >> opt;
	}
	while (opt2 != 1 && opt2 != 2 && opt2 != 0 && !salir) { //Para evitar valores no deseados
		if (opt == 3) { salir = true; }
		if (!salir) { //SI NO SALE, muestro el siguiente menu
			juego.escalaJuego = opt;
			system("cls");
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