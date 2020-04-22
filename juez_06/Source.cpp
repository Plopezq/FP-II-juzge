
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado; VS 2019 y windows 10
// Nombre del problema: Maxima cota de un mapa topográfico
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: almacenamos la matriz, y tan solo buscamos el mayorv valor contenido en ella
// una vez encontrado, almacenamos sus coordenadas

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX1 = 100;
const int MAX2 = 100;
// propios o los de las estructuras de datos de clase
typedef struct {
    int filas, columnas;
    int matriz[MAX1][MAX2];
}tMatriz;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
string resolver(tMatriz mat) {

    int x = 0, y = 0;

    int maximo = mat.matriz[0][0];
    for (int i = 0; i < mat.filas; i++) {
        for (int j = 0; j < mat.columnas; j++) {
            if (mat.matriz[i][j] > maximo) {
                maximo = mat.matriz[i][j];
                x = i;
                y = j;
            }
        }
    }
    //ESTARÍA MUCHO MEJOR ALMACENAR LA INFORMACIÓN EN UN STRUCT Y DEVOLVER EL STRUCT
    string resultado = to_string(maximo) + " " + to_string(x) + " " + to_string(y);
    return resultado;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    tMatriz matriz;
    // leer los datos de la entrada
    cin >> matriz.filas >> matriz.columnas;
    for (int i = 0; i < matriz.filas; i++) {
        for (int j = 0; j < matriz.columnas; j++) {
            cin >> matriz.matriz[i][j];
        }
    }
    if (!std::cin)  // fin de la entrada
        return false;

    string sol = resolver(matriz);

    // escribir sol
    cout << sol << endl;
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