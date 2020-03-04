
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

int main() {
	tJuego juego; //Un juego para toda la ejecucion
	cargar_juego(juego, 1); //FUNCIONA
	dibujar1_1(juego.mina);


	return 0;
}

void mostrarMenu() {

	cout << "1. Jugar partida a escala 1:1. " << endl;
	cout << "2. Jugar partida a escala 1:3. " << endl;
	cout << "0. Salir " << endl;


}









