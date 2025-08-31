//Aguiar Maria Agustina
//Antoci Mora
//Fausto Sebastian

#include <iostream> 
#include <ncurses.h>
#include "Personaje.h"
#include "mapa.h"

using namespace std;  

bool salir = false; 
bool gameover = false;
const int DELAY = 30;
const int ANCHO = 120;
const int ALTO = 40;

void setup();
void input();
void update();
void draw();
void game_over();
void Salir();

Personaje P1;
Mapa Mapa1;

int main() {

	setlocale(LC_ALL, "");

    initscr();    
    noecho();
    curs_set(false);
    keypad(stdscr, true);
    nodelay(stdscr, true);
	
	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}

    setup();

    while (!salir) {
    erase();
    box(stdscr, 0, 0);

    mvprintw(5, 30, "!!!!! ADOLECENTE EN FUGA !!!!!");
    mvprintw(7, 40, "1 - Jugar");
    mvprintw(8, 40, "2 - Creditos");
    mvprintw(9, 40, "3 - Salir");
	mvprintw(30, 30, "Se recomienda jugar con la tipografia 'Liberation Mono'");

    refresh();

    int tecla = getch();
        
        switch (tecla) {

            case '1':
            // Jugar
            while (!gameover) {
                input();
                update();
                draw();
            }
            game_over();
            break;

            case '2':
            // Créditos
            erase();
			box(stdscr, 0, 0);
            mvprintw(5, 40, "!! CREDITOS !!");
			mvprintw(8, 10, "LOS CREADORES SOOON:");
            mvprintw(13, 10, "/Agustina Aguiar/");
            mvprintw(14, 10, "/Sebastian Fausto/");
            mvprintw(15, 10, "/Mora Antoci/");

			nodelay(stdscr, false);
    		getch();         
    		nodelay(stdscr, true);
            refresh();
            break;

            case '3':
            
                // salir 
				Salir();

            break;
            
            default:
            break;
       }
    }
return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
	gameover = false;

	P1.setup();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void input()
{
	int tecla = getch();
	int nuevoX = P1.getX();
    int nuevoY = P1.getY();

	switch (tecla)
	{
	 	case KEY_UP:
            nuevoY--;
            break;
        case KEY_DOWN:
            nuevoY++;
            break;
        case KEY_LEFT:
            nuevoX--;
            break;
        case KEY_RIGHT:
            nuevoX++;
            break;
		case 27:
			gameover = true;
		default:
			break;
	}

	if (!Mapa1.esPared(nuevoX, nuevoY)) {
        P1.setX(nuevoX);
        P1.setY(nuevoY);
    }
}

///////////////////////////////////////////////////////////////////////////
void update()
{
	if (Mapa1.ganaste(P1.getX(), P1.getY())) 
	{
		clear();
	
		for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);
		
		mvaddch(9, 39, ACS_ULCORNER);
		mvaddch(9, 80, ACS_URCORNER);
		mvaddch(16, 39, ACS_LLCORNER);
		mvaddch(16, 80, ACS_LRCORNER);
		mvhline(9, 40, ACS_HLINE, 40);
		mvhline(16, 40, ACS_HLINE, 40);
		mvvline(10, 39, ACS_VLINE, 6);
		mvvline(10, 80, ACS_VLINE, 6);
		mvprintw(10, 52, "!! GANASTE !!");	
		mvprintw(11, 51, "* FELICIDADES *");
		mvprintw(13, 50, "1- Jugar De Nuevo");

		nodelay(stdscr, false); 
		int opcion = getch();

		if (opcion == '1')
		{
			setup();
		}

		nodelay(stdscr, true);
	}
}

///////////////////////////////////////////////////////////////////////////
void draw()
{
	erase();
	box(stdscr, 0, 0);

	//AGREGAR MAPA
	Mapa1.draw();
	P1.draw();

	refresh();
	napms(DELAY);
}

///////////////////////////////////////////////////////////////////////////
void game_over()
{
	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

	mvaddch(9, 39, ACS_ULCORNER);
	mvaddch(9, 80, ACS_URCORNER);
	mvaddch(16, 39, ACS_LLCORNER);
	mvaddch(16, 80, ACS_LRCORNER);
	mvhline(9, 40, ACS_HLINE, 40);
	mvhline(16, 40, ACS_HLINE, 40);
	mvvline(10, 39, ACS_VLINE, 6);
	mvvline(10, 80, ACS_VLINE, 6);
	mvprintw(10, 57, "PAUSA");	
	mvprintw(12, 52, "1- Menu Principal");
	mvprintw(13, 52, "2- Salir");

	nodelay(stdscr, false); 
	int opcion = getch();

	if (opcion == '1')
	{
		setup();
	}
	else if (opcion == '2')
	{
		Salir();
	}

	nodelay(stdscr, true);
}

void Salir() 
{
	clear();
    mvprintw(15, 40, "!! QUE TENGAS UN HERMOSO DIA !!");
    mvprintw(37, 5, "SALIENDO...");
	nodelay(stdscr, false);
    getch(); 
	nodelay(stdscr, true);
	clear();

    salir = true;
}

