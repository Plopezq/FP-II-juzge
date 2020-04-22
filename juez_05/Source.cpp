#include <stdio.h>

// Autor/a: Pablo López, Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: VS Studio 2019
// Nombre del problema: Solucion de la intersección de conjuntos 
// Comentario general sobre la solución
// explicando como se resuelve el problema: Primero ordenamos y luego contamos cuantos valores hay repetidos

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1000;

typedef struct {
    int cto[500];
    int cont = 0;
}tCto;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tCto resolver(tCto& con1, tCto& con2) {
    tCto conFin;
    conFin.cont = 0;
    //Ordeno el conjunto 1
    int tmp;
    // Del primero al penúltimo...
    for (int i = 0; i < con1.cont - 1; i++) {
        // Desde el último hasta el siguiente a i...
        for (int j = con1.cont - 1; j > i; j--) {
            if (con1.cto[j] < con1.cto[j - 1]) {
                tmp = con1.cto[j];
                con1.cto[j] = con1.cto[j - 1];
                con1.cto[j - 1] = tmp;
            }// El elemento va hacia la izq hasta que tiene a la izq uno menor que el 
        }
    }
    //Ordeno el conjunto 2
    int tmp2;
    // Del primero al penúltimo...
    for (int i = 0; i < con2.cont - 1; i++) {
        // Desde el último hasta el siguiente a i...
        for (int j = con2.cont - 1; j > i; j--) {
            if (con2.cto[j] < con2.cto[j - 1]) {
                tmp2 = con2.cto[j];
                con2.cto[j] = con2.cto[j - 1];
                con2.cto[j - 1] = tmp2;
            }// El elemento va hacia la izq hasta que tiene a la izq uno menor que el 
        }
    }
    //Aqui ya tenemos ya los pesos ordenados, procedemos a resolverlos
    int i = 0, j = 0, s = 0;
    while (i < con1.cont && j < con2.cont) {
        if (con1.cto[i] == con2.cto[j]) {
            conFin.cto[s] = con1.cto[i];
            i++; 
            j++;
            s++;
        }else if(con1.cto[i] > con2.cto[j]){
            j++;
        }else if( con1.cto[i] < con2.cto[j]) {
            i++;
        }
    }
    conFin.cont= s;

    return conFin;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    tCto con1;
    con1.cont = 0;
    tCto con2;
    con2.cont = 0;
    // leer los datos de la entrada
    int i = 0;
    cin >> con1.cto[i];
   while(con1.cto[i] != 0) {
       i++;
       cin >> con1.cto[i];
    }
   con1.cont = i;

   int j = 0;
   cin >> con2.cto[j];
   while (con2.cto[j] != 0) {
       j++;
       cin >> con2.cto[j];
   }
   con2.cont = j;

    tCto sol = resolver(con1, con2);

    // escribir solución

   for (int j = 0; j < sol.cont; j++) {
          cout << sol.cto[j] << " ";
   }
      cout << endl;

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













