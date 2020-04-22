
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado; VS 2019 y windows 10
// Nombre del problema: La fabrica de juguetes de Papa Noel
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: sobrecargamos los aperadores para poder hacer las operaciones tipicas de matriz y asi reutilizar código.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX1 = 100;
const int MAX2 = 100;
// tipos 
typedef struct {
    int filas, columnas;
    int matriz[MAX1][MAX2];
}tMatriz;
tMatriz operator*(tMatriz const& a, tMatriz const& b) {
    //Matriz resultante de la multiplicacion
    tMatriz aux; aux.filas = a.filas; aux.columnas = b.columnas;
    for (int i = 0; i < aux.filas; i++) {
        for (int j = 0; j < aux.columnas; j++) {
            aux.matriz[i][j] = 0;
            for(int k=0; k < a.columnas; k++){
                aux.matriz[i][j] += a.matriz[i][k] * b.matriz[k][j];
            }
        }
    }
    return aux;
}
istream& operator>>(istream & in, tMatriz & m){
    in >> m.filas >> m.columnas;
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            in >> m.matriz[i][j];
        }
    }
    return in;
}
ostream& operator<<(ostream& out, tMatriz const& m) {
    // escribir sol
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            out << m.matriz[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tMatriz resolver(tMatriz mat1, tMatriz mat2) {
    tMatriz aux = mat1 * mat2;
    return aux;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    tMatriz matriz1;
    tMatriz matriz2;
    // leer los datos de la entrada
    cin >> matriz1;
    cin >> matriz2;
    if (!std::cin)  // fin de la entrada
        return false;
    tMatriz sol = resolver(matriz1, matriz2);
    cout << sol;
    cout << endl;
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
    while (resuelveCaso());
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}