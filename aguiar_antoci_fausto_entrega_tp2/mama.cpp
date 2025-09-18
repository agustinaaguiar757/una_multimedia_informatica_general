#include "mama.h"

mama::mama()
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
        "",
        "",
        "",
        "///////////| .,.',,,.'/''--...__`.,,|__E         |____________________________|/////,-.",
        "///////////|.,.--.`.,,',,,,,,,,,'.,,|__|____.-------------------------._______|///(     )",
        "///////////|'',,.',,_.',,--.,,.--':/       {                           }       //((!     )",
        "////////////''(,,/_/,,,,(()),,(()(         {                           }        //)6(!  /",
        "////////////''._',,,,,,,,,,(,,,],'Y---, '``}_____________ _____________{``'      /! _`)/&<",
        "////////////',`.,,,,,,,,,,,,`--',,'---  '  !             !             !  '     _ >o< ) )",
        "////////////`.:,,,,.,,,,,,___,',,'      '..!.............!.............!..'      ( (__/)  ))",
        "//////////////`.,,,,,.,,,/_  _/,.'      '                                 '     / ( (   !  !",
        "/////////////////),,,,,,,.____.-':_     '..-----------------------------..'    (=.|!    |)=.|",
        "///////////////.'`.,,,,,,,,(--..                                               /  / )   /   |",
        "/////////////.',/,,//,,,,,,/,/,,`.                                             |   /  /     |",
        "///////////.',,,,/(,,/,,,,/|/,,,,,`.                                           |_,/  (`;-.  |!",
        "////////.',,,,,,,,,,,/__/,,,,,,,,,,`.                                            /    |!  `'   !",
        "////////,,,,,,|,,,,,,,,o,,,,,,|,,,,,,|                                          /     ' `       !",
        "//////|,,,,,,,|,,,,,,,,,,,,,,,|,,,,,,|                                         /                  !"
    };

    filas = data.size();
    columnas = data[0].size();
}

void mama::draw()
{
    for (int i = 0; i < filas; i++) 
    {
        mvprintw(i + 1, 1, "%s", data[i].c_str());
    }
}

void mama::Dialogo1()
{
    for (int y = 31; y < 38; y++);

	mvprintw(34, 3, "Madre: No Julian, sos muy chico para esas cosas. Tus amiguitos te llevan por el lado de la desgracia!");
}

void mama::Dialogo2()
{
    for (int y = 31; y < 38; y++);

    mvprintw(32, 3, "Madre: No julian");
	mvprintw(36, 3, "Madre: Soy tu madre, a mi me hablas bien. Ahora de castigo no solo NO vas a ir a la fiesta sino que");
    mvprintw(37, 3, "te vas a quedar reflexionando en tu habitacion.");
}

void mama::Final()
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

	mvprintw(33, 3, "Mama: Oye!! Vuelve a la habitacion!!");	
    mvprintw(35, 3, "Mama: Mal educado!!");
}