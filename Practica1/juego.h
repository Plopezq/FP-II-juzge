#include "mina.h"
typedef enum tTecla {ARRIBA, ABAJO, DCHA, IZDA, SALIR, NADA, TNT};
typedef struct {
	tMina mina;
	int contGemas;
	int contMov;
	int contTNT;
}tJuego;
typedef struct {
	char planoCaracteres[3*MAX][3*MAX]; // esta matriz guarda los caracteres por cada casilla.
}tPlanoCaracteres;

typedef struct {
	int planoColores[3*MAX][3*MAX]; //Esta matriz guarda el color de cada casilla
}tPlanoColores;


//Prototipos usados en el main, relacionados con el juego
void colorFondo(int color);

