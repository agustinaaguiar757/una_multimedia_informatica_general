#pragma once
#include <ncurses.h>
#include "mapa.h"

class enemigo {
private:

    int m_x, m_y;
    int dir;

public:

    enemigo(int x, int y);
    int getX() { return m_x; }
    int getY() { return m_y; }
    
    void update(Mapa &mapa);
    void draw();
};