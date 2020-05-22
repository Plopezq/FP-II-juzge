/*
*
* Pablo Lopez Martin
*
* Sergio Sanchez Chamizo
*
*/
#include "puntuaciones.h"
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
			if (i >= marcador.capacidad) {
				aumentar_capacidad(marcador);
			}
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

bool guardar_marcador(tPuntuaciones& marcador, tJuego &juego)
{
	calcularPuntuaciones(marcador, juego);
	//Escribir en fichero
	bool guardado = false;
	ofstream archivo;
	archivo.open("puntuaciones.txt"); //Apertura
	for (int i = 0; i < marcador.num_jugadores; i++) {
		archivo << marcador.array_clasificacion[i].nombre << endl
			<< marcador.array_clasificacion[i].punt_total << endl
			<< marcador.array_clasificacion[i].minasRecorridas << endl;
		for (int m = 0; m < marcador.array_clasificacion[i].minasRecorridas; m++) {
			archivo << marcador.array_clasificacion[i].vMinasRecorridas[m].IdMina << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numMovimientos << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numGemas << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].numDinamitas << " "
				<< marcador.array_clasificacion[i].vMinasRecorridas[m].puntosMina << endl;
		}
	}
	archivo << "000";
	return guardado;
}

void mostrar_minas_usuario(const tPuntuaciones& marcador, int pos){
	//pos se refiere a la posicion donde esta el jugador del que queremos mostrar sus minas
	int puntTotal = 0;
	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) { //Hallo pntos totales
		puntTotal += marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
	}
	cout << left << setw(18)  << marcador.array_clasificacion[pos].nombre << left << setw(20) << "Movimientos" << left << setw(8) << "Gemas"
		<< left << setw(11) << "Dinamitas" << left << setw(12) << "Puntos " << left << setw(20) << "Puntos en total" << endl;
	string aux = "";
	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) {
		cout << setw(18) << "Mina " + to_string( marcador.array_clasificacion[pos].vMinasRecorridas[i].IdMina)
			 << setw(20) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numMovimientos
			 << setw(8) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numGemas
			 << setw(11) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numDinamitas
			 << setw(12) << marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
		if (i == 0) {
			cout  << setw(20) << puntTotal << endl;
		}
		else {
			cout << endl;
		}	
	}
}
void mostrar_alfabetico(const tPuntuaciones& marcador){
	cout << "\t\t\t" << internal << "--------------LISTA DE JUGADORES ---------" << endl << endl;
	for (int i = 0; i < marcador.num_jugadores; i++) {
		cout << "\t\t\t" << marcador.array_clasificacion[i].nombre << "  " << marcador.array_clasificacion[i].punt_total << endl;
	}
}

void mostrar_datos_usuario(const tPuntuaciones& marcador){
	cout << setw(20) << "--------------  JUGADORES ORDENADOS POR NOMBRE ----------" << endl << endl;
	for (int s = 0; s < marcador.num_jugadores; s++) {
		 mostrar_minas_usuario(marcador, s);
	}
}

void inicializar_marcador(tPuntuaciones& marcador){
	marcador.capacidad = TAM_INICIAL;
	marcador.num_jugadores = 0;
	marcador.array_clasificacion = new tPuntuacionJugador[TAM_INICIAL];
}

void aumentar_capacidad(tPuntuaciones& marcador){
	tPuntuacionJugador* aux = nullptr;
	aux = new tPuntuacionJugador[2 * marcador.capacidad];
	for (int i = 0; i < marcador.num_jugadores ; i++)
	{
		aux[i] = marcador.array_clasificacion[i];
	}
	delete[] marcador.array_clasificacion; 
	marcador.array_clasificacion = aux;
	marcador.capacidad *= 2;
}

void destruir(tPuntuaciones& marcador){
	delete[] marcador.array_clasificacion;
	marcador.array_clasificacion = nullptr;
}

bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos){
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
		else if(nombre > marcador.array_clasificacion[mitad].nombre) { // buscado > lista.elementos[mitad]
			ini = mitad + 1;
		}
	}
	pos = mitad; //Donde debería estar insertado
	if (!encontrado) { //Para que funcione correctamente
		if (nombre > marcador.array_clasificacion[marcador.num_jugadores - 1].nombre) {
			pos = marcador.num_jugadores;
		}
		else if (nombre < marcador.array_clasificacion[0].nombre) {
			pos = 0;
		}
	}
	return encontrado;
}

void insertar(tPuntuaciones& marcador, string const& nombre, int pos){
	//"pos" es la posicion donde deberia estar el jugador, lo insertamos ahi 
	if (( marcador.num_jugadores + 1 ) > marcador.capacidad) {
		aumentar_capacidad(marcador);
	}
	int aux = marcador.num_jugadores; //Comienza en la ultima posicion del array de jugadores, que está libre
	while (aux > pos) { //Desplazo los jugadores
		swap(marcador.array_clasificacion[aux], marcador.array_clasificacion[aux - 1]);
		aux--;
	}
	marcador.array_clasificacion[pos].nombre = nombre;
	marcador.num_jugadores++;
}
void ordenarNiveles(tPuntuaciones& marcador, int pos){
	//Pos se refiere a la posicion donde se encuentra el jugador del que quiero ordenar sus niveles
	bool inter = true;
	int i = 0;
	while ((i < marcador.array_clasificacion[pos].minasRecorridas - 1) && inter) {
		// Desde el primer elemento hasta el penúltimo si hay intercambios...
		inter = false;
		for (int j = marcador.array_clasificacion[pos].minasRecorridas - 1; j > i; j--) {
			// Desde el último hasta el siguiente a i
			if (marcador.array_clasificacion[pos].vMinasRecorridas[j].IdMina <
				marcador.array_clasificacion[pos].vMinasRecorridas[j - 1].IdMina) {
				swap(marcador.array_clasificacion[pos].vMinasRecorridas[j], marcador.array_clasificacion[pos].vMinasRecorridas[j - 1]);
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}	
}

void calcularPuntuaciones(tPuntuaciones& marcador, tJuego& juego){
	int A = 10;
	int B = 2;
	//int puntuacion = 0;
	int puntTotal = 0;
	//Busco la posicion del jugador que acaba de terminar la mina
	int pos = -1;
	buscar(juego.jugador, marcador, pos); //Devuelve un booleano y no lo trato porque ya tengo el jugador el struct de juego, se que existe
	int contMina = -1;
	bool existe = false;
	while (contMina < marcador.array_clasificacion[pos].minasRecorridas && !existe) {
		contMina++;
		if (juego.nivel == marcador.array_clasificacion[pos].vMinasRecorridas[contMina].IdMina) { // Solo se incrementa, si la mina es distinta. Si es la misma, se sobrescribe
			existe = true;
		}
	}
	if (!existe) {
		marcador.array_clasificacion[pos].minasRecorridas++; //Es una mina nueva
	}
	marcador.array_clasificacion[pos].vMinasRecorridas[contMina].IdMina = juego.nivel;
	marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numMovimientos = juego.contMov;
	juego.contMov = 0; //Lo reseteo
	marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numGemas = juego.contGemas;
	juego.contGemas = 0; //Lo reseteo
	marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numDinamitas = juego.contTNT;
	juego.contTNT = 0; //Lo reseteo
	//Le damos la puntuacion a la mina
	marcador.array_clasificacion[pos].vMinasRecorridas[contMina].puntosMina = juego.mina.nColumnas * juego.mina.nFilas
		+ A * marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numGemas
		- marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numMovimientos
		- B * marcador.array_clasificacion[pos].vMinasRecorridas[contMina].numDinamitas;
	//Añadimos la puntuacion de la mina a la total del jugador
	puntTotal += marcador.array_clasificacion[pos].vMinasRecorridas[contMina].puntosMina;
		
	marcador.array_clasificacion[pos].punt_total = puntTotal;

	ordenarNiveles(marcador, pos); //Para que luego no escriba las minas vacías
}
