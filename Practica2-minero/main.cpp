
#include<conio.h>
#include<stdio.h>

#include "puntuaciones.h"
using namespace std;

bool mostrarMenu(tJuego& juego);
bool mostrarMenuNivel(tJuego& juego, tPuntuaciones marcador);
bool menuv2(tJuego& juego, tPuntuaciones& marcador);

int main() {
	//Creo el juego y inicializo el array
	tJuego juego;
	tPuntuaciones marcador;
	inicializar_marcador(marcador);
	cargar_marcador(marcador);
	//ordenarNombre(marcador); //Ordena jugadores por nombre, se or
	ordenarNiveles(marcador);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			juego.mina.planoMina[i][j] = VACIO;
		}
	}
	bool final = menuv2(juego, marcador);
	if (!final) final = mostrarMenu(juego);
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
			if (juego.estadoMinero == EXITO) { //Ha superado el nivel
				guardar_marcador(marcador, juego);
				mostrar_datos_usuario(marcador);
				final = mostrarMenuNivel(juego, marcador);
				if (!final) { //Si quiere seguir jugando
					final = mostrarMenu(juego);
					if (!final) { //Quiere seguir jugando
						juego.estadoMinero = EXPLORANDO;
					}
					else { //No quiere jugar más, pulsa salir
						juego.estadoMinero = ABANDONO;
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
bool mostrarMenuNivel(tJuego& juego, tPuntuaciones marcador) {
	bool salir = false;
	int opt = 0;

	cout << juego.jugador << ", ¿Que mina quieres explorar? " << endl;
	cout << "Introduce un número entre 1 y 5 para explorar una mina y 0 para salir " << endl;
	cin >> opt;
	if (opt > 1 && opt <= NUM_NIVELES) {
		juego.nivel = opt;
		salir = false;
	}
	else if (opt == 0) {		
		salir = true;
	}
	return salir;
}

bool menuv2(tJuego& juego, tPuntuaciones& marcador){
	bool salir = false;

	string nombreJug = "";

	cout << "SEGUNDA PARTE DE LA PRATICA DEL MINERO " << endl;
	cout << "\t\t Introduce tu nombre de jugador/a:  ";
	cin >> nombreJug;

	juego.jugador = nombreJug;

	int posicion = -1;

	if (buscar(nombreJug, marcador, posicion)) {
		//Existe el jugador
		cout << "\t Ya estas registrado/a. " << endl;
		cout << "\t\t\t" << "Mira las minas que has recorrido ordenadas por nivel " << endl << endl; //Pasar esto al main
		mostrar_minas_usuario(marcador, posicion);
	}
	else {
		//No existe el jugador
		cout << "\t Eres nuevo: " << nombreJug << endl;
		cout << "\t\t\t" << "Mira las puntuaciones de otros jugadores: " << endl << endl; //Pasar al main
		mostrar_alfabetico(marcador);
		insertar(marcador, nombreJug, marcador.num_jugadores );

	}
	cout << nombreJug << "¿Que mina quieres explorar?" << endl;
	cout << "Introduce un número entre 1 y 5 para explorar una mina y 0 para salir" << endl;
	int nivel = -1;
	cin >> nivel;
	if (nivel == 0) {//Quiere salir
		salir = true;
	}
	else {// Quiere jugar
		juego.nivel = nivel;
	}

return salir;
}