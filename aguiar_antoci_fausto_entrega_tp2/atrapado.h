#pragma once 
#include <ncurses.h>
#include <string>
#include <vector>

class atrapado {
private:
    std::vector<std::string> data;
    int filas;
    int columnas;

public:
    atrapado();

    void draw();

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
};