#pragma once
#include <ncurses.h>

class Personaje
{
public:

  void setup();
  void draw();

  void setX(int x);
  void setY(int y);
  int getX();
  int getY();

private:
  int m_x, m_y;
};