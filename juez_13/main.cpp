
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019 y windows 10
// Nombre del problema: Sopa de letras
// Comentario general sobre la solución
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

const int incF[8] = { 1,1,0,-1,-1,-1,0,1 };
const int incC[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef struct {
    int numFilas = 0;
    int numColumnas = 0;
    char matriz[50][50];
}tMatriz;

typedef struct {
    string palabras[50];
    int numPalabras = 0;
}tPalabras;

bool dentro_matriz(tMatriz t, int x, int y) {
    if (x >= 0 && x < t.numFilas && y >= 0 && y < t.numColumnas) {
        return true;
    }
    else {
        return false;
    }
}

istream& operator>> (istream& in, tMatriz& m) { //LECTURA y GUARDADO

    for (int i = 0; i < m.numFilas; i++) {
        for (int j = 0; j < m.numColumnas; j++) {
            in >> m.matriz[i][j];
        }
    }
    return in;
}

ostream& operator<< (ostream& out, tMatriz const& m) { //ESCRITURA
    for (int i = 0; i < m.numFilas; i++) {
        for (int j = 0; j < m.numColumnas; j++) {
            out << " " << m.matriz[i][j];
        }
        out << endl;
    }
    return out;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tMatriz resolver(tMatriz sopa, tPalabras palabras, tMatriz& solucion) {
    bool encontrada = false;

    for (int z = 0; z < palabras.numPalabras; z++) {
        for (int i = 0; i < sopa.numFilas; i++) {
            for (int j = 0; j < sopa.numColumnas; j++) {
                //cout << "Exploramos casillas adyacentes a la casilla [" << i << "][" << j << "]: ";
                for (int dir = 0; dir < 8; dir++) { //Cambio de direccion
                    int cont = 0;
                    int aux = 0;
                   
                    while (dentro_matriz(sopa, i + (incF[dir] * cont), j + (incC[dir] * cont)) && cont < palabras.palabras[z].size() ) {

                       // cout << sopa.matriz[i + (incF[dir] * cont)][j + (incC[dir] * cont)];
                       
                        if (palabras.palabras[z][cont] == sopa.matriz[i + (incF[dir] * cont)][j + (incC[dir] * cont)]) {
                            aux++;
                        }
                        
                        if (aux == palabras.palabras[z].size()) {
                            encontrada = true;
                               
                            for (int aux = 0; aux < palabras.palabras[z].size(); aux++) {
                                solucion.matriz[i + (incF[dir] * aux)][j + (incC[dir] * aux)] = sopa.matriz[i + (incF[dir] * aux)][j + (incC[dir] * aux)];
                            }
                        }
                        cont++;
                    }
                   // cout << "- "; //Cambia de dirección 
                }
              //  cout << endl;
            }
        }
       // cout << endl;
       // cout << endl;
    }

    bool encontrado = false;
        if (encontrado) {

        }

    return sopa;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    tMatriz sopa;
    tPalabras palabras;
    tMatriz solucion;
    // leer los datos de la entrada
    cin >> sopa.numFilas;
    cin >> sopa.numColumnas;

    solucion.numFilas = sopa.numFilas;
    solucion.numColumnas = sopa.numColumnas;

    //Inicializamos matriz sopa
    for (int s = 0; s < 50; s++) {
        for (int w = 0; w < 50; w++) {
            sopa.matriz[s][w] = '-';
            solucion.matriz[s][w] = ' ';
        }
    }

    //Leemos la sopa

        cin >> sopa;

    //Inicializamos el vector palabras
    for (int z = 0; z < 50; z++) {
        palabras.palabras[z] = "";
    }

    //Leemos las palabras
    cin >> palabras.numPalabras;
    for (int r = 0; r < palabras.numPalabras; r++) {
        cin >> palabras.palabras[r];
    }
    tMatriz sol = resolver(sopa, palabras, solucion);

    // escribir solución -- TODO
    for (int i = 0; i < sopa.numColumnas; i++) {
        cout << " -";
    }
    cout << endl;
    cout << solucion;
    for (int i = 0; i < sopa.numColumnas; i++) {
        cout << " -";
    }
    cout << endl;
    cout << endl;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}
