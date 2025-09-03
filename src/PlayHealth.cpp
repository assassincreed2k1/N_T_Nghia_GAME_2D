#include <iostream>
#include "PlayHealth.h"

PlayerPower::PlayerPower()
{
    number_ = 0;
}

PlayerPower::~PlayerPower()
{
}

void PlayerPower::Init(SDL_Renderer *screen)
{
    LoadImg("res/pic/img/player_pw.png", screen);
    number_ = 3;
    if (pos_list_.size() > 0)
    {
        pos_list_.clear();
    }

    AddPos(20);
    AddPos(60);
    AddPos(100);
}

void PlayerPower::Show(SDL_Renderer *screen) const
{
    for (size_t i = 0; i < pos_list_.size(); ++i)
    {
        SDL_Rect rect = rect_;
        rect.x = pos_list_[i];
        rect.y = 0;
        SDL_RenderCopy(screen, p_object_, nullptr, &rect);
    }
}

void PlayerPower::Decrease()
{
    number_--;
    pos_list_.pop_back();
}

void PlayerPower::InitCrease()
{
    number_++;
    int last_pos = pos_list_.back();
    last_pos += 40;
    pos_list_.push_back(last_pos);
}

void PlayerPower::AddPos(int xPos) {
    pos_list_.push_back(xPos);
}

PlayerMoney::PlayerMoney()
{
    x_pos_ = 0;
    y_pos_ = 0;
}

PlayerMoney::~PlayerMoney()
{
}

void PlayerMoney::Init(SDL_Renderer *screen)
{
    bool ret = LoadImg("res/pic/img/heart_.png", screen);
}

void PlayerMoney::Show(SDL_Renderer *screen) const
{
    SDL_Rect rect = rect_;
    rect.x = x_pos_;
    rect.y = y_pos_;
    SDL_RenderCopy(screen, p_object_, nullptr, &rect);
}
