
const int MAX = 50;
typedef enum tCasilla{LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA};
typedef tCasilla tPlano[MAX][MAX];
typedef struct {
	tPlano planoMina; 
	int nFilas, nColumnas; //Numero de filas y columnas del array bidimensional (de la mina)
	int posFila, posColumna; //Posicion donde se encuentra el minero.
}tMina;






