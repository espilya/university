
#include "checkML.h"
#include "listaSudokus.h"

//	
//				HECHO POR: 
//		ILYA LAPSHIN y MICHAL FITAL
//
//
//
//
//
//
//				Preg:
//	--Policia de memoria
//	--(return true;  return false;) ???
//	--Opcionales
//

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int op, op2;
	bool okListaSud = false, okListaJug = false;
	tListaSudokus listaSud;
	tListaJugadores listaJug;
	cout << boolalpha << ("luis" < "jugador");
	tJuego juego;
	creaLista(listaSud); // iniciamos lista de sudoku
	creaLista(listaJug); // iniciamos lista de jugadores

	if (cargar(listaSud))
		okListaSud = true;
	if (cargar(listaJug))
		okListaJug = true;

	if (okListaSud && okListaJug) // cargamos listaSudoku
		do {
			iniciaJuego(juego); // iniciamos juego
			listaJug = ordenarPorAscii_Burbuja(listaJug);
			listaSud = ordenarListaSudoku(listaSud);
			//mostrar(listaJug);
			//cout << endl << endl << endl;
			cout << "1. - Jugar\n"
				<< "2. - Ver jugadores ordenados por identificador\n"
				<< "3. - Ver jugadores ordenados por puntos\n"
				<< "4. - Incorporar sudoku\n"
				<< "5. - Eliminar sudoku\n"
				<< "6. - Incorporar jugador\n"
				<< "7. - Eliminar jugador\n"
				<< "0. - Salir" << endl;
			op = leerOpcion(0, 7);
			clear();
			switch (op) {
			case 1:
				op2 = menuListaSudokus(listaSud, juego);
				if (op2 != 0) {
					startJuego(juego);
					if (juego.guardar) {
						puntuarJugador(listaJug, juego.sudoku.nivel);
						listaJug = ordenarPorAscii_Burbuja(listaJug);
						mostrar(ordenarPorAscii_Burbuja(listaJug));
						guardar(listaJug);
						pausa();
					}
				}

				break;
			case 2: // Ver jugadores ordenados por ID
				//listaJug = ordenarPorAscii_Burbuja(listaJug);
				mostrar(listaJug);
				pausa();
				break;
			case 3: // Ver jugadores ordenados por puntos
				mostrar(menuOrdenacion(listaJug, true));
				pausa();
				break;
			case 4: // registrar sudoku
				registrarSudoku(listaSud);
				listaSud = ordenarListaSudoku(listaSud);
				guardar(listaSud);
				mostrar(listaSud);
				pausa();
				break;
			case 5: // eliminar sudoku
				eliminarSudoku(listaSud);
				guardar(listaSud);
				mostrar(listaSud);
				pausa();
				break;
			case 6: // Incorporar jugador
				listaJug = ordenarPorAscii_Burbuja(listaJug);
				incorporarJugador(listaJug);
				listaJug = ordenarPorAscii_Burbuja(listaJug);
				guardar(listaJug);
				mostrar(listaJug);
				pausa();
				break;
			case 7: // eliminar jugador
				listaJug = ordenarPorAscii_Burbuja(listaJug);
				borrarJugador(listaJug);
				guardar(listaJug);
				mostrar(listaJug);
				pausa();
				break;
			}

			clear();
		} while (op != 0);
	else if (!okListaSud)
		colorStr("Error al cargar 'listaSudokus.txt'.\n", ROJO);
	else if (!okListaJug)
		colorStr("Error al cargar 'listaJugadores.txt'.\n", ROJO);
	borrarJugadores(listaJug);
	borrarLista(listaJug);
	borrarLista(listaSud);
	return 0;
}
