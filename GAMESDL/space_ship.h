#ifndef SPACE_SHIP_H_
#define SPACE_SHIP_H_

#include<vector>
#include"common.h"
#include"base.h"
#include"bullet.h"

#define WIDTH_MAIN 70
#define HEIGHT_MAIN 57
#define MAIN_SPEED 8

class space_ship : public base
{
public:
    space_ship();
    ~space_ship();

    void set_bullet_list(std::vector<bullet*> bullet_list) {bullet_list_ = bullet_list;}
    std::vector<bullet*> get_bullet_list() {return bullet_list_;}
    void set_bullet_type(const int& bullet_type) {bullet_type_ = bullet_type;}
    int get_bullet_type() {return bullet_type_;}
    void set_bullet_damage(const float& bullet_damage) {bullet_damage_ = bullet_damage;}
    float get_bullet_damage() {return bullet_damage_;}
    void set_status(const bool& status) {status_ = status;}
    bool get_status() {return status_;}

    void Control(SDL_Event event, SDL_Renderer* screen, int bullet_level);
    void Move();
    void Show(SDL_Renderer* screen);
    void HandleBullet(SDL_Renderer* screen);
    void RemoveBullet(const int& idx);
private:
    int x_val_;
    int y_val_;
    bool status_;

    std::vector<bullet*> bullet_list_;
    int bullet_type_;
    float bullet_damage_;
};


#endif
