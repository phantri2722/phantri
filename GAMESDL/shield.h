#ifndef SHIELD_H_
#define SHIELD_H_

#include<vector>
#include"common.h"
#include"base.h"

#define WIDTH_SHIELD 100
#define HEIGHT_SHIELD 100

class Shield : public base
{
public:
    Shield();
    ~Shield();

    void set_status(const bool& status) {status_ = status;}
    bool get_status()const {return status_;}

    void set_x_val(const int& xVal) {x_val_ = xVal;}
    void set_y_val(const int& yVal) {y_val_ = yVal;}
    int get_x_val()const {return x_val_;}
    int get_y_val()const {return y_val_;}

    void set_clip();
    SDL_Rect GetRectFrame();

    void Show(SDL_Renderer* screen);
    void update_shield();
    void Move();
private:
    int x_val_;
    int y_val_;

    bool status_;
    int shield_count;
    int frame_;

    SDL_Rect clip_[4];
};

#endif
