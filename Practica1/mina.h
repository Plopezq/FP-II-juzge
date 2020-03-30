//LIBRERÍAS
#include<iostream>
#include <fstream>
using namespace std;
//CONSTANTES
const int MAX = 50;


//TIPOS
typedef enum { LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA, VACIO } tElemento;
typedef tElemento tPlano[MAX][MAX];
typedef struct {
	tPlano planoMina;
	int nFilas, nColumnas; //Numero de filas y columnas del array bidimensional (de la mina)
	int posFila, posColumna; //Posicion donde se encuentra el minero.
}tMina;
typedef struct {
	char planoCaracteres[3 * MAX][3 * MAX]; // esta matriz guarda los caracteres por cada casilla.
}tPlanoCaracteres;

typedef struct {
	int planoColores[3 * MAX][3 * MAX]; //Esta matriz guarda el color de cada casilla
}tPlanoColores;

//PROTOTIPOS
void cargar_Mina(ifstream& fichero, tMina& mina);//lee los datos de	un fichero y guarda la posición	del	minero.
void dibujar1_1(const tMina& mina); //: dibuja la mina a escala	1 : 1
void dibujar1_3(const tMina& mina); //: dibuja la mina a escala 1:3	y usa la siguientefunción dibuja3x3.
void dibuja3x3(tElemento casilla, tPlanoCaracteres& caracteres, tPlanoColores& colores, int i, int j);
void colorFondo(int color);

ostream& operator<<(ostream& out, tElemento const& e);
bool dentroPlano(tMina const& mina, int x, int y);
char getChar(tElemento ele);


