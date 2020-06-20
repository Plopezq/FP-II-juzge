
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


const int TAM_INICIAL = 3;

//ESTRUCTURAS PROPIAS
typedef struct {
    string nombre;
    int unidades;
}tObjeto;
typedef struct {
    tObjeto* arrayDinam;
    int tam, capacidad;
}tLista;

void ampliar(tLista& almacen) {
    //Duplica el tama�o
    tObjeto* aux = nullptr;
    aux = new tObjeto[2 * almacen.capacidad];
    for (int i = 0; i < almacen.tam; i++)
    {
        aux[i] = almacen.arrayDinam[i];
    }
    for (int j = almacen.capacidad; j < 2 * almacen.capacidad; j++) {
        aux[j].unidades = 0;
    }
    delete[] almacen.arrayDinam; //OJO! usar [] para vectores din�micos
    almacen.arrayDinam = aux;
    almacen.capacidad *= 2;
    aux = nullptr;
}
bool buscar(tLista &almacen, tObjeto& objeto, int& posicion) {
    int pos = 0;
    bool encontrado = false;
    for (int i = 0 ; i < almacen.tam; i++) {
        if (almacen.arrayDinam[i].nombre == objeto.nombre) {
            encontrado = true;
            pos = i;
        }
    }
    if (encontrado) {
        posicion = pos;
        return true;
    }
    else {
        posicion = almacen.tam;
        return false;
    }
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(tLista & almacen, tObjeto& objeto, string operacion) {
    int posicion = 0;
    bool encontrado = buscar(almacen, objeto, posicion);
    //Añadir
    if (operacion == "A") {
        if (almacen.tam == almacen.capacidad) {
            ampliar(almacen);
        }
        //Ya añadimos
        almacen.arrayDinam[posicion].nombre = objeto.nombre;
        almacen.arrayDinam[posicion].unidades += objeto.unidades;
        if (! encontrado) {
            almacen.tam++;
        }
    }
    //Restar si existe
    if (operacion == "R" && almacen.arrayDinam[posicion].nombre == objeto.nombre) {
        if (objeto.unidades > almacen.arrayDinam[posicion].unidades) {
            almacen.arrayDinam[posicion].unidades = 0;
        }
        else {
            almacen.arrayDinam[posicion].unidades -= objeto.unidades;
        }
    }


}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    //INICIALIZAMOS TODO
    tObjeto objeto;
    objeto.nombre = "";
    objeto.unidades = 0;

    tLista almacen;
    almacen.capacidad = TAM_INICIAL;
    almacen.tam = 0;
    almacen.arrayDinam = new tObjeto[TAM_INICIAL];
    for (int j = 0; j < almacen.capacidad; j++) {
        almacen.arrayDinam[j].unidades = 0;
    }

    //Leeemos los datos    
    bool acabar = false;
    while (!acabar) {
        string operacion = "";
        cin >> operacion;
        if (operacion == "F") acabar = true;

        if (operacion == "L") {//La operacion es listar
            //Hacer bucle for
            for (int s = 0; s < almacen.tam; s++) {
                cout << almacen.arrayDinam[s].nombre << " " << almacen.arrayDinam[s].unidades << endl;
            }
            cout << "---" << endl;
        }

        if (!acabar && operacion != "L") {
            cin >> objeto.nombre;
            cin >> objeto.unidades;
            resolver(almacen, objeto, operacion);
        }

    }


    delete[] almacen.arrayDinam;
    almacen.arrayDinam = nullptr;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
