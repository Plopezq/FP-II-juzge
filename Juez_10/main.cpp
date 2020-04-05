
// Autor/a: Pablo López y Sergio Sanchez
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: Visual Studio 2019 y Windows 10 Education
// Nombre del problema: Puntos de silla
// Comentario general sobre la solución
// explicando cómo se resuelve el problema:

#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    int numFilas = 0;
    int numColumnas = 0;
    int plano[100][100];
}tCaso;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(tCaso caso) {
    int num1 = 9;
    //bool resul = false;
    int fila = 0;
    int columna = 0;

    //Aqui buscamos el menor de la fila y el mayor de la columna
    for (int i = 0; i < caso.numFilas; i++) {
        for (int j = 0; j < caso.numColumnas; j++) {
            num1 = caso.plano[i][j];
            fila = 0;
            columna = 0;
            for (int s = 0; s < caso.numColumnas; s++ ) {//Recorremos la fila para saber si es el menor
                if (num1 <= caso.plano[i][s]) {
                    fila++;
                }
            }
            //Ahora que sabemos que es el menor de la fila, 
            // comprobamos que es el mayor de la columna
            for (int w = 0; w < caso.numFilas; w++) { //Recorremos la columnas para saber si es el mayor
                if (num1 >= caso.plano[w][j]) {
                    columna++;
                }
            }

            if ( (fila == caso.numColumnas)  && (columna == caso.numFilas )) {
                return true;
            }
        }
    }


    //Aqui buscamos el mayor de la fila y el menor de la columna
    for (int i = 0; i < caso.numFilas; i++) {
        for (int j = 0; j < caso.numColumnas; j++) {
            num1 = caso.plano[i][j];
            fila = 0;
            columna = 0;
            for (int s = 0; s < caso.numColumnas; s++) {//Recorremos la fila para saber si es el mayor
                if (num1 >= caso.plano[i][s]) {
                    fila++;
                }
            }
            //Ahora que sabemos que es el mayor de la fila, 
            // comprobamos que es el menor de la columna
            for (int w = 0; w < caso.numFilas; w++) { //Recorremos la columnas para saber si es el menor
                if (num1 <= caso.plano[w][j]) {
                    columna++;
                }
            }

            if ((fila == caso.numColumnas) && (columna == caso.numFilas)) {
                return true;
            }
        }
    }

    return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tCaso caso;

    //Inicializar el plano
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <100; j++) {
            caso.plano[i][j] = -1;
        }
    }
    // leer los datos de la entrada
    cin >> caso.numFilas;
    cin >> caso.numColumnas;

    if (caso.numFilas == 0 && caso.numColumnas == 0)
        return false;

    for (int i = 0; i < caso.numFilas; i++) {
        for (int j = 0; j < caso.numColumnas; j++) {
            cin >> caso.plano[i][j];
        }
    }

    bool sol = resolver(caso);

    // escribir sol
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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
