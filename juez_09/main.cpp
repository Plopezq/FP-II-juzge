
// Autor/a: Pablo Lopez y Sergio Sanchez    
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual studio 2019 y Windows 10
// Nombre del problema: Buscador de patrones
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: 

#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
    int numFilasImagen = 0;
    int numColumnasImagen = 0;
    int imagen[40][40]; //TODO: Hay que inicializar 
}tImagen;

typedef struct {
    int numFilasPatron = 0;
    int numColumnasPatron = 0;
    int patron[40][40];
}tPatron;

typedef struct {
    int posFila = -1;
    int posColumna = -1;
}tPosicion;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tPosicion resolver( tImagen imagen, tPatron patron) {
    tPosicion pos;
    int sum = 0;

        for (int i = 0; i < imagen.numFilasImagen; i++) {
            for (int j = 0; j < imagen.numColumnasImagen; j++) {

                for (int s = 0; s < patron.numFilasPatron; s++) {
                    for (int w = 0; w < patron.numColumnasPatron; w++) {
                        if (imagen.imagen[i + s][j + w] == patron.patron[s][w]) {
                            sum++;
                            if (sum == (patron.numFilasPatron * patron.numColumnasPatron)) {
                                pos.posFila = i;
                                pos.posColumna = j;
                                return pos;
                            }
                        }
                    }
                }

            }
        }

    return pos;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tImagen imagen;
    tPatron patron;

    //Inicializo las matrices a - 1
    for (int r = 0; r < 40; r++) {
        for (int z = 0; z < 40; z++) {
            imagen.imagen[r][z] = 0;
            patron.patron[r][z] = 0;
        }
    }
    // leer los datos de la entrada
    cin >> imagen.numFilasImagen;
    cin >> imagen.numColumnasImagen;
    for (int i = 0; i < imagen.numFilasImagen; i++) {
        for (int j = 0; j < imagen.numColumnasImagen; j++) {
            cin >> imagen.imagen[i][j];
        }
    }
    cin >> patron.numFilasPatron;
    cin >> patron.numColumnasPatron;
    for (int s = 0; s < patron.numFilasPatron; s++) {
        for (int w = 0; w < patron.numColumnasPatron; w++) {
            cin >> patron.patron[s][w];
        }
    }
    if (!std::cin)  // fin de la entrada
        return false;
    tPosicion sol = resolver(imagen, patron);

    // escribir sol
    if (sol.posFila != -1 && sol.posColumna != -1) {
        cout << sol.posFila << " " << sol.posColumna << endl;
    }
    else {
        cout << "NO" << endl;
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
