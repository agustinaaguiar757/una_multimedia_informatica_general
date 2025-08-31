#pragma once 
#include <ncurses.h>
#include <string>
#include <vector>

class Mapa {
private:
    std::vector<std::string> data;
    int filas;
    int columnas;

public:
    Mapa();

    void draw();                 
    bool esPared(int x, int y);
    bool ganaste(int x, int y);   

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
};