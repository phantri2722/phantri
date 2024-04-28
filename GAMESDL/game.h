#ifndef GAME_H_
#define GAME_H_

#include"common.h"
#include"base.h"
#include"space_ship.h"
#include"item.h"
#include"Chicken.h"

class game
{
public:
    game();
    ~game();
    void init(std::string title);
    void handle_event();
    void handle_game();
    void handle_chicken();
    bool get_running() {return isRunning;}
    bool crash_check(const SDL_Rect& object1, const SDL_Rect& object2);
    void clean();

private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;

    base background;
    space_ship spaceship;
    item item_;

    float scrolling;
    int bullet_level;
    int kill;

    std::vector<Chicken*> p_chicken_list_;
};

#endif
