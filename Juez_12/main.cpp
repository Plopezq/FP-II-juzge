
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019 y Windows 10
// Nombre del problema: 4 en raya
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: 

#include <iostream>
#include <fstream>
#include <iomanip>   
//const int MAX_FILAS = 50;
//const int MAX_COLUMNAS = 50;
const int incF[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int incC[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

using namespace std;

typedef struct {
    const int filas = 6;
    const int columnas = 7;
    int tablero[6][7];
    int cont = 0;
}tTablero;

typedef struct {
    tTablero tablero;
    int numFichas = 0;
    int colocaciones[42];
}tCaso;

bool dentro_matriz(tTablero t, int x, int y) {
    if (x >= 0 && x < t.filas && y >= 0 && y < t.columnas) {
        return true;
    }
    else {
        return false;
    }
}

void comprobarCaida(tCaso& caso, bool& seguirCayendo) {
    seguirCayendo = false;

    for (int i = 0; i < caso.tablero.filas; i++) {
        for (int j = 0; j < caso.tablero.columnas; j++) {
            if (caso.tablero.tablero[i][j] == 1 && caso.tablero.tablero[i + 1][j] == 0
                && dentro_matriz(caso.tablero, i+1, j ) ) {
                caso.tablero.tablero[i + 1][j] = 1;
                caso.tablero.tablero[i][j] = 0;
                seguirCayendo = true;
            }
            if (caso.tablero.tablero[i][j] == 2 && caso.tablero.tablero[i + 1][j] == 0
                && dentro_matriz(caso.tablero, i + 1, j) ) {
                caso.tablero.tablero[i + 1][j] = 2;
                caso.tablero.tablero[i][j] = 0;
                seguirCayendo = true;
            }
        }
    }
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(tCaso &caso) {
    int contA = 0; //Jugador 1, fichas que pone
    int contB = 0; //Jugador 2, fichas que pone
    int aux = 3;
    int turno = 0; //Jugador 1 es par y jugador 2 es impar
    for (int q = 0; q < caso.numFichas; q++) {

        //Jugadoor pone ficha
        if(turno % 2 == 0){  //Jugador A - 1 - Par
            caso.tablero.tablero[0][caso.colocaciones[q]] = 1;
            contA++;
            turno++;
        }
        else { //Jugador B - 2 - Impar
            caso.tablero.tablero[0][caso.colocaciones[q]] = 2;
            contB++;
            turno++;
        }

        //Caen fichas
        bool seguirCayendo = true;
        while (seguirCayendo) {
            comprobarCaida(caso, seguirCayendo);
        }

        // Visualizo la matriz


        //Comprobar si hay 4 en raya
        // Vamos a explorar tres elementos por cada radial
        //cout << "   Exploramos Si hay 4 en raya " << endl;
        int aux1 = 0; //Para contar las adyacentes del jugador 1
        int aux2 = 0; //Para contar las adyacentes del jugador 2
        for (int i = 0; i < caso.tablero.filas; i++) {
            for (int j = 0; j < caso.tablero.columnas; j++) {
                //cout << "Exploramos casillas adyacentes a la casilla [" << i << "][" << j << "]: ";
                for (int dir = 0; dir < 8; dir++) {
                    int cont = 1;
                    while (dentro_matriz(caso.tablero, i + (incF[dir] * cont), j + (incC[dir] * cont)) && cont < 4) {
                        
                        if (caso.tablero.tablero[i + (incF[dir] * cont)][j + (incC[dir] * cont)] == 1) {
                            aux1++;
                            if (aux1 == 3) {
                                return 1;
                            }
                        }
                        if (caso.tablero.tablero[i + (incF[dir] * cont)][j + (incC[dir] * cont)] == 2) {
                            aux2++;
                            if (aux2 == 3) {
                                return 2;
                            }
                        }
                        cont++;
                    }
                    aux1 = 0;
                    aux2 = 0;
                }

            }
        }
    }
    return 3;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tCaso caso;
    //Inicializamos el array del tablero.
    for (int i = 0; i < caso.tablero.filas; i++) {
        for (int j = 0; j < caso.tablero.columnas; j++) {
            caso.tablero.tablero[i][j] = 0;
        }
    }
    //Inicializo el vector de colocaciones
    for (int w = 0; w < 42; w++) {
        caso.colocaciones[w] = -1;
    }
    // leer los datos de la entrada
    cin >> caso.numFichas;
    for (int s = 0; s < caso.numFichas; s++) {
        cin >> caso.colocaciones[s];
    }

    if (caso.numFichas == 0)
        return false;

    int sol = resolver(caso);

    
    for (int i = 0; i < caso.tablero.filas; i++) {
        for (int j = 0; j < caso.tablero.columnas; j++) {
            cout << setw(2) << caso.tablero.tablero[i][j] << " ";
        }
        cout << endl;
    }
    // escribir sol
    if (sol == 1) {
        cout << "Gana A" << endl;

    }
    if (sol == 2) {
        cout << "Gana B" << endl;

    } 
    if (sol == 3) {
        cout << "EMPATE" << endl;

    }
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
