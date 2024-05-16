#ifndef GAME_H_
#define GAME_H_

#include"common.h"
#include"base.h"
#include"space_ship.h"
#include"item.h"
#include"Chicken.h"
#include"boss.h"
#include"explosion.h"
#include"text.h"
#include"shield.h"
class game
{
public:
    game();
    ~game();
    void init(std::string title);
    void handle_event();
    void handle_game();
    void handle_chicken();
    void handle_boss();
    bool get_running() {return isRunning;}
    bool get_pause_game() {return isPause;}
    bool crash_check(const SDL_Rect& object1, const SDL_Rect& object2);
    bool check_mouse_item(const int& x, const int& y, const SDL_Rect& rect);
    void menu(const std::string& element);
    void reset_game();
    void handle_pause_game();
    void clean();

private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;
    TTF_Font* g_font_text;
    TTF_Font* g_font_menu;
    TTF_Font* g_font_end_game;
    Mix_Chunk* g_sound_bullet[4];
    Mix_Chunk* g_sound_exp[3];
    Mix_Chunk* g_sound_chicken_hit[3];
    Mix_Chunk* g_sound_level_up;
    Mix_Music* g_music_start;

    base background;
    space_ship spaceship;
    item item_;
    Boss boss;
    Boss boss2;
    Explosion exp;
    Explosion exp_boss;
    Text kill_text;
    Text heart_text;
    Text lighting_text;
    Text hint;
    Text end_game;
    Text pause_game;
    Text restart_game;
    Text continue_game;
    Text music;
    base support;
    Shield shield;

    float scrolling;
    int bullet_level;
    int kill;
    int count_num_exp;
    int time_end_game;
    int menu_number;
    bool isPause;
    bool isSoundOn;

    std::vector<Chicken*> p_chicken_list_;
};

#endif
