#include "mina.h"
typedef enum tTecla {ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT};
typedef struct {
	tMina mina;
	int contGemas;
	int contMov;
	int contTNT;
}tJuego;



//PROTOTIPOS
void colorFondo(int color);
bool cargar_juego( tJuego& juego, int nivel);
bool hacerMovimiento(tJuego& juego, tTecla tecla);
void dibujar(const tJuego& juego);

