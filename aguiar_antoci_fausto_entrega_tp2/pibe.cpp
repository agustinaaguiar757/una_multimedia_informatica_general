#include "pibe.h"

pibe::pibe()
{
    data = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "///////////|   |/| (.,------...__",
        "///////////|  /|.'',,,,,,,,,,,,,`.",
        "///////////|/ .',,.',,,`,,`.,`.,,,,`",
        "///////////| .,.',,,.'/''--...__`.,,|",
        "///////////|.,.--.`.,,',,,,,,,,,'.,,|",
        "///////////|'',,.',,_.',,--.,,.--':/",
        "////////////''(,,/_/,,,,(()),,(()(",
        "////////////''._',,,,,,,,,,(,,,],'",
        "////////////',`.,,,,,,,,,,,,`--',,'",
        "////////////`.:,,,,.,,,,,,___,',,'",
        "//////////////`.,,,,,.,,,/_  _/,.'",
        "/////////////////),,,,,,,.____.-'",
        "///////////////.'`.,,,,,,,,(--..",
        "/////////////.',/,,//,,,,,,/,/,,`.",
        "///////////.',,,,/(,,/,,,,/|/,,,,,`.",
        "////////.',,,,,,,,,,,/__/,,,,,,,,,,`.",
        "////////,,,,,,|,,,,,,,,o,,,,,,|,,,,,,|",
        "//////|,,,,,,,|,,,,,,,,,,,,,,,|,,,,,,|"
    };

    filas = data.size();
    columnas = data[0].size();
}

void pibe::draw()
{
    for (int i = 0; i < filas; i++) 
    {
        mvprintw(i + 1, 1, "%s", data[i].c_str());
    }
}

void pibe::Dialogo1()
{
    for (int y = 31; y < 38; y++) mvhline(y, 3, ' ', 114);
		
	mvaddch(30, 117, ACS_URCORNER);
	mvaddch(38, 2, ACS_LLCORNER);
	mvaddch(38, 117, ACS_LRCORNER);
    mvaddch(30, 2, ACS_ULCORNER);
    mvhline(30, 3, ACS_HLINE, 114);
    mvhline(38, 3, ACS_HLINE, 114);
    mvvline(31, 2, ACS_VLINE, 7);
    mvvline(31, 117, ACS_VLINE, 7);

	mvprintw(32, 3, "Julian: Mama, me invitaron a una fiesta mis amigos, Puedo ir?");	
    mvprintw(36, 3, "Julian: Pero mama, va a ser una fiesta tranquila, incluso si asi queres puedo volver temprano.");
}

void pibe::Dialogo2()
{
    for (int y = 31; y < 38; y++) mvhline(y, 3, ' ', 114);

	mvprintw(34, 3, "Julian: Por dios! me tenes harto! Nunca me dejas hacer nada...");	
}

void pibe::Dialogo3()
{
    for (int y = 31; y < 38; y++) mvhline(y, 3, ' ', 114);

    mvaddch(30, 117, ACS_URCORNER);
	mvaddch(38, 2, ACS_LLCORNER);
	mvaddch(38, 117, ACS_LRCORNER);
    mvaddch(30, 2, ACS_ULCORNER);
    mvhline(30, 3, ACS_HLINE, 114);
    mvhline(38, 3, ACS_HLINE, 114);
    mvvline(31, 2, ACS_VLINE, 7);
    mvvline(31, 117, ACS_VLINE, 7);

	mvprintw(34, 3, "Julian: Tengo que salir de esta prision!!");
}

void pibe::Final()
{
    for (int y = 31; y < 38; y++) mvhline(y, 3, ' ', 114);
		
	mvaddch(30, 117, ACS_URCORNER);
	mvaddch(38, 2, ACS_LLCORNER);
	mvaddch(38, 117, ACS_LRCORNER);
    mvaddch(30, 2, ACS_ULCORNER);
    mvhline(30, 3, ACS_HLINE, 114);
    mvhline(38, 3, ACS_HLINE, 114);
    mvvline(31, 2, ACS_VLINE, 7);
    mvvline(31, 117, ACS_VLINE, 7);

	mvprintw(33, 3, "Julian: POR FIN! PUDE ESCAPAR DE MI FAMILIA!!");	
    mvprintw(35, 3, "Julian: RAPIDO! ANTES QUE DESCUBRAN QUE ME FUI");
}