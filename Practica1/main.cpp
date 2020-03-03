#include "juego.cpp" //Que este incluye juego.h y ese incluye mina.h

using namespace std;

int main() {
	system("cls");
	
	
	return 0;
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}