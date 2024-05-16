#include"bullet.h"

bullet::bullet()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
    //frame_ = 0;
    bullet_type_=BLASTER;
}

bullet::~bullet() {}

void bullet::loadImgBullet(SDL_Renderer* screen, int bullet_level)
{
    if(bullet_type_ == BLASTER){
        std::string blaster_str = "image//blaster" + std::to_string(bullet_level) + ".png";
        loadImg(blaster_str, screen);
    }
    if(bullet_type_ == BORON)
    {
        std::string boron_str = "image//boron" + std::to_string(bullet_level) + ".png";
        loadImg(boron_str, screen);
    }
    if(bullet_type_ == LOVE)
    {
        std::string love_str = "image//love" + std::to_string(bullet_level) + ".png";
        loadImg(love_str, screen);
    }
    if(bullet_type_ == NEUTRON)
    {
        std::string neutron_str = "image//neutron" + std::to_string(bullet_level) + ".png";
        loadImg(neutron_str, screen);
    }
}

void bullet::HandleMoveSpaceshipBullet()
{

    rect_.y += y_val_;
    if(rect_.y < -rect_.h)
    {
        is_move_ = false;
    }

}

void bullet::HandleMoveChickenBullet()
{
    rect_.y += y_val_;
    if(rect_.y > SCREEN_HEIGHT)
    {
        is_move_ = false;
    }
}

void bullet::HandleMoveBossBullet(const int& x_border, const int& y_border)
{
    rect_.y += y_val_;
    if(rect_.y > y_border)
    {
        is_move_ = false;
    }
}

//void bullet::set_thunder_clip()
//{
//    for(int i=0;i<5;i++)
//    {
//        thunder_clip_[i].x = i* 158;
//        thunder_clip_[i].y = 0;
//        thunder_clip_[i].w = 158;
//        thunder_clip_[i].h = 400;
//    }
//}
//
//SDL_Rect bullet::GetThunderRect()
//{
//    SDL_Rect thunder_rect;
//    thunder_rect.x = rect_.x;
//    thunder_rect.y = rect_.y;
//    thunder_rect.w =rect_.w;
//    thunder_rect.h = rect_.h;
//    return thunder_rect;
//}
//
//void bullet::ShowThunder(SDL_Renderer* screen)
//{
//    frame_ ++;
//    if(frame_/10>=5)
//    {
//        frame_ = 0;
//    }
//    SDL_Rect renderQuad = {rect_.x, rect_.y, 158, 400};
//    SDL_RenderCopy(screen, object_, &thunder_clip_[frame_/10], &renderQuad);
//}
