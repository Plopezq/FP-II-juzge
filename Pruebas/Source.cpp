
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	string palabras[2];

	palabras[0] = "HOLA";
	palabras[1] = "ADIOS";


	for (int i = 0; i < palabras[0].size() ; i++) {
		cout << palabras[0][i];
	}
	return 0;
}