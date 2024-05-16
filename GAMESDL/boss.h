#ifndef BOSS_H_
#define BOSS_H_

#include<vector>
#include"common.h"
#include"base.h"
#include"bullet.h"
#include"thunder.h"

class Boss : public base
{
public:
    Boss();
    ~Boss();

    void set_x_val(const int& xVal) {x_val_ = xVal;}
    void set_y_val(const int& yVal) {y_val_ = yVal;}
    void set_bullet_list(std::vector<bullet*> bullet_list) {bullet_list_ = bullet_list;}
    void set_heart (const int& heart) {heart_ = heart;}

    int get_x_val()const {return x_val_;}
    int get_y_val()const {return y_val_;}
    std::vector<bullet*> get_bullet_list()const {return bullet_list_;}
    int get_heart()const {return heart_;}

    void set_thunder_list(std::vector<Thunder*> thunder_list) {thunder_list_ = thunder_list;}
    std::vector<Thunder*> get_thunder_list()const {return thunder_list_;}

    void InitBullet(bullet* p_bulet, SDL_Renderer* screen,const int& speed_);
    void MakeBullet(SDL_Renderer* screen, bool& isPause, const int& width_, const int& height_);
    void Move();
    void Show(SDL_Renderer* screen);
    void set_clips();
    SDL_Rect GetRectFrame();
    void Decrease(const float& bullet_damage) {heart_ -= bullet_damage;}
    void show_heart_boss (SDL_Renderer* screen, int x, int y, int w, int h);
    void Show2(SDL_Renderer* screen);
    void InitThunder(Thunder* p_thunder, SDL_Renderer* screen);
    void MakeThunder(SDL_Renderer* screen, bool& isPause);
    void Move2();
private:
    int x_val_;
    int y_val_;
    float heart_;
    int frame_;
    SDL_Rect clip_[10];
    StatusChicken status_;
    std::vector<bullet*> bullet_list_;
    std::vector<Thunder*>thunder_list_;
};
#endif
