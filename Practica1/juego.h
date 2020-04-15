#include "mina.h"
const int incF[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int incC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef enum { ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT} tTecla; 
typedef enum {
	EXPLORANDO, //El minero continua buscando diamantes por la mina
	EXITO, //El minero consigue llegar a la salida
	ABANDONO, //Si el minero decide sentarse a esperar a que le vengan a rescatar 
	FRACASO //Si el minero muere durante la exploración de la mina
}tEstado;

typedef struct {
	tMina mina;
	int contGemas = 0;
	int contMov = 0;
	tEstado estadoMinero = EXPLORANDO;
	int escalaJuego = 0; //La opcion seleccionada para dibujar el juego 1: escala 1:1 y 2 escala 1:3
	int opcionMov = 0; //Opcion elegida para introducir movimientos: por teclado (1) o por fichero (2)
	int contTNT = 0;
	int nivel = 1;
}tJuego;

//PROTOTIPOS
void colorFondo(int color);
bool cargar_juego( tJuego& juego, int nivel);
void realizarMovimiento(tJuego& juego, tTecla& mov);
void dibujar(const tJuego& juego);
void jugarFichero(tJuego& juego, std::istream& movimientos);
void jugarTeclado(tJuego& juego);
istream& operator<< (std::istream& movimientos, tTecla& tecla);
void leerMovimiento(tJuego& juego, tTecla& tecla, std::istream& movimientos);
void comprobarCaida(tJuego& juego, bool& seguirCayendo);
tTecla leerTecla(tJuego& juego);
bool ponerTNT(tJuego& juego);