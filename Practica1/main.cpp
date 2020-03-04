
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

int main() {
	tJuego juego; //Un juego para toda la ejecucion

	cargar_juego(juego, 3); //FUNCIONA
	//dibujar1_1(juego.mina);
	dibujar1_3(juego.mina);



	return 0;
}

void mostrarMenu() {
	int opt;

	cout << "1. Jugar partida a escala 1:1. " << endl;
	cout << "2. Jugar partida a escala 1:3. " << endl;
	cout << "0. Salir " << endl;



}









