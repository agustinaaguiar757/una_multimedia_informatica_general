#pragma once 
#include <ncurses.h>
#include <string>
#include <vector>

class pieza {
private:
    std::vector<std::string> data;
    int filas;
    int columnas;

public:
    pieza();

    void draw();                 

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
};