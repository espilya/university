
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
		do {
			op = menuListaSudokus(lista, juego);
			if(op !=0)
				mostrarMenuPrincipal(juego);
		} while (op != 0);
	else
		colorStr("Error al cargar 'listaSudokus.txt'.\nFinalizando programa.", ROJO);
	return 0;
}

