
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019
// Nombre del problema: Ejercicio 14 del juez, coleccion de fotos con vectores
// Comentario general sobre la solución
// explicando cómo se resuelve el problema: 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_FOTOS = 100;
//ESTRUCTURAS PROPIAS
typedef struct {
    string titulo;
    string tema;
    int matriz[50][50];
}tFoto;
typedef struct {
    int numFotos = 0; //Contador
    tFoto array_fotos[MAX_FOTOS]; //Si pongo 200, peta la pila
}tListaFotos;

typedef struct {
    int contador = 0;
    tFoto* arrayPunt[MAX_FOTOS]; //Si pongo 200, peta la pila
}tArrayPunt;


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
//Estas 2 funciones sustituyen a la de resolver
void ordenarTitulo(tArrayPunt arrayPunteros) {

}

void ordenarTema(tArrayPunt arrayPunteros) {

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char aux;
    tListaFotos lista;
    tArrayPunt array1; //Titulo
    tArrayPunt array2; //Tema

    //PONGO LOS ARRAYS DE PUNTEROS, APUNTANDO A LAS FOTOS
    for (int i = 0; i < MAX_FOTOS; i++) {
        array1.arrayPunt[i] = &lista.array_fotos[i];
        array2.arrayPunt[i] = &lista.array_fotos[i];
    }

    // leer los datos de la entrada
    cin >> lista.numFotos;
    //Leo todos los titulos
    cin.get(aux);
    for (int i = 0; i < lista.numFotos; i++) {
        getline(cin, lista.array_fotos[i].titulo);
        for (int s = 0; s < 50; s++) {
            for (int w = 0; w < 50; w++) {
                lista.array_fotos[i].matriz[s][w] = 3;
            }
        }
    }//
    //Leo todos los temas
    for (int i = 0; i < lista.numFotos; i++) {
       // cin.get(aux);
        getline(cin, lista.array_fotos[i].tema);
    }

    if (lista.numFotos == 0 )
        return false;

    //Solucion sol = resolver(datos);

    // escribir solucion
    
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
