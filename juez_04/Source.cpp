#include <stdio.h>

// Autor/a: Pablo López, Sergio Sanchez, Alvaro Ortega, Jordan David Loayza, Israel Luengo
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: VS Studio 2019
// Nombre del problema: Solucion del burro y las alforjas
// Comentario general sobre la solución
// explicando como se resuelve el problema: Primero ordenamos los pesos y rdespués recorremos el array ordenado, 
// contando cuantos valores hay repetidos

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1000;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(int pesos[MAX], int &numSacos, int &burros) {
    int nuevo;
    int pos;
    int cont = 0;
    // En el siguiente codigo, ordenamos la lista 
    for (int i = 1; i < numSacos; i++) {
        nuevo = pesos[i];
        pos = 0;
        while ((pos < i) && (pesos[pos] < nuevo)) { //Mientras las posiciones de la izq sea menor que la que estamos actualemnete
            pos++;
        }
        // pos: índice del primer mayor; i si no lo hay
        for (int j = i; j > pos; j--) {
            pesos[j] = pesos[j - 1];
        }
        pesos[pos] = nuevo;
    }
    //Aqui ya tenemos ya los pesos ordenados, procedemos a resolverlos
    int i = 1;
    while ( i < numSacos && cont < burros) {
        if (pesos[i - 1] == pesos[i]) {
            cont++;
            i = i + 2;
        }
        else {
            i++;
        }
    }
    return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    int burros, numSacos;
    int pesos[MAX];

    cin >> burros >> numSacos;
    for (int i = 0; i < numSacos; i++) {
        cin >> pesos[i];
    }

    int sol = resolver(pesos, numSacos, burros);
    
    // escribir solución
    cout << sol << endl;
     cout << endl;
  /*  for (int j = 0; j < numSacos; j++) {
        cout << pesos[j] << " ";
    }
    cout << endl;*/

}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
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













