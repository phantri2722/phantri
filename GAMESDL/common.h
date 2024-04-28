#ifndef COMMON_H_
#define COMMON_H_

#include<SDL.h>
#include<SDL_image.h>
#include<string>


const int BACKGROUND_WIDTH = 1200;
const int BACKGROUND_HEIGH = 3840;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const float SCREEN_SPEED = 0.4;

const int COLOR_KEY_R = 170;
const int COLOR_KEY_G = 170;
const int COLOR_KEY_B = 170;
const int RENDER_DRAW_COLOR = 255;

const int BLASTER = 0;
const int NEUTRON = 1;
const int BORON = 2;
const int LEVEL_UP = 3;
const int BLASTER_SPEED = 12;
const int NEUTRON_SPEED = 18;
const int BORON_SPEED = 30;
const int BULLET_DAMAGE_LEVEL_UP = 0.5;

const int NUMBER_OF_CHICKEN = 36;
const int CHICkEN_HEART = 3;
const int DISTANCE_BETWEEN_CHICKEN = 100;
const int NUMBER_OF_CHICKEN_PER_ROW = 12;

const int ONE_TURN_GIFT = 14;

struct StatusChicken
{
    int turn_left;
    int turn_right;
    int turn_up;
    int turn_down;
};
#endif
