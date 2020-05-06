#include"juego.h"

const int NUM_NIVELES = 5;
const int TAM_INICIAL = 2;
typedef struct {
	int IdMina = 0;
	int numMovimientos = 0;
	int numGemas = 0;
	int numDinamitas = 0;
	int puntosMina = 0;
} tDatosMina;

typedef struct {
	string nombre;
	int punt_total = 0;
	int minasRecorridas = 0;
	tDatosMina vMinasRecorridas[NUM_NIVELES];
} tPuntuacionJugador;
//Array din�mico de tPuntuacionJugador
typedef struct {
	int capacidad;
	int num_jugadores;
	tPuntuacionJugador* array_clasificacion;
} tPuntuaciones; 

//PROTOTIPOS
bool cargar_marcador(tPuntuaciones& marcador);	// Introduce en el array din�mico los datos disponibles en el fichero Puntuaciones.txt
bool guardar_marcador(tPuntuaciones& marcador); // Vuelca el contenido del array din�mico en el fichero Puntuaciones.txt.
void mostrar_minas_usuario(const tPuntuaciones& marcador, int cont); // Lista las minas recorridas por una persona, ordenadas por nivel (Figura 1).
void mostrar_alfabetico(const tPuntuaciones& marcador); // Lista los jugadores y sus puntuaciones totales, ordenados por orden alfab�tico (Figura 2).
void mostrar_datos_usuario(const tPuntuaciones& marcador); 
		/* Muestra todos los datosde todos los usuarios(Figura 3).
		Los usuarios est�n ordenados alfab�ticamente y los identificadores de las minas, 
		al ser num�ricos, est�n ordenados crecientemente.*/

//Para el tratamiento del vector din�mico
void inicializar_marcador(tPuntuaciones& marcador); // Inicializa el array din�mico.
void aumentar_capacidad(tPuntuaciones& marcador); // Duplica el tama�o del array.
void destruir(tPuntuaciones& marcador); // Libera la memoria din�mica.
bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos);
/* Busca un nombre en el array din�mico y devuelve si se encuentra o no.
Si el nombre est� en el array entonces se devuelve la posici�n en la cual se encuentra
y si no est� en el array entonces se devuelve la posici�n d�nde deber�a estar.
Los datos del array din�mico se encuentran ordenados por orden alfab�tico.
Debe realizarse una b�squeda binaria iterativa de los datos. */
void insertar(tPuntuaciones& marcador, string const& nombre, int pos);
	/* Inserta ordenadamente en la posici�n pos un nuevo jugador(nombre).
	 Al realizar la inserci�n de un nuevo jugador, si no hay suficiente espacio en el array,
	 se amplia. */






