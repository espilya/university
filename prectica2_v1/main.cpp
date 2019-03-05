
#include "pch.h"
#include "listaSudokus.h"

int main()
{
	int op;
	tListaSudokus lista;
	tJuego juego;
	creaListaVacia(lista);
	iniciaJuego(juego);
	if (cargarListaSudokus(lista))
		do{
			clear();
			cout << "1. - Jugar.\n"
			<< "0. - Salir del juego." << endl;
			op = leerOpcion(0, 1);
			if (op == 1) 
				op = menuListaSudokus(lista, juego);
			if(op!= 0)
				mostrarMenuPrincipal(juego, op);
			
		} while ( op != 0);
			
	else
		colorStr("Error al cargar 'listaSudokus.txt'.\nFinalizando programa.", ROJO);
	return 0;
}

