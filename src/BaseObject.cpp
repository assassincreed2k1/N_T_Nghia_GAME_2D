#include <iostream>
#include "BaseObject.h"

BaseObject::BaseObject()
    : p_object_(nullptr)
{
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObject::~BaseObject()
{
    Free();
}
bool BaseObject::LoadImg(const std::string& path, SDL_Renderer *screen)
{
    Free();
    SDL_Texture *new_texture = nullptr;

    SDL_Surface *load_surface = IMG_Load(path.c_str());
    if (load_surface != nullptr)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if (new_texture != nullptr)
        {
            rect_.w = load_surface->w;
            rect_.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    else
    {
        std::cout << "Unable to load " << path << " SDL Error: " << SDL_GetError() << "\n";
    }
    p_object_ = new_texture;
    return p_object_ != nullptr;
}

void BaseObject::Render1(SDL_Renderer *des, const SDL_Rect *clip) const
{
    SDL_Rect renderquad = {rect_.x + minus, rect_.y, rect_.w, rect_.h};
    if(rect_.x <= -SCREEN_WIDTH)
    {
        // Không nên thay đổi trạng thái trong hàm const, nhưng giữ nguyên logic
        // Nếu cần, bỏ const ở khai báo hàm này ở header
        // rect_.x = 0;
    }
    SDL_Rect renderquad2 = {rect_.x + SCREEN_WIDTH + minus, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderquad);
    SDL_RenderCopy(des, p_object_, clip, &renderquad2);
}

void BaseObject::Render(SDL_Renderer *des, const SDL_Rect *clip) const
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void BaseObject::Free()
{
    if (p_object_ != nullptr)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = nullptr;
        rect_.w = 0;
        rect_.h = 0;
    }
}

