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
		//int puntuacionTotal = 0;
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
		//Comprobar que guardar bien
	}
	archivo << "000";
	return guardado;
}

void mostrar_minas_usuario(const tPuntuaciones& marcador, int pos)
{

	int puntTotal = 0;

	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) { //Hallo pntos totales
		puntTotal += marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
	}
	//pos se refiere a la posicion donde esta el jugador del que queremos mostrar sus minas

	cout << "\t\t" << marcador.array_clasificacion[pos].nombre << setw(13) << "Movimientos" << setw(8) << "Gemas"
		<< setw(11) << "Dinamitas" << setw(7) << "Puntos " << setw(21) << "Puntos en total" << endl;

	string aux = "";
	for (int i = 0; i < marcador.array_clasificacion[pos].minasRecorridas; i++) {

		cout << "\t\t" << "Mina   " << marcador.array_clasificacion[pos].vMinasRecorridas[i].IdMina
			<< setw(13) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numMovimientos
			<< setw(11) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numGemas
			<< setw(8) << marcador.array_clasificacion[pos].vMinasRecorridas[i].numDinamitas
			<< setw(10) << marcador.array_clasificacion[pos].vMinasRecorridas[i].puntosMina;
		if (i == 0) {
			cout << setw(20) << puntTotal << endl;
		}
		else {
			cout << endl;
		}	
	}
}

void mostrar_alfabetico(const tPuntuaciones& marcador)
{
	cout << "\t\t\t\t" << "--------------LISTA DE JUGADORES ---------" << endl << endl;

	for (int i = 0; i < marcador.num_jugadores; i++) {
		cout << setw(60) << marcador.array_clasificacion[i].nombre << "  " << marcador.array_clasificacion[i].punt_total << endl;
	}
}

void mostrar_datos_usuario(const tPuntuaciones& marcador)
{
	cout << "\t\t\t" << "--------------  JUGADORES ORDENADOS POR NOMBRE ----------" << endl << endl;
	for (int s = 0; s < marcador.num_jugadores; s++) {
		//Me sobra todo esto, mejor llamar a la otra función de arriba
		mostrar_minas_usuario(marcador, s);
	}
}

void inicializar_marcador(tPuntuaciones& marcador)
{
	marcador.capacidad = TAM_INICIAL;
	marcador.num_jugadores = 0;
	marcador.array_clasificacion = new tPuntuacionJugador[TAM_INICIAL];
	//ordenarNombre(marcador);
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
	//marcador.num_jugadores = 0; //Da un poco igual, pero bueno
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
		else { // buscado > lista.elementos[mitad]
			ini = mitad + 1;
		}
	}
	pos = mitad; //Donde debería estar insertado

	return encontrado;
}

void insertar(tPuntuaciones& marcador, string const& nombre, int pos) //TODO
{
	//Damos por hecho que pos es numJugadores 
	// Doy por hecho que el array ya está ordenado, despues de insertar, volvemos a ordenar
	//Debug

	//TODO - insertar en el pos, que NO ES numJugadores 
	if (( pos + 1 )> marcador.capacidad) {
		aumentar_capacidad(marcador);
		marcador.array_clasificacion[pos].nombre = nombre;
		marcador.num_jugadores++;
	}
	else {
		marcador.array_clasificacion[pos].nombre = nombre;
		marcador.num_jugadores++;
	}
	ordenarNombre(marcador);
}

void ordenarNombre(tPuntuaciones& marcador) //ESTO VA A SOBRAR AHORA
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

void ordenarNiveles(tPuntuaciones& marcador){
	for (int z = 0; z < marcador.num_jugadores; z++) { //Ordena los niveles de todos los jugadores
		//Pos se refiere a la posicion donde se encuentra el jugador del que quiero ordenar sus niveles
		bool inter = true;
		int i = 0;
		while ((i < marcador.array_clasificacion[z].minasRecorridas - 1) && inter) {
			// Desde el primer elemento hasta el penúltimo si hay intercambios...
			inter = false;
			for (int j = marcador.array_clasificacion[z].minasRecorridas - 1; j > i; j--) {
				// Desde el último hasta el siguiente a i
				if (marcador.array_clasificacion[z].vMinasRecorridas[j].IdMina <
					marcador.array_clasificacion[z].vMinasRecorridas[j - 1].IdMina) {
					swap(marcador.array_clasificacion[z].vMinasRecorridas[j], marcador.array_clasificacion[z].vMinasRecorridas[j - 1]);
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}
	}
}

void calcularPuntuaciones(tPuntuaciones& marcador, tJuego& juego)
{
	int A = 10;
	int B = 2;
	//int puntuacion = 0;
	int puntTotal = 0;
	//Busco la posicion del jugador que acaba de terminar la mina
	int pos = -1;
		buscar(juego.jugador, marcador, pos); //Devuelve un booleano y no lo trato
	int idMine = -1;
	bool existe = false;
	for (int z = 0; z < marcador.array_clasificacion[pos].minasRecorridas; z++) {
		//CONVERTIR EN UN WHILE CON Booleano y usar solo una variable --> Z
		if (juego.nivel == marcador.array_clasificacion[pos].vMinasRecorridas[z].IdMina) { // Solo se incrementa, si la mina es distinta. Si es la misma, se sobrescribe
			idMine = z;
			existe = true;
		}
	}
	if (!existe) {
		marcador.array_clasificacion[pos].minasRecorridas++; //Es una mina nueva
		idMine = juego.nivel;
	}
	//NO VALE PONER ID MINA, HAY QUE INSERTAR EN ORDEN --> Usar Z
	marcador.array_clasificacion[pos].vMinasRecorridas[idMine].IdMina = idMine;
	marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numMovimientos = juego.contMov;
	juego.contMov = 0; //Lo reseteo
	marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numGemas = juego.contGemas;
	juego.contGemas = 0; //Lo reseteo
	marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numDinamitas = juego.contTNT;
	juego.contTNT = 0; //Lo reseteo
	//Le damos a cada mina su puntuacion
	marcador.array_clasificacion[pos].vMinasRecorridas[idMine].puntosMina = juego.mina.nColumnas * juego.mina.nFilas
		+ A * marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numGemas
		- marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numMovimientos
		- B * marcador.array_clasificacion[pos].vMinasRecorridas[idMine].numDinamitas;
	//Añadimos la puntuacion de la mina a la total
	puntTotal += marcador.array_clasificacion[pos].vMinasRecorridas[idMine].puntosMina;
		
	marcador.array_clasificacion[pos].punt_total = puntTotal;
	
	ordenarNiveles(marcador); //Para que luego no escriba las minas vacías
}
