
// Autor/a: Pablo Lopez y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019
// Nombre del problema: ordenar consultas por fecha
// Comentario general sobre la solución
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<string>

using namespace std;
const int N = 20;
const int ESPECIALIDADES_INICIALES = 2;

//Array dinamico de especialidades
typedef struct {
    int codigo;
    string especialidad;
}tEspecialidad;
typedef struct {
    tEspecialidad* arrayDinamico;
    int tamaño, capacidad;
}tListaEspecialidades;

//Array de punteros
typedef struct {
    int codigo;
    string fecha;
    int numConsultas;
}tConsulta;
typedef struct {
    tConsulta* consulta[N];
    int tam;
}tListaConsultas;


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(tListaConsultas& listaConsultas) {

}

void ampliar(tListaEspecialidades& lista) {
    //Duplica el tama�o

    tEspecialidad* aux = nullptr;

    aux = new tEspecialidad[2 * lista.capacidad];
    for (int i = 0; i < lista.tamaño; i++)
    {
        aux[i] = lista.arrayDinamico[i];
    }
    delete[] lista.arrayDinamico; //OJO! usar [] para vectores din�micos
    lista.arrayDinamico = aux;
    lista.capacidad *= 2;
    aux = nullptr;
}

bool cargarConsultas(tListaConsultas& listaConsultas) {

    // leer los datos de la entrada
    int codigoAux;
    cin >> codigoAux;
    while (codigoAux != -1 ) {
        listaConsultas.consulta[listaConsultas.tam] = new tConsulta;
        listaConsultas.consulta[listaConsultas.tam]->codigo = codigoAux;
        cin >> listaConsultas.consulta[listaConsultas.tam]->fecha;
        cin >> listaConsultas.consulta[listaConsultas.tam]->numConsultas;
        listaConsultas.tam++;
        cin >> codigoAux;
    }
}

bool cargarEspecialidades(tListaEspecialidades & listaEspec) {
    int codigoAux;
    cin >> codigoAux;
    while (codigoAux != -1) {
        if (listaEspec.tamaño == listaEspec.capacidad)
            ampliar(listaEspec);
        listaEspec.arrayDinamico[listaEspec.tamaño].codigo = codigoAux;
        getline(cin, listaEspec.arrayDinamico[listaEspec.tamaño].especialidad);
        listaEspec.tamaño++;
        cin >> codigoAux;

    }
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tListaConsultas listaConsultas;
    listaConsultas.tam = 0;
    tListaEspecialidades listaEspecialidades;

    listaEspecialidades.capacidad = ESPECIALIDADES_INICIALES;
    listaEspecialidades.tamaño = 0;


 

    //Ordenamos las consultas
    resolver(listaConsultas);

    // escribir sol --> ESCRIBIMOS LA SOLUCION

    return true;
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
