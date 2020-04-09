
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
            out << m.matriz[i][j];
        }
        out << endl;
    }
    return out;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tMatriz resolver(tMatriz sopa, tPalabras palabras, tMatriz resultado) {

 
    //1 - Recorrer la matriz 
    for (int z = 0; z < palabras.numPalabras; z++) {//Palabras a buscar
        bool encontrado = false;
        for (int i = 0; i < sopa.numFilas; i++) {
            for (int j = 0; j < sopa.numColumnas; j++) {
                int aux1 = 0; //Sentido natural
                int aux2 = 0; //Sentido contrario
                //Buscar en horizontal, mover la fila
                for (int f = 0; f < palabras.palabras[z].size(); f++) {
                    if (sopa.matriz[i][j + f] == palabras.palabras[z][f]) {
                        aux1++;
                    }
                }
                int g = 0;
                for (int f = palabras.palabras[z].size(); f >= 0; f--) {
              
                    if (sopa.matriz[i][j + g] == palabras.palabras[z][f]) {
                        aux2++;
                        g++;
                    }
                }
                if (aux1 == palabras.palabras[z].size()) {
                    encontrado = true; //Encontrado en el sentido natural
                    //Escribimos el resultado

                }
                if (aux2 == palabras.palabras[z].size()) {
                    encontrado = true; //Encontrado en el sentido contrario
                    //Escribimos el resultado

                }

                aux1 = 0;
                aux2 = 0;
                //Buscar en vertical


                aux1 = 0;
                aux2 = 0;
                //Buscar en diagonal -- Codigo sonia





            }
        }
        if (encontrado) {

        }

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
