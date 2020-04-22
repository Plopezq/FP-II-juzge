// Autor/a: Pablo López Martín
// email: pablop14@ucm.es
// Compilador y S.O. utilizado: VS profesional 2019 
// Nombre del problema: Ordenar por el método de insercción
// Comentario general sobre la solución: Datos de entrada limitados
#include <iostream> 
#include <fstream> 
using namespace std;
const int N = 100; 
typedef int tLista[N];
// función que resuelve el problema de ordenar los “total” elementos de la “lista” 

void resolver(tLista &lista, int total) {
	int nuevo;
	int pos;
// Introducir el código que corresponda
	for (int i = 1; i < total; i++) {
		nuevo = lista[i];
		pos = 0;
		while ((pos < i) && (lista[pos] < nuevo)) { //Mientras las posiciones de la izq sea menor que la que estamos actualmente
			pos++;
		}
		// pos: índice del primer mayor; i si no lo hay
		for (int j = i; j > pos; j--) { //Desplazaría todo a la derecha, si el elemento nuevo se debiera insertar a la izq
			lista[j] = lista[j - 1];
		}
		lista[pos] = nuevo;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada que es una secuencia de números que 
// finaliza cuando se encuentra al centinela “0” 
// Se escribe la secuencia de números separados por un espacio
void resuelveCaso() { 
	// leer la secuencia de números que finaliza con el centinela “0” 
	// y se almacenan en un array llamado “lista”
	tLista lista; 
	int num, i = 0;

	cin >> num; 
	while (num != 0){ 
		lista[i] = num; 
		i++; 
		cin >> num; 
	
	}
// Es necesario pasar el número de elementos que contiene la lista 
	resolver(lista, i);
// Escribo la secuencia de números ordenados, separados por un espacio en blanco 
	
	for (int j = 0; j < i; j++) {
		cout << lista[j] << " ";
	}
		cout << endl; 

}

int main(){ 
// ajustes para que cin extraiga directamente de un fichero 

#ifndef DOMJUDGE 
	std::ifstream in("datos.in"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
	std::ofstream out("datos.out"); 
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	// caso de pruebas limitados (4 casos). 
	int numCasos; 
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	// para dejar todo como estaba al principio 

#ifndef DOMJUDGE std::cin.rdbuf(cinbuf); 
	std::cout.rdbuf(coutbuf); 
	system("PAUSE"); 
#endif return 0; 
}