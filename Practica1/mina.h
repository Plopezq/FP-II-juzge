
const int MAXIMO = 10;
typedef enum tCasilla{LIBRE, TIERRA, GEMA, PIEDRA, MURO, DINAMITA, SALIDA, MINERO};
typedef tCasilla tPlano[MAXIMO][MAXIMO];
typedef struct {
	tPlano planoMina;
	int nFilas, nColumnas;
	int posFila, posColumna;
}tMina;






