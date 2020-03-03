
const int MAX = 50;
typedef enum tCasilla{LIBRE, TIERRA, GEMA, PIEDRA, MURO, SALIDA, MINERO, DINAMITA};
typedef tCasilla tPlano[MAX][MAX];
typedef struct {
	tPlano planoMina; 
	int nFilas, nColumnas; //Numero de filas y columnas del array bidimensional (de la mina)
	int posFila, posColumna; //Posicion donde se encuentra el minero.
}tMina;

void cargar_Mina(ifstream& fichero, tMina& mina) {
	//lee	los	datos	de	un	fichero y	guarda	la	posición	del	minero.

}


void dibujar1_1(const tMina& mina) { //: dibuja	la	mina	a	escala	1 : 1


}

void dibujar1_3(const tMina& mina) { 
//: dibuja la mina a escala 1:3	y usa la siguientefunción dibuja3x3.



}

void dibuja3x3(tCasilla casilla, tPlanoCaracteres caracteres, tPlanoColores colores, int i, int j){
	// : dibuja	las	casillas aumentadas	tres veces. 
	// En concreto, la	casilla	sirve para actualizar el plano de caracteres y colores en las
	// coordenadas	i, j.


