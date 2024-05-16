#ifndef THUNDER_H_
#define THUNDER_H_

#include<vector>
#include"common.h"
#include"base.h"

class Thunder : public base
{
public:
    Thunder();
    ~Thunder();

    void set_isActive(const bool& active) {isActive = active;}
    bool get_isActive()const {return isActive;}

    void set_clip();
    SDL_Rect GetRectFrame();
    void HandleThunder(SDL_Renderer* screen, bool& isPause);
private:
    SDL_Rect clip_[4];
    int frame_;
    bool isActive;
};

#endif
