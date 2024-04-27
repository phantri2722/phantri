#include"game.h"

game::game()
{
    isRunning = true;
    scrolling = -(BACKGROUND_HEIGH - SCREEN_HEIGHT);
}

game::~game(){}

void game::init(std::string title)
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        isRunning = false;
    }
    else
    {
        gWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            isRunning = false;
        }
        else
        {
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL)
            {
                isRunning = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

                int imgFlags = IMG_INIT_PNG;
                if( !(IMG_Init( imgFlags) & imgFlags))
                {
                    isRunning = false;
                }
            }
        }
    }

    background.loadImg("image//background.png", gRenderer);
    spaceship.loadImg("image//spacecraft.png", gRenderer);

    isRunning = true;
}

void game::handle_event()
{
    while(SDL_PollEvent(&gEvent))
    {
        if(gEvent.type == SDL_QUIT)
        {
            isRunning = false;
        }
        spaceship.Control(gEvent, gRenderer, bullet_level);
    }
}

void game::handle_game()
{
    SDL_SetRenderDrawColor(gRenderer, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
    SDL_RenderClear(gRenderer);

    scrolling += SCREEN_SPEED;
    if(scrolling<0)
    {
        background.Render(gRenderer);
        background.SetRect(0, scrolling);
    }
    else
    {
        background.Render(gRenderer);
        background.SetRect(0, 0);
    }

    spaceship.Move();
    spaceship.Show(gRenderer);
    spaceship.HandleBullet(gRenderer);

    SDL_RenderPresent(gRenderer);
}

void game::clean()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow=NULL;
    gRenderer=NULL;
    SDL_Quit();
}
