#include "atrapado.h"

atrapado::atrapado()
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
        "                                 |#####|WWWWWWW  ,-.||    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWW (     )    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWW ((!     )   IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWW )6(!  /    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWWW ! _`)/&<   IWWWWWWWWWWW| ",
        "                                 |#####|WWWWW  >o< ) )    IWWWWWWWWWWW| ",
        "                                 |#####|WWWWW ( (__/)  )) IWWWWWWWWWWW| ",
        "                                 |#####|WWWWW / ( (   !  !IWWWWWWWWWWW| ",
        "                                 |#####|WWWW (=.|!    |)=.|WWWWWWWWWWW| ",
        "                                 |#####/_o_  /  / )   /   |           | ",
        "                                 |####/  X   |   /  /     |           | ",
        "                                 |###/  ' `  |_,/  (`;-.  |!          | ",
        "                                 |##/          /    |!  `'   !        | ",
        "                                 |#/          /     ' `       !       | ",
        "                                 |/          /                  !     | "
    };

    filas = data.size();
    columnas = data[0].size();
}

void atrapado::draw()
{
    for (int i = 0; i < filas; i++) 
    {
        mvprintw(i + 1, 1, "%s", data[i].c_str());
    }
}
