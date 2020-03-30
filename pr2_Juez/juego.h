#include "mina.h"
#include <fstream>

typedef enum { ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA} tTecla;
typedef enum {
	EXPLORANDO, //El minero continua buscando diamantes por la mina
	EXITO, //El minero consigue llegar a la salida
	ABANDONO, //Si el minero decide sentarse a esperar a que le vengan a rescatar 
	FRACASO //Si el minero muero durante la exploración de la mina
}tEstado;
typedef struct {
	tMina mina;
	int contGemas = 0;
	int contMov = 0;
	tEstado estadoMinero = EXPLORANDO;
	int escalaJuego = 0; //La opcion seleccionada para dibujar el juego 1: escala 1:1 y 2 escala 1:3
	int opcionMov = 0; //Opcion elegida para introducir movimientos: por teclado (1) o por fichero (2)
	//int contTNT; 
}tJuego;

//PROTOTIPOS
void cargar_juego(tJuego& juego, std::istream& input);
void dibujar(const tJuego& juego);
istream& operator<< (std::istream& movimientos, tTecla& tecla);
void leerMovimiento(tJuego& juego, tTecla& tecla, std::istream& movimientos);
void realizarMovimiento(tJuego& juego, tTecla& mov);
void jugar(tJuego& juego, std::istream& entrada, std::istream& movimientos);
