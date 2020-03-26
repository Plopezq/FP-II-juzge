
#include <iostream>
#include <fstream>
#include <vector>
#include "juego.h"

//Pablo Lopez y Sergio Sanchez
// pablop14@ucm.es

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int escala; std::cin >> escala;
    int teclado; std::cin >> teclado;
    //tJuego juego(escala, 0, teclado);
    tJuego juego;
    juego.escalaJuego = escala;
    juego.opcionMov = teclado;
    jugar(juego, std::cin, std::cin);
    //Aqui ya ha realizado el minero todos los movimientos

    dibujar(juego);

    //Mina recorrida o pide rescate
    if (juego.estadoMinero == ABANDONO) {
        cout << "Pide rescate" << endl;
    }
    else {
        cout << "Mina recorrida" << endl;
    }
    /*La funcion resuelveCaso lee los parametros del juego:
     escala del dibujo y entrada de movimientos por teclado; 
     y llama a la funcion jugar. Al llamar a la funcion se 
     utilizara la entrada por consola (std::cin) para el ﬁchero 
     de la mina (entrada) y para el ﬁchero de movimientos 
     (movimientos). Por ultimo muestra si el minero ha salido 
     de la mina, cuantos movimientos ha realizado y cuantas gemas 
     ha recolectado, seguido del plano de la mina cuando el minera 
     ha acabado de excavarla. */
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) { resuelveCaso(); }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
