
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019 y Windows 10
// Nombre del problema: 4 en raya
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: 

#include <iostream>
#include <fstream>

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

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
string resolver(tCaso caso) {
    int contA = 0;
    int contB = 0;
    string aux = "EMPATE";









    if (contA == 4) {
        aux = "Gana A";
    }
    if (contB == 4) {
        aux = "Gana B";
    }
    return aux;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tCaso caso;
    //Inicializamos el array del tablero.
    for (int i = 0; i < caso.tablero.filas; i++) {
        for (int j = 0; j < caso.tablero.columnas; j++) {
            caso.tablero.tablero[i][j] = -1;
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

    string sol = resolver(caso);

    // escribir sol
    cout << sol << endl;
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
