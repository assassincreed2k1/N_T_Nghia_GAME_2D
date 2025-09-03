
#ifndef PLAYER_POWER_H_
#define PLAY_POWER_H_

#include "CommonFunc.h"
#include "BaseObject.h"

class PlayerPower : public BaseObject
{
public:
    PlayerPower();
    ~PlayerPower();

    void SetNum(const int &num) { number_ = num; }
    void AddPos(int xPos);
    void Show(SDL_Renderer *screen) const;
    void Init(SDL_Renderer *screen);

    void InitCrease();
    void Decrease();

private:
    int number_;
    std::vector<int> pos_list_;
};

class PlayerMoney : public BaseObject
{
public:
    PlayerMoney();
    ~PlayerMoney();

    void Init(SDL_Renderer *screen);
    void Show(SDL_Renderer *screen) const;
    void SetPos(const int &x, const int &y) { x_pos_ = x, y_pos_ = y; }

private:
    int x_pos_;
    int y_pos_;
};

#endif