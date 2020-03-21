#include<stdio.h>
#include<iostream>
#include <conio.h>
#include <string>

#include "juego.h"
using namespace std;


//Vector de direcciones, que coincide con las del enumerado
// ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA} tTecla;
int tdirs4[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ejemploArryaBidimensional[2][3] = { {1,2,3},{7,8,9} };
//FUNCIONES
void cargar_juego(tJuego& juego, std::istream& input) {
	//bool cargado = false;
	//Inicializo el juego
	juego.contGemas = 0;
	juego.contMov = 0;
	//juego.contTNT = 0;
	/**************Leo la mina***************/
	//string aux = to_string(nivel);
	//aux += ".in";
	//ifstream archivo;
	//input.open(aux);
		cargar_mina(input, juego.mina);
}
void dibujar(const tJuego& juego) {
	//Visualiza los contadores y tambien llama al dibujar mina
	// Manda dibujar el plano de la mina a la escala que tiene guardada en las opciones del juego
	for (int i = 0; i < juego.mina.nFilas; i++) {
		for (int j = 0; j < juego.mina.nColumnas; j++) {
			cout << getChar(juego.mina.planoMina[i][j]);
		}
		cout << endl;
	}
}
/*
tTecla leerTecla() {
	tTecla tecla = ARRIBA;
	int dir;
	cin.sync();
	dir = _getch(); // dir: tipo int
	if (dir == 0xe0) { //TECLA ESPECIAL
		dir = _getch();
		switch (dir) {
		case 72: //ARRIBA
			tecla = ARRIBA;
			break;
		case 80: //ABAJO
			tecla = ABAJO;
			break;
		case 77: //DERECHA 
			tecla = DCHA;
			break;
		case 75: //IZQUIERDA
			tecla = IZDA;
			break;
		}
	}
	else if (dir == 27){// Tecla ESC
		tecla = SALIR;

	}
	return tecla;
}*/
istream& operator<<(std::istream& movimientos, tTecla& tecla)
{ /******LECTURA DE LA TECLA DE FICHERO, NO DE USUARIO******/
	//lee del ﬂujo de entrada movimientos un movimiento y devuelve el valor del tipo enumerado correspondiente
	char dir;
	movimientos.get(dir);
	//cin.sync();
	//dir = _getch(); // dir: tipo int
	//if (dir == 0xe0) { //TECLA ESPECIAL
		//dir = _getch();
	switch (dir) {
	case 'A': //ARRIBA
		tecla = ARRIBA;
		break;
	case 'Z': //ABAJO
		tecla = ABAJO;
		break;
	case 'M': //DERECHA 
		tecla = DCHA;
		break;
	case 'N': //IZQUIERDA
		tecla = IZDA;
		break;
	case 'S': //FIN DE MOVIMIENTOS, EL MINERO SE SIENTA
		tecla = SALIR;
		break;
	default:
		tecla = SALIR;
	}
	return movimientos;
}

void leerMovimiento(tJuego& juego, tTecla& tecla, std::istream& movimientos)
{
	/* lee un movimiento del ﬁchero con la sobrecarga del operador. 
		Si el minero selecciona el movimiento SALIR pondra 
		el estado del minero en situacion de ABANDONO.
	*/
	movimientos << tecla;
	if (tecla == SALIR) {
		juego.estadoMinero = ABANDONO;
	}
}
void realizarMovimiento(tJuego& juego, tTecla& mov) {
	/*se encarga de realizar el movimiento indicado en el parametro mov modiﬁcando
	el plano de la mina y la posicion del minero en la mina.
	Para obtener la casilla de destino se ayudara del vector tdirs4,
	de forma que no tiene que diferenciar el movimiento realizado.
	*/
	//Vector de direcciones, que coincide con las del enumerado
	//					 ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA} tTecla;
	int tdirs4[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
	//Posiciones siguientes donde quiere ir: X e Y
	//int aux = 1; 
	int aux = mov;
	int x = juego.mina.posFila + tdirs4[aux][0];
	int y = juego.mina.posColumna + tdirs4[aux][1];

	//HASTA AQUI FUNCIONA BIEN, depurando
	if (dentroPlano(juego.mina, x, y) )  { //Si el minero se quiere mover dentro del pano.
		//typedef enum { LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA } tElemento;
		switch (juego.mina.planoMina[x][y]) {
		case LIBRE:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos libre donde estaba antes el miner
			//Actualizamos la posicion del minero
			juego.mina.posFila = x;
			juego.mina.posColumna = y;
			break;
		case TIERRA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			//Actualizamos la posicion del minero
			juego.mina.posFila = x;
			juego.mina.posColumna = y;
			break;
		case GEMA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			//Actualizamos la posicion del minero
			juego.mina.posFila = x;
			juego.mina.posColumna = y;		
			//Actualizar el contador de gemas
			break;
		case PIEDRA:
			//TODO
			break;
		case MURO:
			//TODO
			break;
		case SALIDA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			//Actualizamos la posicion del minero
			juego.mina.posFila = x;
			juego.mina.posColumna = y;
			//Actualizar el contador de gemas
			break;
		case MINERO:
			//TODO
			break;
		case DINAMITA:
			//TODO
			break;
		}
	}

}
void jugar(tJuego& juego, std::istream& entrada, std::istream& movimientos) {
	/* comienza cargando los datos de la mina, a continuacion va leyendo los movimientos 
		y para cada uno modiﬁca la mina de acuerdo con el movimiento. 
		Los movimientos no los almacena, los trata segun los va leyendo. 
		La funcion debe recibir los dos ﬂujos de entrada, porque en fases posteriores 
		del desarrollo de la practica sera necesario tenerlos diferenciados.
	*/
	cargar_juego(juego, entrada); //Carga la mina e inicializa TODO el juego con sus contadores, etc...
	
	tTecla tecla = ARRIBA;

	while (tecla != SALIR) {
		leerMovimiento(juego, tecla, movimientos); //Modifica el valor de tecla
		realizarMovimiento(juego, tecla);
	}

}

