#include "enemigo.h"

enemigo::enemigo(int x, int y) {
    m_x = x;
    m_y = y;
    dir = 1;
}

void enemigo::update(Mapa &mapa) {
    if (mapa.esPared(m_x + dir, m_y))
        dir *= -1;

    m_x += dir;
}

void enemigo::draw() {
    mvaddch(m_y, m_x, '8');
}