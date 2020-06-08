
// Autor/a: Sergios Sanchez y Pablo Lopez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019
// Nombre del problema: Recursion, contar numero digitos
// Comentario general sobre la solución
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
unsigned long long int  resolver(unsigned long long int  n) {
    unsigned long long int sol = 0;
        if (n < 10)
            sol = 1;
        else
            sol = 1 + resolver(n / 10);
        return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    unsigned long long int  numero = 0;
    cin >> numero;
    if (!cin) // fin de la entrada
        return false;

    unsigned long long int sol = resolver(numero);

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
