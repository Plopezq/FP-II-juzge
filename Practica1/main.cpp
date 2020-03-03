#include "juego.cpp" //Que este incluye juego.h y ese incluye mina.h
#include<conio.h>
#include<stdio.h>
using namespace std;

int main() {
	system("cls");
	
	
	return 0;
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}


tTecla leerTecla{
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

bool hacerMovimiento(tJuego& juego, tTecla tecla) {


}




