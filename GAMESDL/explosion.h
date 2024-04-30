#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include"base.h"
#include"common.h"

#define WIDTH_FRAME_EXP 150
#define HEIGHT_FRAME_EXP 165
#define NUMBER_OF_FRAME 8

class Explosion : public base
{
public:
    Explosion();
    ~Explosion();

    void set_frame(const int& frame) {frame_ = frame;}
    int get_frame () {return frame_;}

    void set_clip();
    void Show(SDL_Renderer* screen);
private:
    int frame_;
    SDL_Rect clip_[NUMBER_OF_CHICKEN];
};

#endif
