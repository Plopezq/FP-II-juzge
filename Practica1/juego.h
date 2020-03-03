#include "mina.h"
typedef enum tTecla {ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT};
typedef struct {
	tMina mina;
	int contGemas;
	int contMov;
	int contTNT;
}tJuego;



//Prototipos usados en el main, relacionados con el juego
void colorFondo(int color);

