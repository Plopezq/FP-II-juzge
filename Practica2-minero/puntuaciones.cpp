#include "puntuaciones.h"

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

bool guardar_marcador(tPuntuaciones& marcador)
{
	return false;
}

void mostrar_minas_usuario(const tPuntuaciones& marcador, int cont)
{

	//Cont se refiere a la posicion donde esta el jugador del que queremos mostrar sus minas
	

	cout << "Mira las minas que has recorrido ordenadas por nivel " << endl;
	cout << " Persona1 Movimientos Gemas Dinamitas Puntos Puntos en total " << endl;
	for (int i = 0; i < marcador.array_clasificacion[cont].minasRecorridas; i++) {
		cout << "Mina " << marcador.array_clasificacion[cont].vMinasRecorridas[i].IdMina
			<< " " << marcador.array_clasificacion[cont].vMinasRecorridas[i].numMovimientos
			<< " " << marcador.array_clasificacion[cont].vMinasRecorridas[i].numGemas
			<< " " << marcador.array_clasificacion[cont].vMinasRecorridas[i].numDinamitas
			<< " " << marcador.array_clasificacion[cont].vMinasRecorridas[i].puntosMina << endl;
			
		//TODO poner lospuntos totales, almacenando esta informacion en un string y haciendo el cout despues del for
	}
	

}

void mostrar_alfabetico(const tPuntuaciones& marcador)
{
}

void mostrar_datos_usuario(const tPuntuaciones& marcador)
{
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
	
	delete[] aux; // ¿?
	aux = nullptr;
}

void destruir(tPuntuaciones& marcador)
{
	delete[] marcador.array_clasificacion;
	marcador.array_clasificacion = nullptr;
}

bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos)
{
	//TODO: Queda devolver la posicion donde deberia estar
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
