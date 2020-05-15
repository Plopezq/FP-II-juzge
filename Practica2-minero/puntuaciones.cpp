﻿#include "puntuaciones.h"
#include <string>
#include <iomanip>

bool cargar_marcador(tPuntuaciones& marcador)
{
	bool acabado = false;
	string aux = "Puntuaciones.txt";
	ifstream archivo;
	archivo.open(aux);
	if (archivo.is_open()) {
		int i = 0;
		string aux = "";
		while (!acabado) {
			archivo >> aux;
			if ( aux == "000") {
				acabado = true;
			}
			else {
				marcador.array_clasificacion[i].nombre = aux;
				archivo >> marcador.array_clasificacion[i].punt_total;
				archivo >> marcador.array_clasificacion[i].minasRecorridas;
				for (int s = 0; s < marcador.array_clasificacion[i].minasRecorridas; s++ ) {// For para las minas recorridas
					archivo >> marcador.array_clasificacion[i].vMinasRecorridas[s].IdMina;
					archivo >> marcador.array_clasificacion[i].vMinasRecorridas[s].numMovimientos;
					archivo >> marcador.array_clasificacion[i].vMinasRecorridas[s].numGemas;
					archivo >> marcador.array_clasificacion[i].vMinasRecorridas[s].numDinamitas;
					archivo >> marcador.array_clasificacion[i].vMinasRecorridas[s].puntosMina;
					
				}
				marcador.num_jugadores++; //Se ha añadido un jugador
				i++;
			}
		}
		archivo.close();
	}
	return acabado;
}

bool guardar_marcador(tPuntuaciones& marcador, tJuego juego)
{
	calcularPuntuaciones(marcador, juego.mina);

	bool guardado = false;

	ofstream archivo;
	archivo.open("puntuaciones.txt"); //Apertura

	for (int i = 0; i < marcador.num_jugadores; i++) {
		//int puntuacionTotal = 0;

		archivo << marcador.array_clasificacion[i].nombre << endl
			<< marcador.array_clasificacion[i].punt_total << endl
			<< marcador.array_clasificacion[i].minasRecorridas << endl;
		for (int m = 0; m < marcador.array_clasificacion[i].minasRecorridas; m++) {
			archivo << marcador.array_clasificacion[i].vMinasRecorridas[m].IdMina << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numMovimientos << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numGemas << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numDinamitas << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].puntosMina;
		}
	}
	return guardado;
}

void mostrar_minas_usuario(const tPuntuaciones& marcador, int pos)
{

	int puntTotal = 0;

	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) { //Hallo pntos totales
		puntTotal += marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
	}
	//pos se refiere a la posicion donde esta el jugador del que queremos mostrar sus minas
	cout << "\t\t\t"<< "Mira las minas que has recorrido ordenadas por nivel " << endl << endl;

	cout << "\t\t" << marcador.array_clasificacion[pos].nombre << setw(15) << "Movimientos" << setw(15) << "Gemas"
		<< setw(15) << "Dinamitas" << setw(15) << "Puntos " << setw(30) << "Puntos en total" << endl;

	string aux = "";
	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) {

		cout << "\t\t" << "Mina  "<< marcador.array_clasificacion[pos].vMinasRecorridas[i].IdMina
			<< setw(15) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numMovimientos
			<< setw(15) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numGemas
			<< setw(15) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numDinamitas
			<< setw(15) << marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
		if (i == 0) {
			 cout << setw(30) << puntTotal << endl;
		}
		else {
			cout << endl;
		}
			
			
	}

}

void mostrar_alfabetico(const tPuntuaciones& marcador)
{
	cout << "\t\t\t" << "Mira las puntuaciones de otros jugadores: " << endl << endl;
	cout << "\t\t\t\t" << "--------------LISTA DE JUGADORES -------" << endl << endl;

	for (int i = 0; i < marcador.num_jugadores; i++) {
		cout << setw(60) << marcador.array_clasificacion[i].nombre << "  " << marcador.array_clasificacion[i].punt_total << endl;
	}

}

void mostrar_datos_usuario(const tPuntuaciones& marcador)
{
	cout << "\t\t\t" << "--------------  JUGADORES ORDENADOS POR NOMBRE ----------" << endl << endl;
	for (int s = 0; s < marcador.num_jugadores; s++) {

		int puntTotal = 0;
		for (int i = 0; i < marcador.array_clasificacion[s].minasRecorridas; i++) { //Hallo pntos totales
			puntTotal += marcador.array_clasificacion[s].vMinasRecorridas[i].puntosMina;
		}
		//pos se refiere a la posicion donde esta el jugador del que queremos mostrar sus minas

		cout << "\t" << marcador.array_clasificacion[s].nombre << setw(15) << "Movimientos" << setw(15) << "Gemas"
			<< setw(15) << "Dinamitas" << setw(15) << "Puntos " << setw(30) << "Puntos en total" << endl;

		string aux = "";
		for (int i = 0; i < marcador.array_clasificacion[s].minasRecorridas; i++) {

			cout << "\tMina  " << setw(15)<< marcador.array_clasificacion[s].vMinasRecorridas[i].IdMina
				<< setw(15) << marcador.array_clasificacion[s].vMinasRecorridas[i].numMovimientos
				<< setw(15) << marcador.array_clasificacion[s].vMinasRecorridas[i].numGemas
				<< setw(15) << marcador.array_clasificacion[s].vMinasRecorridas[i].numDinamitas
				<< setw(15) << marcador.array_clasificacion[s].vMinasRecorridas[i].puntosMina;
			if (i == 0) {
				cout << setw(30) << puntTotal << endl;
			}
			else {
				cout << endl;
			}


		}
	}
}

void inicializar_marcador(tPuntuaciones& marcador)
{
	marcador.capacidad = TAM_INICIAL;
	marcador.num_jugadores = 0;
	marcador.array_clasificacion = new tPuntuacionJugador[TAM_INICIAL];

	ordenarNombre(marcador);
}

void aumentar_capacidad(tPuntuaciones& marcador)
{
	//cout << "Se ha llamdo a duplicar tama�o con lista.tam= " << lista.tam << endl;

	tPuntuacionJugador* aux = nullptr;
	aux = new tPuntuacionJugador[2 * marcador.capacidad];
	for (int i = 0; i < marcador.num_jugadores ; i++)
	{
		aux[i] = marcador.array_clasificacion[i];
	}
	delete[] marcador.array_clasificacion; //OJO! usar [] para vectores din�micos
	marcador.array_clasificacion = aux;
	marcador.capacidad *= 2;
	
	//delete[] aux; // ¿?
	//aux = nullptr;
}

void destruir(tPuntuaciones& marcador)
{
	delete[] marcador.array_clasificacion;
	marcador.array_clasificacion = nullptr;
}

bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos)
{
	pos = -1;
	int ini = 0, fin = marcador.num_jugadores - 1, mitad;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (nombre == marcador.array_clasificacion[mitad].nombre) {
			encontrado = true;
		}
		else if (nombre < marcador.array_clasificacion[mitad].nombre) {
			fin = mitad - 1;
		}
		else { // buscado > lista.elementos[mitad]
			ini = mitad + 1;
		}
	}
	if (encontrado) {
		pos = mitad;
	}

	return encontrado;
}

void insertar(tPuntuaciones& marcador, string const& nombre, int pos)
{
	//Damos por hecho que pos es numJugadores 
	// Doy por hecho que el array ya está ordenado, despues de insertar, volvemos a ordenar
	//Debug
	if (pos > marcador.capacidad) {
		aumentar_capacidad(marcador);
		marcador.array_clasificacion[pos - 1].nombre = nombre;
		marcador.num_jugadores++;
	}
	else {
		marcador.array_clasificacion[pos - 1].nombre = nombre;
		marcador.num_jugadores++;
	}
	ordenarNombre(marcador);
}

void ordenarNombre(tPuntuaciones& marcador) //Ordena
{
	bool inter = true;
	int i = 0;
	while ((i < marcador.num_jugadores - 1) && inter) {
		// Desde el primer elemento hasta el penúltimo si hay intercambios...
		inter = false;
		for (int j = marcador.num_jugadores - 1; j > i; j--) {
			// Desde el último hasta el siguiente a i
			if (marcador.array_clasificacion[j].nombre < marcador.array_clasificacion[j - 1].nombre) {
				swap(marcador.array_clasificacion[j], marcador.array_clasificacion[j - 1]);
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}

void ordenarNivel(tPuntuaciones& marcador, int pos)
{

	//Pos se refiere a la posicion donde se encuentra el jugador del que quiero ordenar sus niveles
	bool inter = true;
	int i = 0;
	while ((i < marcador.num_jugadores - 1) && inter) {
		// Desde el primer elemento hasta el penúltimo si hay intercambios...
		inter = false;
		for (int j = marcador.num_jugadores - 1; j > i; j--) {
			// Desde el último hasta el siguiente a i
			if (marcador.array_clasificacion[pos].vMinasRecorridas[j].IdMina < 
				marcador.array_clasificacion[pos].vMinasRecorridas[j - 1].IdMina) {

				swap(marcador.array_clasificacion[pos].vMinasRecorridas[j].IdMina, 
					marcador.array_clasificacion[pos].vMinasRecorridas[j - 1].IdMina);

				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}
}

void calcularPuntuaciones(tPuntuaciones& marcador, tMina mina)
{
	const int A = 10;
	const int B = 2;
	int puntuacion = 0;

	for (int i = 0; i < marcador.num_jugadores; i++) { //Recorremos los jugadores
		for (int m = 0; m < marcador.array_clasificacion[i].minasRecorridas; m++) {//Recorremos todas las  minas de cada jugador
			//Le damos a cada mina su puntuacion
			marcador.array_clasificacion[i].vMinasRecorridas[m].puntosMina = mina.nColumnas * mina.nFilas 
				+ A * marcador.array_clasificacion[i].vMinasRecorridas[m].numGemas 
				- marcador.array_clasificacion[i].vMinasRecorridas[m].numMovimientos
				- B * marcador.array_clasificacion[i].vMinasRecorridas[m].numDinamitas;
			//Añadimos la puntuacion de la mina a la total
			marcador.array_clasificacion[i].punt_total += marcador.array_clasificacion[i].vMinasRecorridas[m].puntosMina;
		}
	}
}
