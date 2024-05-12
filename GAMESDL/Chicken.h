#ifndef CHICKEN_H_
#define CHICKEN_H_

#include<vector>
#include"common.h"
#include"base.h"
#include"bullet.h"

#define WIDTH_CHICKEN 75
#define HEIGHT_CHICKEN 68
#define CHICKEN_SPEED 1
#define CHICKEN_BULLET_SPEED 1

class Chicken : public base
{
public:
    Chicken();
    ~Chicken();

    void set_x_val(const int& xVal) {x_val_=xVal;}
    void set_y_val(const int& yVal) {y_val_ = yVal;}
    void set_bullet_list(std::vector<bullet*> bullet_list) {bullet_list_ = bullet_list;}
    void set_come_back(const bool& come_back) {come_back_ = come_back;}
    void set_heart(const float& heart) {heart_=heart;}

    int get_x_val()const {return x_val_;}
    int get_y_val()const {return y_val_;}
    std::vector<bullet*> get_bullet_list(){return bullet_list_;}
    bool get_come_back()const {return come_back_;}
    float get_heart()const {return heart_;}

    void Move();
    void Show(SDL_Renderer* screen);
    void set_clips();
    SDL_Rect GetRectFrame();

    void InitBullet(bullet* p_bullet, SDL_Renderer* screen);
    void HandleBullet(SDL_Renderer* screen, bool& isPause);
    void RemoveBullet(const int& idx);

    void Decresae(const float& bullet_damage) {heart_ -= bullet_damage;}

    void set_status_right();

private:
    float heart_;
    std::vector<bullet*> bullet_list_;

    int x_val_;
    int y_val_;

    StatusChicken status_;
    int frame_;
    SDL_Rect clip_[18];
    bool come_back_;
};

#endif
