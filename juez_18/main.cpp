
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
    int tamanyo, capacidad;
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
void ordenar(tListaConsultas& listaConsultas) {
    for (int i = 0; i < listaConsultas.tam; i++) {
        // Desde el primer elemento hasta el penúltimo
        for (int j = i + 1; j < listaConsultas.tam; j++) {
            // Desde i+1 hasta el final
            if (listaConsultas.consulta[j]->fecha < listaConsultas.consulta[i]->fecha) {
                swap(listaConsultas.consulta[j]->fecha, listaConsultas.consulta[i]->fecha);
            }
        }
    }

}

void ampliar(tListaEspecialidades& lista) {
    //Duplica el tama�o

    tEspecialidad* aux = nullptr;

    aux = new tEspecialidad[2 * lista.capacidad];
    for (int i = 0; i < lista.tamanyo; i++)
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
    while (codigoAux != -1) {
        listaConsultas.consulta[listaConsultas.tam] = new tConsulta;
        listaConsultas.consulta[listaConsultas.tam]->codigo = codigoAux;
        cin >> listaConsultas.consulta[listaConsultas.tam]->fecha;
        cin >> listaConsultas.consulta[listaConsultas.tam]->numConsultas;
        listaConsultas.tam++;
        cin >> codigoAux;
    }
    return true;
}

bool cargarEspecialidades(tListaEspecialidades& listaEspec) {
    int codigoAux;
    cin >> codigoAux;
    while (codigoAux != -1) {
        listaEspec.arrayDinamico[listaEspec.tamanyo].codigo = codigoAux;
        getline(cin, listaEspec.arrayDinamico[listaEspec.tamanyo].especialidad);
        listaEspec.tamanyo++;
        if (listaEspec.tamanyo == listaEspec.capacidad)
            ampliar(listaEspec);
        cin >> codigoAux;
    }
    return true;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tListaEspecialidades listaEspecialidades;
    tListaConsultas listaConsultas;
    listaConsultas.tam = 0;

    listaEspecialidades.arrayDinamico = new tEspecialidad[ESPECIALIDADES_INICIALES];
    listaEspecialidades.capacidad = ESPECIALIDADES_INICIALES;
    listaEspecialidades.tamanyo = 0;


    bool encontrado = false;

    if (cargarConsultas(listaConsultas) && cargarEspecialidades(listaEspecialidades)) {
        ordenar(listaConsultas);
        for (int i = 0; i < listaConsultas.tam; i++) {
            for (int j = 0; j < listaEspecialidades.tamanyo; j++) {
                if (listaConsultas.consulta[i]->codigo == listaEspecialidades.arrayDinamico[j].codigo) {
                    cout << listaConsultas.consulta[i]->fecha << listaEspecialidades.arrayDinamico[j].especialidad << " " << listaConsultas.consulta[i]->numConsultas << endl;
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << listaConsultas.consulta[i]->fecha << " Especialidad inexistente" << endl;
            }
            encontrado = false;
        }
    }



    for (int i = 0; i < listaConsultas.tam; i++) {
        delete(listaConsultas.consulta[i]);
        listaConsultas.consulta[i] = nullptr;
    }
    listaConsultas.tam = 0;



    delete[] listaEspecialidades.arrayDinamico;
    listaEspecialidades.arrayDinamico = nullptr;
    listaEspecialidades.tamanyo = 0;
    listaEspecialidades.capacidad = 0;


    // escribir sol --> ESCRIBIMOS LA SOLUCION

    return false;
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
