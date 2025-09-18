#pragma once 
#include <ncurses.h>
#include <string>
#include <vector>

class final {
private:
    std::vector<std::string> data;
    int filas;
    int columnas;

public:
    final();

    void draw();

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
};