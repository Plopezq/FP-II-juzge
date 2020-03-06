
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

//PROTOTIPOS
void mostrarMenu();

int main() {

	mostrarMenu();
	tJuego juego; //Un juego para toda la ejecucion
	
	cargar_juego(juego,1); //FUNCIONA
	dibujar1_1(juego.mina);
	//dibujar1_3(juego.mina);
	
   

	return 0;
}

void mostrarMenu() {
	int opt;
	cout << "Elige la opcion que prefieras" << endl;
	cin >> opt;
	switch (opt) {
	case 1:
		cout << "1. Jugar partida a escala 1:1. " << endl;
		break;
	case 2:
		cout << "2. Jugar partida a escala 1:3. " << endl;
		break;
	case 0:
		cout << "0. Salir " << endl;
		break;
	}
}








