#include "CommonFunc.h"

#include <iostream>

bool winner = false;
int minus = 0;
bool change_threats = false;
int map_start = 0;

bool SDLCommonFunc::CheckCollision(const SDL_Rect &object1, const SDL_Rect &object2)
{
  // Tối ưu kiểm tra giao nhau trực tiếp
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;

  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;

  if (right_a <= left_b || left_a >= right_b || bottom_a <= top_b || top_a >= bottom_b)
    return false;
  return true;
}

bool SDLCommonFunc::CheckFocusMouse(const int &x, const int &y,const SDL_Rect& pos)
{
  return (x > pos.x && x < pos.x + pos.w && y > pos.y && y < pos.y + pos.h);
}
