#include "final.h"

final::final()
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
        "                                 --------------------------------------",
        "                                 |#####|WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW| ",
        "                                 |#####|WW<(        Salida       !)>WW| ",
        "                                 |#####|WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWWWW.----.WWWWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWW,'  ||  `.WWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI   _||_   IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI  ' || `  IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI    ||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWWWI____||____IWWWWWWWWWWW| ",
        "                                 |#####/_o_                           | ",
        "                                 |####/  X                            | ",
        "                                 |###/  ' `                           | ",
        "                                 |##/                                 | ",
        "                                 |#/                                  | ",
        "                                 |/                                   | "
    };

    filas = data.size();
    columnas = data[0].size();
}

void final::draw()
{
    for (int i = 0; i < filas; i++) 
    {
        mvprintw(i + 1, 1, "%s", data[i].c_str());
    }
}
