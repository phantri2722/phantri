#ifndef GAME_H_
#define GAME_H_

#include"common.h"
#include"base.h"
#include"space_ship.h"

class game
{
public:
    game();
    ~game();
    void init(std::string title);
    void handle_event();
    void handle_game();
    bool get_running() {return isRunning;}
    void clean();

private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;

    base background;
    space_ship spaceship;

    float scrolling;
    int bullet_level;
};

#endif // GAME_H_INCLUDED
