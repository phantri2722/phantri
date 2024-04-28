#include"item.h"

item::item()
{
    item_type_ = 0;
    come_back_ = false;
    frame_ = 0;
}

item::~item() {}

void item::set_clip()
{
    for(int i=0;i<25;i++)
    {
        clip_[i].x = i*BULLET_INCREASE_WIDTH;
        clip_[i].y = 0;
        clip_[i].w = BULLET_INCREASE_WIDTH;
        clip_[i].h = BULLET_INCREASE_HEIGHT;
    }
}

SDL_Rect item::GetRectFrame()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = BULLET_INCREASE_WIDTH;
    rect.h = BULLET_INCREASE_HEIGHT;

    return rect;
}

int item::ramdom_item()const
{
    int rand_item_type = rand() % 5;
    rand_item_type = rand_item_type < 3 ? rand_item_type : 3;
    return rand_item_type;
}

void item::loadImgItem(SDL_Renderer* screen)
{
    if(item_type_ == BLASTER)
    {
        loadImg("image//gift1.png", screen);
    }
    else if(item_type_ == NEUTRON)
    {
        loadImg("image//gift2.png", screen);
    }
    else if(item_type_ == BORON)
    {
        loadImg("image//gift3.png", screen);
    }
    else if(item_type_ == LEVEL_UP)
    {
        loadImg("image//level_up_1225.png", screen);
    }
}

void item::Move(const int& x_border, const int& y_border)
{
    if(come_back_ == true)
    {
        rect_.y += y_val_;
        if(rect_.y > y_border)
        {
            come_back_ = false;
            rect_.x = -BULLET_TYPE_WIDTH;
            rect_.y = -BULLET_TYPE_HEIGHT;
        }
    }
}

void item::Show(SDL_Renderer* screen)
{
    if(item_type_ == 3)
    {
        if(come_back_ == true)
        {
            frame_ ++;
            if(frame_/3 >= 25)
            {
                frame_ = 0;
            }
            SDL_Rect renderQuad = {rect_.x, rect_.y, BULLET_INCREASE_WIDTH, BULLET_INCREASE_HEIGHT};
            SDL_RenderCopy(screen, object_, &clip_[frame_/3], &renderQuad);
        }
    }
    else if(item_type_ < 3)
    {
        if(come_back_ == true)
        {
            Render(screen);
        }
    }
}
