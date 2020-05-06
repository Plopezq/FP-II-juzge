
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019 con windows 10
// Nombre del problema: Matriz tridiagonal
// Comentario general sobre la solución 
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

const int NUM_DIRECCIONES = 4;                  //IZQ       DRCHA   ARRIBA  ABAJO
const pair <int, int > dirs4[NUM_DIRECCIONES] = { { 0 ,-1} ,{0 ,1} ,{-1 ,0} ,{1 , 0} };

typedef struct {
    int matriz[50][50];
    int numFilas = 0;
    int numColumnas = 0; 
}tMatriz;

typedef struct {
    int fila = 0;
    int suma = -999999999;
}tResultado;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tResultado resolver(tMatriz caso) {
    tResultado resul;
    int suma = 0;
    for (int i = 0; i < caso.numColumnas; i++) {
         suma = caso.matriz[i][i];
        for (int d = 0; d < 4; d++) {

            //Compruebo que a donde se quiere mover está dentro del array
            if ( ( (i + dirs4[d].first >= 0) && (i + dirs4[d].first < caso.numFilas) )
                && ( (i + dirs4[d].second >= 0) && (i + dirs4[d].second < caso.numColumnas)) ) {
                suma += caso.matriz[i + dirs4[d].first][i + dirs4[d].second];
            }

        }
        if (suma > resul.suma) {
            resul.fila = i;
            resul.suma = suma;
        }
    }


    return resul;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tMatriz caso;
    // leer los datos de la entrada
    int aux = 0;
    cin >> aux;
    caso.numColumnas = aux;
    caso.numFilas = aux;

    //Inicializo la matriz
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            caso.matriz[i][j] = 0;
        }
    }

    //Almaceno la matriz principal
    for (int i = 0; i < caso.numColumnas; i++) {
        cin >> caso.matriz[i][i];
    }

    //Almaceno la matriz de arriba
    for (int i = 0; i < caso.numColumnas - 1; i++) {
        cin >> caso.matriz[i][i + 1];
    }

    //Almaceno la matriz de abajo
    for (int i = 0; i < caso.numColumnas - 1; i++) {
        cin >> caso.matriz[i + 1][i];
    }

    if (!std::cin)  // fin de la entrada
        return false;

    tResultado sol = resolver(caso);

    // escribir sol
    cout << sol.fila << " " << sol.suma << endl;
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
