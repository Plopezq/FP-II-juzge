
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
const int MAX_FOTOS = 200;
const int MAX = 2; //Disminuyo el tamaño de las matrices, ya que no se van a usar. Y esque sino, se llena la pila y da error el juez.
//ESTRUCTURAS PROPIAS
typedef struct {
    string titulo;
    string tema;
    int matriz[MAX][MAX];
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
void ordenarTitulo(tArrayPunt & arrayPunt) {

    bool inter = true;
    int i = 0;
    while ((i < arrayPunt.contador - 1) && inter) {
        // Desde el primer elemento hasta el penúltimo si hay intercambios...
        inter = false;
        for (int j = arrayPunt.contador - 1; j > i; j--) {
            // Desde el último hasta el siguiente a i
            if (arrayPunt.arrayPunt[j]->titulo < arrayPunt.arrayPunt[j - 1]->titulo) {
                swap(arrayPunt.arrayPunt[j], arrayPunt.arrayPunt[j - 1]);
                inter = true;
            }
        }
        if (inter) {
            i++;
        }
    }
}

void ordenarTema(tArrayPunt& arrayPunt) {

    ordenarTitulo(arrayPunt);

    bool inter = true;
    int i = 0;
    while ((i < arrayPunt.contador - 1) && inter) {
        // Desde el primer elemento hasta el penúltimo si hay intercambios...
        inter = false;
        for (int j = arrayPunt.contador - 1; j > i; j--) {
            // Desde el último hasta el siguiente a i
            if (arrayPunt.arrayPunt[j]->tema < arrayPunt.arrayPunt[j - 1]->tema ) {
              
                swap(arrayPunt.arrayPunt[j], arrayPunt.arrayPunt[j - 1]);
                inter = true;

            }
        }
        if (inter) {
            i++;
        }
    }


}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char aux;

    tListaFotos lista;
    tArrayPunt array1; // Titulo
    tArrayPunt array2; // Tema

      //Inicializo a null los punteros
    for (int i = 0; i < MAX_FOTOS; i++) {
        array1.arrayPunt[i] = nullptr;
        array2.arrayPunt[i] = nullptr;
    }

    //PONGO LOS ARRAYS DE PUNTEROS, APUNTANDO A LAS FOTOS


    // leer los datos de la entrada
    cin >> lista.numFotos;

    //Leo todos los titulos
    cin.get(aux);
    for (int i = 0; i < lista.numFotos; i++) {
        getline(cin, lista.array_fotos[i].titulo);
        for (int s = 0; s < MAX; s++) {
            for (int w = 0; w < MAX; w++) {
                lista.array_fotos[i].matriz[s][w] = 3;
            }
        }
        array1.contador = lista.numFotos;
        array2.contador = lista.numFotos;
    }
    //Leo todos los temas
    for (int i = 0; i < lista.numFotos; i++) {
       // cin.get(aux);
        getline(cin, lista.array_fotos[i].tema);
    }

    for (int i = 0; i < MAX_FOTOS; i++) {
        array1.arrayPunt[i] = &lista.array_fotos[i];
        array2.arrayPunt[i] = &lista.array_fotos[i];
    }

    if (lista.numFotos == 0 )
        return false;

    //Solucion sol = resolver(datos);
    ordenarTitulo(array1);
    ordenarTema(array2);
    // escribir solucion
    for (int z = 0; z < array1.contador; z++) {
        cout << array1.arrayPunt[z]->titulo << endl;
    }

    cout << endl;
    for (int z = 0; z < array1.contador; z++) {
        cout << array2.arrayPunt[z]->tema << " - " << array2.arrayPunt[z]->titulo << endl;

    }
    cout << endl;

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
