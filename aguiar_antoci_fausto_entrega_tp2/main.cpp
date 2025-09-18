//Sebastian Fausto ----> re copado este :D
//Mora Antoci
//Agustina Aguiar

#include <iostream> 
#include <ncurses.h>
#include "Personaje.h"
#include "mapa.h"
#include "pieza.h"
#include "pibe.h"
#include "mama.h"
#include "enemigo.h"
#include "final.h"
#include "atrapado.h"

using namespace std;  

bool salir = false; 
bool gameover = false;
const int DELAY = 30;
const int ANCHO = 120;
const int ALTO = 40;
int objetos = 0;
const int OBJETOS_META = 19;

void Menu();
void Titulo();
void Creditos();
void escena1();
void Intro();
void Final();

void setup();
void input();
void update();
void draw1();
void draw2();
void game_over();
void Salir();

Personaje P1;
enemigo Enemigo1(24, 17);
enemigo Enemigo2(24, 18);
enemigo Enemigo3(81, 17);
enemigo Enemigo4(81, 18);
enemigo Enemigo5(3, 26);
enemigo Enemigo6(3, 27);
enemigo Enemigo7(81, 31);
enemigo Enemigo8(81, 32);
enemigo Enemigo9(98, 2);
enemigo Enemigo10(98, 3);
Mapa Mapa1;
pieza Pieza;
pibe Pibe;
mama Mama;
final FINAL;
atrapado ATR;

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

    while (!salir) 
	{
    	erase();

		Titulo();

    	refresh();

    	int tecla = getch();
        
        switch (tecla) {

            case '1':

			escena1();
			
            while (!gameover) {
				input();
                update();
                draw1();
            }

			game_over();
			break;

            case '2':
            erase();

			Creditos();

			nodelay(stdscr, false);
    		getch();         
    		nodelay(stdscr, true);
            refresh();
            break;

            case '3':
            
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
	nodelay(stdscr, true);
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

		FINAL.draw();
		Pibe.Final();

		nodelay(stdscr, false);
    	getch(); 
		nodelay(stdscr, true);

		Final();
		nodelay(stdscr, false);
    	getch(); 
		nodelay(stdscr, true);
	}

	if (Mapa1.objetos(P1.getX(), P1.getY())) 
	{
    	objetos++;
    	Mapa1.recogerObjeto(P1.getX(), P1.getY());

    	if (objetos >= OBJETOS_META)
		{
        	Mapa1.abrirPuerta(93, 11);  
        	Mapa1.abrirPuerta(93, 12);  
    	}
	}

	Enemigo1.update(Mapa1);
	Enemigo2.update(Mapa1);
	Enemigo3.update(Mapa1);
	Enemigo4.update(Mapa1);
	Enemigo5.update(Mapa1);
	Enemigo6.update(Mapa1);
	Enemigo7.update(Mapa1);
	Enemigo8.update(Mapa1);
	Enemigo9.update(Mapa1);
	Enemigo10.update(Mapa1);

    if (P1.getX() == Enemigo1.getX() && P1.getY() == Enemigo1.getY() || P1.getX() == Enemigo2.getX() && P1.getY() == Enemigo2.getY() || P1.getX() == Enemigo3.getX() && P1.getY() == Enemigo3.getY() || P1.getX() == Enemigo4.getX() && P1.getY() == Enemigo4.getY() || P1.getX() == Enemigo5.getX() && P1.getY() == Enemigo5.getY() || P1.getX() == Enemigo6.getX() && P1.getY() == Enemigo6.getY() || P1.getX() == Enemigo7.getX() && P1.getY() == Enemigo7.getY() || P1.getX() == Enemigo8.getX() && P1.getY() == Enemigo8.getY() || P1.getX() == Enemigo9.getX() && P1.getY() == Enemigo9.getY() || P1.getX() == Enemigo10.getX() && P1.getY() == Enemigo10.getY())
	{
		clear();

		ATR.draw();
		Mama.Final();

		nodelay(stdscr, false);
    	getch(); 
		nodelay(stdscr, true);

		clear();
		
		mvaddch(9, 39, ACS_ULCORNER);
		mvaddch(9, 80, ACS_URCORNER);
		mvaddch(16, 39, ACS_LLCORNER);
		mvaddch(16, 80, ACS_LRCORNER);
		mvhline(9, 40, ACS_HLINE, 40);
		mvhline(16, 40, ACS_HLINE, 40);
		mvvline(10, 39, ACS_VLINE, 6);
		mvvline(10, 80, ACS_VLINE, 6);
		mvprintw(10, 52, "!! TE ATRAPARON!!");	
		mvprintw(11, 51, "* Suerte la proxima *");
		mvprintw(13, 50, "1- Jugar de nuevo");
		mvprintw(14, 51, "(toca 2 veces)");
		mvprintw(20, 51, "No pierdes tu progreso, no te preocupes!!");

		nodelay(stdscr, false); 
		int opcion = getch();
    	getch(); 

		switch (opcion)
		{
    		case '1':
        		setup();
        	break;

    		default:
        	break;
		}	
	}
}

///////////////////////////////////////////////////////////////////////////
void draw1()
{
	erase();
	box(stdscr, 0, 0);

	Mapa1.draw();
	P1.draw();
	Enemigo1.draw();
	Enemigo2.draw();
	Enemigo3.draw();
	Enemigo4.draw();
	Enemigo5.draw();
	Enemigo6.draw();
	Enemigo7.draw();
	Enemigo8.draw();
	Enemigo9.draw();
	Enemigo10.draw();

	refresh();
	napms(DELAY);
}

///////////////////////////////////////////////////////////////////////////
void draw2()
{
	erase();
	box(stdscr, 0, 0);
	Pieza.draw();
	Pibe.draw();

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
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Salir() 
{
	clear();
    mvprintw(10, 20, " __ __");
	mvprintw(11, 20, "|  |  |   _____ _____ _____    _____ _____ _____ _____ _____ _____    _____ _____");
	mvprintw(12, 20, "|  |  |  |     |  |  |   __|  |_   _|   __|   | |   __|  _  |   __|  |  |  |   | |");
	mvprintw(13, 20, "|__|__|  |  |  |  |  |   __|    | | |   __| | | |  |  |     |__   |  |  |  | | | |");
	mvprintw(14, 20, "|__|__|  |__  _|_____|_____|    |_| |_____|_|___|_____|__|__|_____|  |_____|_|___|");
	mvprintw(15, 20, "            |__|");
	mvprintw(17, 20, "                                                                   __ __");
	mvprintw(18, 20, " _____ _____ _____ _____ _____ _____ _____    ____  _____ _____   |  |  |");
	mvprintw(19, 20, "|  |  |   __| __  |     |     |   __|     |  |    ||     |  _  |  |  |  |");
	mvprintw(20, 20, "|     |   __|    -| | | |  |  |__   |  |  |  |  |  |-   -|     |  |__|__|");
	mvprintw(21, 20, "|__|__|_____|__|__|_|_|_|_____|_____|_____|  |____/|_____|__|__|  |__|__|");

    mvprintw(37, 5, "SALIENDO...");
	nodelay(stdscr, false);
    getch(); 
	nodelay(stdscr, true);
	clear();

    salir = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Intro()
{
    for (int y = 31; y < 38; y++) mvhline(y, 3, ' ', 114);

		clear();
		box(stdscr, 0, 0);

		FINAL.draw();

		mvaddch(30, 117, ACS_URCORNER);
		mvaddch(38, 2, ACS_LLCORNER);
		mvaddch(38, 117, ACS_LRCORNER);
        mvaddch(30, 2, ACS_ULCORNER);
        mvhline(30, 3, ACS_HLINE, 114);
        mvhline(38, 3, ACS_HLINE, 114);
        mvvline(31, 2, ACS_VLINE, 7);
        mvvline(31, 117, ACS_VLINE, 7);

		mvprintw(32, 18, "Vas a jugar desde el punto de vista de Julian, un chico adolescente que quiere ir");	
		mvprintw(33, 15, "a una fiesta pero su madre no lo deja por portarse mal, de castigo lo dejo encerrado en");
		mvprintw(34, 15, "su habitacion. Tu objetivo es abrir la puerta principal y escaparte porque sos muy rebelde.");
		mvprintw(35, 18, "Deberas agarrar todas las llaves y asi poder escapar, en total son 19, Tienes que");
		mvprintw(36, 15, "evitar a la familia, asi que animos, vos podes!!");

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void escena1()
{
	Intro();
	nodelay(stdscr, false);
    getch();         
    nodelay(stdscr, true);

	draw2();
	Mama.draw();

	Pibe.Dialogo1();
	Mama.Dialogo1();
	nodelay(stdscr, false);
    getch();         
    nodelay(stdscr, true);

	Pibe.Dialogo2();
	Mama.Dialogo2();
	nodelay(stdscr, false);
    getch();         
    nodelay(stdscr, true);

	draw2();

	Pibe.Dialogo3();
	nodelay(stdscr, false);
    getch();         
    nodelay(stdscr, true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Titulo()
{
box(stdscr, 0, 0);

    mvprintw(5, 19, "     _      _     _                    _                    ___");
	mvprintw(6, 19, "    /_|  __| |___| |___ ___ __ ___ _ _| |_ ___   ___ _ _   | __|  _ __ _ __ _");
	mvprintw(7, 19, "   / _ |/ _` / _ | / -_|_-</ _/ -_) ' |  _/ -_) / -_) ' |  | _| || / _` / _` |");
	mvprintw(8, 19, "  /_/ |_|__,_|___/_|___/__/|__|___|_||_|__|___| |___|_||_| |_| |_,_|__, |__,_|");
	mvprintw(9, 19, "                                                                   |___/");

	mvvline(5, 19, ACS_VLINE, 6);
	mvvline(5, 99, ACS_VLINE, 6);
	mvhline(4, 19, ACS_TTEE, 81);
	mvhline(10, 19, ACS_BTEE, 81);

    mvprintw(13, 38, "  ___           __");
	mvprintw(14, 38, " <  / ____  __ / /_ _____ ____ _____");
	mvprintw(15, 38, " / / /___/ / // / // / _ `/ _ `/ __/");
	mvprintw(16, 38, "/_/        |___/|_,_/|_, /|_,_/_/");
	mvprintw(17, 38, "                    /___/");
    mvprintw(20, 38, "   ___          _____           ___ __");
	mvprintw(21, 38, "  |_  |  ____  / ___/______ ___/ (_) /____  ___");
	mvprintw(22, 38, " / __/  /___/ / /__/ __/ -_) _  / / __/ _ |(_-<");
	mvprintw(23, 38, "/____/        |___/_/  |__/|_,_/_/|__/|___/___/");
	mvprintw(26, 38, "   ____         ____     ___");
	mvprintw(27, 38, "  |_  /  ____  / __/__ _/ (_)___");
	mvprintw(28, 38, " _/_ <  /___/ _| |/ _ `/ / / __/");
	mvprintw(29, 38, "/____/       /___/|_,_/_/_/_/");
	mvprintw(37, 30, "Se recomienda jugar con la tipografia 'Liberation Mono'");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Creditos()
{
	box(stdscr, 0, 0);

	mvhline(4, 35, ACS_HLINE, 54);
    mvhline(10, 35, ACS_HLINE, 54);
    mvvline(5, 34, ACS_VLINE, 5);
    mvvline(5, 89, ACS_VLINE, 5);

	mvaddch(4, 89, ACS_LLCORNER);
	mvaddch(10, 34, ACS_URCORNER);
	mvaddch(10, 89, ACS_ULCORNER);
    mvaddch(4, 34, ACS_LRCORNER);

	mvhline(16, 20, ACS_HLINE, 88);


    mvprintw(5, 35, "   _  _     ___             _ _ _                _  _");
	mvprintw(6, 35, "  / |/ |   / __| __ ___  __| (_) |_ ___  ___    / |/ |");
	mvprintw(7, 35, " /  /  /  / / | '__/ _ |/ _` | | __/ _ |/ __|  /  /  /");
	mvprintw(8, 35, "/|_/|_/  / /__| | |  __/ (_| | | || (_) |__ | /|_/|_/");
	mvprintw(9, 35, "|/ |/    |____/_|  |___||__,_|_||__|___/|___/ |/ |/");

	mvprintw(11, 20, "   __               ___                   _");
	mvprintw(12, 20, "  / /  ___  ___    / __| __ ___  __ _  __| | ___  _ __ ___  ___   ___  ___  _ __");
	mvprintw(13, 20, " / /  / _ |/ __|  / / | '__/ _ |/ _` |/ _` |/ _ || '__/ _ |/ __| / __|/ _ || '_ |");
	mvprintw(14, 20, "/ /__| (_) |__ | / /__| | |  __/ (_| | (_| | (_) | | |  __/|__ | |__ | (_) | | | |_ _ _");
	mvprintw(15, 20, "|____/|___/|___/ |____/_|  |___||__,_||__,_||___/|_|  |___||___/ |___/|___/|_| |_(_|_|_)");

    mvprintw(20, 10, "   _ _____                _____     _           _   _");
	mvprintw(21, 10, "  / |     |___ ___ ___   |  _  |___| |_ ___ ___|_| / |");
	mvprintw(22, 10, " / /| | | | . |  _| .'|  |     |   |  _| . |  _| |/ /");
	mvprintw(23, 10, "|_/ |_|_|_|___|_| |__,|  |__|__|_|_|_| |___|___|_|_/");

    mvprintw(25, 10, "   _ _____     _           _   _            _____             _         _");
	mvprintw(26, 10, "  / |   __|___| |_ ___ ___| |_|_|___ ___   |   __|___ _ _ ___| |_ ___  / |");
	mvprintw(27, 10, " / /|__   | -_| . | .'|_ -|  _| | .'|   |  |   __| .'| | |_ -|  _| . |/ /");
	mvprintw(28, 10, "|_/ |_____|___|___|__,|___|_| |_|__,|_|_|  |__|  |__,|___|___|_| |___|_/");

    mvprintw(30, 10, "   _ _____             _   _            _____         _           _");
	mvprintw(31, 10, "  / |  _  |___ _ _ ___| |_|_|___ ___   |  _  |___ _ _|_|___ ___  / |");
	mvprintw(32, 10, " / /|     | . | | |_ -|  _| |   | .'|  |     | . | | | | .'|  _|/ /");
	mvprintw(33, 10, "|_/ |__|__|_  |___|___|_| |_|_|_|__,|  |__|__|_  |___|_|__,|_| |_/");
	mvprintw(34, 10, "          |___|                              |___|");

	mvprintw(37, 5, "Toca cualquier tecla para volver al menu...");
}

void Final()
{
	clear();

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
	mvprintw(14, 51, "(toca 2 veces)");

	nodelay(stdscr, false); 
	int opcion = getch();

	switch (opcion)
		{
    		case '1':
        		setup();
        	break;

    		default:
        	break;
		}
}
//Ya dije que Sebas es copado? c: