#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include <conio.h>

#include "mina.cpp"
#include "juego.h"
using namespace std;


//FUNCIONES
void colorFondo(int color) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 15 | (color << 4));
}
bool cargar_juego(tJuego& juego, int nivel) {
	
	return false;
}
bool hacerMovimiento(tJuego& juego, tTecla tecla) {
	
	return false;
}
void dibujar(const tJuego& juego) {

}

tTecla leerTecla() {
	tTecla tecla = ARRIBA;
	int dir;
	cin.sync();
	dir = _getch(); // dir: tipo int
	if (dir == 0xe0) {
		dir = _getch();
		// ...

	   // Si aquí dir es 27, es la tecla Esc
		   /*
			   Dirección de las flechas
			   arriba 72
			   abajo 80
			   derecha	77
			   izquierda 75
		   */
	}
	return tecla;
}
