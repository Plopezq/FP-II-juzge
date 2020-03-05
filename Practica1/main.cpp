
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;
void mostrarMenu() {
	int opt;
	cout << "Elige la opcion que prefieras" << endl;
	cin >> opt;
	if (opt == 1)
	{
		cout << "1. Jugar partida a escala 1:1. " << endl;
	}
	else if (opt == 2)
	{
		cout << "2. Jugar partida a escala 1:3. " << endl;
	}
	else if (opt == 0)
	{
		cout << "0. Salir " << endl;
	}
}
int main() {

	mostrarMenu();
	tJuego juego; //Un juego para toda la ejecucion
	
	cargar_juego(juego, 1); //FUNCIONA
	dibujar1_1(juego.mina);
	//dibujar1_3(juego.mina);
	
   

	return 0;
}











