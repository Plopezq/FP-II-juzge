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
//Array dinámico de tPuntuacionJugador
typedef struct {
	int capacidad;
	int num_jugadores;
	tPuntuacionJugador* array_clasificacion;
} tPuntuaciones; 

//PROTOTIPOS
bool cargar_marcador(tPuntuaciones& marcador);	// Introduce en el array dinámico los datos disponibles en el fichero Puntuaciones.txt
bool guardar_marcador(tPuntuaciones& marcador); // Vuelca el contenido del array dinámico en el fichero Puntuaciones.txt.
void mostrar_minas_usuario(const tPuntuaciones& marcador, int cont); // Lista las minas recorridas por una persona, ordenadas por nivel (Figura 1).
void mostrar_alfabetico(const tPuntuaciones& marcador); // Lista los jugadores y sus puntuaciones totales, ordenados por orden alfabético (Figura 2).
void mostrar_datos_usuario(const tPuntuaciones& marcador); 
		/* Muestra todos los datosde todos los usuarios(Figura 3).
		Los usuarios están ordenados alfabéticamente y los identificadores de las minas, 
		al ser numéricos, están ordenados crecientemente.*/

//Para el tratamiento del vector dinámico
void inicializar_marcador(tPuntuaciones& marcador); // Inicializa el array dinámico.
void aumentar_capacidad(tPuntuaciones& marcador); // Duplica el tamaño del array.
void destruir(tPuntuaciones& marcador); // Libera la memoria dinámica.
bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos);
/* Busca un nombre en el array dinámico y devuelve si se encuentra o no.
Si el nombre está en el array entonces se devuelve la posición en la cual se encuentra
y si no está en el array entonces se devuelve la posición dónde debería estar.
Los datos del array dinámico se encuentran ordenados por orden alfabético.
Debe realizarse una búsqueda binaria iterativa de los datos. */
void insertar(tPuntuaciones& marcador, string const& nombre, int pos);
	/* Inserta ordenadamente en la posición pos un nuevo jugador(nombre).
	 Al realizar la inserción de un nuevo jugador, si no hay suficiente espacio en el array,
	 se amplia. */






