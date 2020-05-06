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
	return false;
}

void insertar(tPuntuaciones& marcador, string const& nombre, int pos)
{
}
