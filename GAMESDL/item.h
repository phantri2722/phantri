#ifndef ITEM_H_
#define ITEM_H_

#include"common.h"
#include"base.h"

#define BULLET_TYPE_WIDTH 49
#define BULLET_TYPE_HEIGHT 58
#define BULLET_INCREASE_WIDTH 49
#define BULLET_INCREASE_HEIGHT 41
#define SPEED_ITEM 3

class item : public base
{
public:
    item();
    ~item();

    void set_x_val(const int& xVal) {x_val_ = xVal;}
    void set_y_val(const int& yVal) {y_val_ = yVal;}
    void set_item_type(const int& item_type) {item_type_ = item_type;}
    void set_come_back(const bool& come_back) {come_back_ = come_back;}

    int get_x_val() {return x_val_;}
    int get_y_val() {return y_val_;}
    int get_item_type() {return item_type_;}
    bool get_come_back() {return come_back_;}

    void set_clip();
    SDL_Rect GetRectFrame();
    int ramdom_item()const;

    void loadImgItem(SDL_Renderer* screen);
    void Move(const int& x_border, const int& y_border);
    void Show(SDL_Renderer* screen);
private:
    int x_val_;
    int y_val_;

    int item_type_;
    bool come_back_;

    int frame_;
    SDL_Rect clip_[25];
};

#endif
