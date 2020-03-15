
#include<conio.h>
#include<stdio.h>

#include "juego.h"
using namespace std;

void mostrarMenu();


int main() {

	//mostrarMenu();
	tJuego juego; //Un juego para toda la ejecucion
	
	cargar_juego(juego, 2); //FUNCIONA
	dibujar1_1(juego.mina);
	dibujar1_3(juego.mina);


	return 0;
}

void mostrarMenu() {
	int opt;
	cout << "Elige la opcion que prefieras" << endl;
	cin >> opt;
	if (opt == 1)
	{

	}
	else if (opt == 2)
	{

	}
	else if (opt == 0)
	{

	}
}









