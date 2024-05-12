#include "shield.h"

Shield::Shield()
{
    rect_.x = -WIDTH_SHIELD;
    rect_.y = -HEIGHT_SHIELD;
    rect_.w = WIDTH_SHIELD;
    rect_.h = HEIGHT_SHIELD;

    shield_count = 500;
    frame_ = 0;
}

Shield::~Shield() {}

void Shield::Show(SDL_Renderer* screen)
{
    if(status_ == true)
    {
        Render(screen);
    }
}

void Shield::update_shield()
{


    if(status_ == true){
        shield_count--;
        if(shield_count == 0)
        {
            status_ = false;
        }
    }
    else{
        shield_count = 500;
    }
}

void Shield::Move()
{
    rect_.x += x_val_;
    rect_.y += y_val_;
}

void Shield::set_clip()
{
    for(int i=0;i<4;i++)
    {
        clip_[i].x = i * WIDTH_SHIELD;
        clip_[i].y = 0;
        clip_[i].w = WIDTH_SHIELD;
        clip_[i].h = HEIGHT_SHIELD;
    }
}

SDL_Rect Shield::GetRectFrame()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = WIDTH_SHIELD;
    rect.h = HEIGHT_SHIELD;

    return rect;
}
