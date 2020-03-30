#include <iomanip>
#include <iostream>

using namespace std;
//CONSTANTES
const int MAX = 50;

//TIPOS
typedef enum { LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO } tElemento;
typedef tElemento tPlano[MAX][MAX];
typedef struct {
	tPlano planoMina;
	int nFilas = 0;
	int nColumnas = 0; //Numero de filas y columnas del array bidimensional (de la mina)
	int posFila = 0;
	int posColumna = 0; //Posicion donde se encuentra el minero.
}tMina;
typedef struct {
	char planoCaracteres[3 * MAX][3 * MAX];// esta matriz guarda los caracteres por cada casilla.
}tPlanoCaracteres;


//PROTOTIPOS
void cargar_mina(istream& fichero, tMina& mina);//lee los datos de	un fichero y guarda la posición	del	minero.
void dibujar1_1(const tMina& mina); //: dibuja la mina a escala	1 : 1
void dibujar3_1(const tMina& mina); //: dibuja la mina a escala 1:3	y usa la siguientefunción dibuja3x3.
void dibuja3x3(tElemento casilla, tPlanoCaracteres& caracteres, int i, int j);
ostream& operator<<(ostream& out, tElemento const& e);
bool dentroPlano(tMina const& mina, int x, int y);
char getChar(tElemento ele);


