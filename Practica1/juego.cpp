#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include <conio.h>
#include <string>


#include "juego.h"
using namespace std;


//FUNCIONES
bool cargar_juego(tJuego& juego, int nivel) {
	bool cargado = false;
	//Inicializo el juego
	juego.contGemas = 0;
	juego.contMov = 0;
	juego.contTNT = 0;
	//Leo la mina
	string aux = to_string(nivel);
	aux += ".txt";
	ifstream archivo;
	archivo.open(aux);
	if (archivo.is_open()) {
		cargar_Mina(archivo, juego.mina);
		cargado = true;
		archivo.close();
	}
	return cargado;
}
bool hacerMovimiento(tJuego& juego, tTecla tecla) {
	
	return false;
}
void dibujar(const tJuego& juego) {
	//Visualiza los contadores y tambien llama al dibujar mina
}


tTecla leerTecla() {
	tTecla tecla = ARRIBA;
	int dir;
	cin.sync();
	dir = _getch(); // dir: tipo int
	if (dir == 0xe0) {
		dir = _getch();
		// ...

	   // Si aqu� dir es 27, es la tecla Esc
		   /*
			   Direcci�n de las flechas
			   arriba 72
			   abajo 80
			   derecha	77
			   izquierda 75
		   */
	}
	return tecla;
}
