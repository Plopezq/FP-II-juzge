#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include <conio.h>
#include <string>
#include "juego.h"
using namespace std;
//FUNCIONES
bool cargar_juego(tJuego& juego, int nivel) {
	bool cargado = false; //Inicializo el juego
	juego.contGemas = 0;
	juego.contMov = 0;
	juego.contTNT = 0;
	juego.estadoMinero = EXPLORANDO;
	string aux = to_string(nivel);//Leo la mina
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
void jugar(tJuego& juego) {
	int opt = juego.opcionMov;
	
		if (opt == 1) { // Introduce por TECLADO
			tTecla tecla;
			tecla = leerTecla(juego);
			if (tecla == TNT) {
				ponerTNT(juego); //TODO, jugar con le boolean que devuelve
			}
			if (tecla != SALIR) {
				realizarMovimiento(juego, tecla);
				comprobarCaida(juego);
			}
		}
		else if (opt == 2) {// Introduce por FICHERO
			ifstream movimientos;
			while (!movimientos.is_open() ){
				string aux = "";
				cout << "Introduce el nombre del fichero para los movimientos: " << endl;
				cin >> aux;
				movimientos.open(aux);
				if (!movimientos.is_open()) {
					cout << "Error al abrir el archivo" << endl;
				}
			}
			if (movimientos.is_open()) {//Se ha podido abrir
				while (juego.estadoMinero == EXPLORANDO) {
					//system("cls");
					tTecla tecla = NADA;
					leerMovimiento(juego, tecla, movimientos); //Modifica el valor de tecla
					if (tecla == TNT) {
						ponerTNT(juego); //TODO, jugar con le boolean que devuelve
					}
					if (tecla != SALIR && tecla != NADA) {
						realizarMovimiento(juego, tecla);
						comprobarCaida(juego);
					}
					dibujar(juego);
				}
			}
			movimientos.close();
		}
}
void realizarMovimiento(tJuego& juego, tTecla& mov) {
	//Vector de direcciones, que coincide con las del enumerado
	//					 ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA} tTecla;
	int tdirs4[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
	//Posiciones siguientes donde quiere ir: X e Y
	int aux = mov;
	int x = juego.mina.posFila + tdirs4[aux][0];
	int y = juego.mina.posColumna + tdirs4[aux][1];

	juego.contMov++; //Incrementa los movimientos, siempre que lea una tecla

	if (dentroPlano(juego.mina, x, y)) { //Si el minero se quiere mover dentro del pano.
		switch (juego.mina.planoMina[x][y]) {
		case LIBRE:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos libre donde estaba antes el miner
			juego.mina.posFila = x; //Actualizamos la posicion del minero
			juego.mina.posColumna = y;
			break;
		case TIERRA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			juego.mina.posFila = x; //Actualizamos la posicion del minero
			juego.mina.posColumna = y;
			break;
		case GEMA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			juego.mina.posFila = x; //Actualizamos la posicion del minero
			juego.mina.posColumna = y;
			juego.contGemas++; //Actualizar el contador de gemas
			break;
		case PIEDRA: //La piedra esta en x, y (Donde se quiere mover el minero)
			//Si el minero viene por la derecha
			if (juego.mina.planoMina[x][y - 1] == LIBRE && aux == 3) {
				juego.mina.planoMina[x][y - 1] = PIEDRA; //Movemos la piedra
				juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
				juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos libre donde antes estaba el minero
				juego.mina.posFila = x; //Actualizamos la posicion del minero
				juego.mina.posColumna = y;
			}
			//Si el minero viene por la izquierda
			if (juego.mina.planoMina[x][y + 1] == LIBRE && aux == 2) {
				juego.mina.planoMina[x][y + 1] = PIEDRA; //Movemos la piedra
				juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
				juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos libre donde estaba antes el minero
				juego.mina.posFila = x; //Actualizamos la posicion del minero
				juego.mina.posColumna = y;
			}
			break;
		case MURO: //NO HACE NADA
			break;
		case SALIDA:
			juego.mina.planoMina[x][y] = MINERO; //Movemos el minero
			juego.mina.planoMina[juego.mina.posFila][juego.mina.posColumna] = LIBRE; //Ponemos tierra donde estaba antes el miner
			juego.mina.posFila = x; //Actualizamos la posicion del minero
			juego.mina.posColumna = y;
			juego.estadoMinero = EXITO;
			break;
		case MINERO: //NO HACE NADA
			break;
		}
	}
}
void dibujar(const tJuego& juego) {
	system("cls");
	if (juego.escalaJuego == 1) {
		dibujar1_1(juego.mina);
	}
	else if (juego.escalaJuego == 2) {
		dibujar1_3(juego.mina);
	}
	cout << "Gemas totales recogidas: " << juego.contGemas << endl;
	cout << "Numero de movimientos: " << juego.contMov << endl;
	cout << "Dinamitas usadas: " << juego.contTNT << endl;
}
tTecla leerTecla(tJuego& juego) {
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
	else if (dir == 27) {// Tecla ESC
		tecla = SALIR;
		juego.estadoMinero = ABANDONO;
	}
	else if (dir == 68 || dir == 100) {
		tecla = TNT;
	}
	return tecla;
}
void leerMovimiento(tJuego& juego, tTecla& tecla, std::istream& movimientos){
	movimientos << tecla;
	if (tecla == SALIR) {
		juego.estadoMinero = ABANDONO;
	}
}
istream& operator<<(std::istream & movimientos, tTecla & tecla){ /******LECTURA DE LA TECLA DE FICHERO, NO DE USUARIO******/
		char dir;
		movimientos.get(dir);
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
		case 'D': //FIN DE MOVIMIENTOS, EL MINERO SE SIENTA
			tecla = TNT;
			break;
		case '\n':
			tecla = NADA;
			break;
		}
		return movimientos;
}
void comprobarCaida(tJuego& juego) {
	int w = 0;
	for (int i = juego.mina.nFilas - 1; i > -1; i--) {
		for (int j = juego.mina.nColumnas - 1; j > -1 ; j--) {
			if (juego.mina.planoMina[i][j] == PIEDRA) {
				w = 1;
				while (juego.mina.planoMina[i + w][j] == LIBRE && i + w < juego.mina.nFilas) {
					juego.mina.planoMina[i + w][j] = PIEDRA;
					juego.mina.planoMina[i + w - 1][j] = LIBRE;
					w++;
					dibujar(juego);
				}
			}
			else if (juego.mina.planoMina[i][j] == GEMA) {
				w = 1;
				while (juego.mina.planoMina[i + w][j] == LIBRE && i + w < juego.mina.nFilas) {
					juego.mina.planoMina[i + w][j] = GEMA;
					juego.mina.planoMina[i + w - 1][j] = LIBRE;
					w++;
					dibujar(juego);
				}
			}
			else if (juego.mina.planoMina[i][j] == DINAMITA) {
				w = 1;
				while (juego.mina.planoMina[i + w][j] == LIBRE && i + w < juego.mina.nFilas) {
					juego.mina.planoMina[i + w][j] = DINAMITA;
					juego.mina.planoMina[i + w - 1][j] = LIBRE;
					w++;
					dibujar(juego); //Para ver el rastro de la dinamita
				}
				//dibujar(juego);
			}
		}
	}
}
bool ponerTNT(tJuego& juego) {
	bool puede = false;
	//Posiciones de la dinamita
	int filaTNT = juego.mina.posFila + 1;
	int columnaTNT = juego.mina.posColumna;
	//Comprobamos si se puede poner la dinamita
	if (juego.mina.planoMina[filaTNT][columnaTNT] == LIBRE) {
		juego.mina.planoMina[filaTNT][columnaTNT] = DINAMITA;
		juego.contTNT++;
		puede = true; //Puede poner la dinamita
	}
	if (puede) { //Hacemos que caiga la dinamita
		comprobarCaida(juego);
	}
	for (int i = 0; i < juego.mina.nFilas; i++) { //Para sacar la posicion donde ha quedado la Dinamita
		for (int j = 0; j < juego.mina.nColumnas; j++) {
			if (juego.mina.planoMina[i][j] == DINAMITA) {
				filaTNT = i;
				columnaTNT = j;
			}
		}
	}
	//Aqui ya reventamos la Dinamita y el juego.contTNT vuelve a ser 0
	for (int dir = 0; dir < 8; dir++) {
		while (dentroPlano(juego.mina, filaTNT + incF[dir], columnaTNT + incC[dir]) ) {
			if (juego.mina.planoMina[filaTNT + incF[dir]][columnaTNT + incC[dir]] == MINERO) {
				juego.estadoMinero = FRACASO;
			}
			juego.mina.planoMina[filaTNT + incF[dir]][columnaTNT + incC[dir]] = LIBRE;
			dir++;
		}
	}
	//Quito la dinamita del pano
	juego.mina.planoMina[filaTNT][columnaTNT] = LIBRE;
	return puede; //Devuelve si se puede poner la dinamita o no 
}