#include <iostream>
#include "BulletObject.h"

BulletObject::BulletObject()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
}

BulletObject::~BulletObject()
{
}

void BulletObject::HandleMove(int x_border, int y_border)
{
    if (bullet_dir_ == static_cast<unsigned int>(BulletDir::DIR_RIGHT))
    {
        rect_.x += x_val_;
        if (rect_.x > x_border)
        {
            is_move_ = false;
        }
    }
    else if (bullet_dir_ == static_cast<unsigned int>(BulletDir::DIR_LEFT))
    {
        rect_.x -= x_val_;
        if (rect_.x < 0)
        {
            is_move_ = false;
        }
    }
}