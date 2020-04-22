 
// Autor/a: Nombre y apellidos
// email:
// Compilador y S.O. utilizado
// Nombre del problema
// Comentario general sobre la solución
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
    int sudoku[9][9];
}tSudoku;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(const tSudoku& sudoku) {
    int auxFilas = 0;
    int auxColumnas = 0;
    bool correcto = true;
    //Compruebo columnas
    for (int i = 0; i < 9; i++) { //Recorre las columnas
        auxFilas = 0;
        for (int j = 0; j < 9; j++) { //Recorre las filas
            auxFilas += sudoku.sudoku[i][j];
        }
        if (auxFilas != 45) {
            correcto = false;
        }
    }

    //Compruebo filas
    for (int j = 0; j < 9; j++) { //Recorre las columnas
        auxColumnas = 0;
        for (int i = 0; i < 9; i++) { //Recorre las filas
            auxColumnas += sudoku.sudoku[i][j];
        }
        if (auxColumnas != 45) {
            correcto = false;
        }
    }

    //Compruebo cuadrantes
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ( (i == 0 && j == 0)||(i == 0 && j == 3)||(i == 0 && j == 6)||
                (i == 3 && j == 0 )||(i == 3 && j == 3)||(i == 3 && j == 6)||
                (i == 6 && j == 0 )||(i == 6 && j == 3)||(i == 6 && j == 6) ) {
                int aux = 0;
                for (int w = i; w < i + 3; w++) {
                    for (int s = j; s < j + 3; s++) {
                        aux += sudoku.sudoku[w][s];
                    }
                }
                if (aux != 45) {
                    correcto = false;
                }
            }
        }
    }



    return correcto;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    tSudoku sudoku;
    // leer los datos de la entrada
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku.sudoku[i][j];
        }
    }
    bool sol = resolver(sudoku);

    // escribir solución
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
