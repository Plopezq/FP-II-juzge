#include "mina.h"
#include <fstream>
const int incF[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int incC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef enum { ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT} tTecla;
typedef enum {
	EXPLORANDO, //El minero continua buscando diamantes por la mina
	EXITO, //El minero consigue llegar a la salida
	ABANDONO, //Si el minero decide sentarse a esperar a que le vengan a rescatar 
	FRACASO //Si el minero muero durante la exploración de la mina
}tEstado;
typedef struct {
	tMina mina;
	int contGemas;
	int contMov;
	tEstado estadoMinero;
	int escalaJuego; //La opcion seleccionada para dibujar el juego 1: escala 1:1 y 2 escala 1:3
	int opcionMov; //Opcion elegida para introducir movimientos: por teclado (1) o por fichero (2)
	int contTNT;
	int nivel;
}tJuego;

//PROTOTIPOS
void colorFondo(int color);
void cargar_juego(tJuego& juego, std::istream& input);
void dibujar(const tJuego& juego);
istream& operator<< (std::istream& movimientos, tTecla& tecla);
void leerMovimiento(tJuego& juego, tTecla& tecla, std::istream& movimientos);
void realizarMovimiento(tJuego& juego, tTecla& mov);
void jugar(tJuego& juego, std::istream& entrada, std::istream& movimientos);
void comprobarCaida(tJuego& juego);
	//void caidaCascada(tJuego & juego);
bool ponerTNT(tJuego& juego);