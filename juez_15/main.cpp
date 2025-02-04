
// Autor/a: Pablo L�pez y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019
// Nombre del problema: Ejercicio 14 del juez, coleccion de fotos con vectores
// Comentario general sobre la soluci�n
// explicando c�mo se resuelve el problema: 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_FOTOS = 200;
const int MAX = 200; //Ahora ya si puedo poner 200 ya que est� todo en memoria din�mica y no se llena
//ESTRUCTURAS PROPIAS
typedef struct {
    string titulo;
    string tema;
    int matriz[MAX][MAX];
}tFoto;

typedef struct {
    int contador = 0;
    tFoto* arrayPunt[MAX_FOTOS];
}tArrayPunt;

typedef struct {
    int contador = 0;
    tFoto* lista;
}tArrayDinFotos;

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
//Estas 2 funciones sustituyen a la de resolver
void ordenarTitulo(tArrayPunt& arrayPunt) {

    bool inter = true;
    int i = 0;
    while ((i < arrayPunt.contador - 1) && inter) {
        // Desde el primer elemento hasta el pen�ltimo si hay intercambios...
        inter = false;
        for (int j = arrayPunt.contador - 1; j > i; j--) {
            // Desde el �ltimo hasta el siguiente a i
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
        // Desde el primer elemento hasta el pen�ltimo si hay intercambios...
        inter = false;
        for (int j = arrayPunt.contador - 1; j > i; j--) {
            // Desde el �ltimo hasta el siguiente a i
            if (arrayPunt.arrayPunt[j]->tema < arrayPunt.arrayPunt[j - 1]->tema) {
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
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
    char aux;

   // tListaFotos lista;
    tArrayDinFotos arrayDin;
    arrayDin.lista = new tFoto[MAX_FOTOS];

    tArrayPunt array1; //Titulo
    tArrayPunt array2; //Tema


    for (int i = 0; i < MAX_FOTOS; i++) {
        array1.arrayPunt[i] = nullptr;
        array2.arrayPunt[i] = nullptr;
    }

    //PONGO LOS ARRAYS DE PUNTEROS, APUNTANDO A LAS FOTOS
    for (int i = 0; i < MAX_FOTOS; i++) {
        array1.arrayPunt[i] = &arrayDin.lista[i];
        array2.arrayPunt[i] = &arrayDin.lista[i];
    }

    // leer los datos de la entrada
    cin >> arrayDin.contador;
    array1.contador = arrayDin.contador;
    array2.contador = arrayDin.contador;
    //Leo todos los titulos
    cin.get(aux);
    for (int i = 0; i < arrayDin.contador; i++) {
        getline(cin, arrayDin.lista[i].titulo);
        //Inicializo la matriz
        for (int s = 0; s < MAX; s++) {
            for (int w = 0; w < MAX; w++) {
                arrayDin.lista[i].matriz[s][w] = 3;
            }
        }
    }
    //Leo todos los temas
    for (int i = 0; i < arrayDin.contador; i++) {
        // cin.get(aux);
        getline(cin, arrayDin.lista[i].tema);
    }

    if (arrayDin.contador == 0) {
        delete[] arrayDin.lista;
        arrayDin.lista = NULL;
        return false;
    }

    //Solucion sol = resolver(datos);
    ordenarTitulo(array1);
    ordenarTema(array2);
    // escribir solucion
    for (int z = 0; z < array1.contador; z++) {
        cout << array1.arrayPunt[z]->titulo << endl;
    }

    cout << endl;
    for (int z = 0; z < array2.contador; z++) {
        cout << array2.arrayPunt[z]->tema << " - " << array2.arrayPunt[z]->titulo << endl;

    }
    cout << endl;

    delete[] arrayDin.lista;
    arrayDin.lista = NULL;
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
