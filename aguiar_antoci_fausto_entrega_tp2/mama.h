#pragma once 
#include <ncurses.h>
#include <string>
#include <vector>

class mama {
private:
    std::vector<std::string> data;
    int filas;
    int columnas;

public:
    mama();

    void draw();
    void Dialogo1(); 
    void Dialogo2();
    void Dialogo3();    
    void Final();            

    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
};