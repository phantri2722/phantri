#include"game.h"

game::game()
{
    isRunning = true;
    bullet_level = 0;
    scrolling = -(BACKGROUND_HEIGH - SCREEN_HEIGHT);
    kill = 0;
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

    int t = 0;
    int y_row = 0;
    for(int c=0;c < NUMBER_OF_CHICKEN; c++)
    {
        Chicken* p_chicken = new Chicken();
        if(p_chicken)
        {
            p_chicken->loadImg("image//chicken_red.png", gRenderer);
            p_chicken->set_clips();
            if(t&NUMBER_OF_CHICKEN_PER_ROW == 0)
            {
                y_row -= DISTANCE_BETWEEN_CHICKEN;
                t=0;
            }
            p_chicken->SetRect(10 + t*DISTANCE_BETWEEN_CHICKEN, y_row);
            p_chicken->set_y_val(CHICKEN_SPEED);
            p_chicken->set_x_val(CHICKEN_SPEED);
            p_chicken->set_heart(CHICkEN_HEART);
            int random = rand()%8;
            if(random<2)
            {
                bullet* p_bullet = new bullet();
                p_chicken->InitBullet(p_bullet, gRenderer);
            }
            p_chicken_list_.push_back(p_chicken);
            t++;
        }
    }

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

    handle_chicken();

    item_.Move(SCREEN_WIDTH, SCREEN_HEIGHT);
    item_.Show(gRenderer);

    bool Col = crash_check(spaceship.GetRect(), item_.get_item_type() < LEVEL_UP ? item_.GetRect() : item_.GetRectFrame());
    if(Col)
    {
        item_.SetRect(-BULLET_TYPE_WIDTH, -BULLET_TYPE_HEIGHT);
        if(bullet_level < 3 && ((item_.get_item_type()) == spaceship.get_bullet_type() || item_.get_item_type() == LEVEL_UP))
        {
            bullet_level ++;
        }
        if(item_.get_item_type() < LEVEL_UP)
        {
            spaceship.set_bullet_type(item_.get_item_type());
        }

        item_.set_come_back(false);
    }

    SDL_RenderPresent(gRenderer);
}

bool game::crash_check(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    if(left_a > right_b || right_a < left_b || top_a > bottom_b || bottom_a < top_b)
    {
        return false;
    }
    return true;
}

void game::clean()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow=NULL;
    gRenderer=NULL;
    SDL_Quit();
}

void game::handle_chicken()
{
    if(kill < NUMBER_OF_CHICKEN*2)
    {
        for(int ck=0;ck<p_chicken_list_.size();ck++)
        {
            Chicken* p_chicken = p_chicken_list_.at(ck);
            if(p_chicken)
            {
                p_chicken->Move();
                p_chicken->Show(gRenderer);
                p_chicken->HandleBullet(gRenderer);
            }

            bool Col1 = false;
            std::vector<bullet*> bullet_list = p_chicken->get_bullet_list();
            for(int b=0;b<bullet_list.size();b++)
            {
                bullet* p_bullet  = bullet_list.at(b);
                if(p_bullet)
                {
                    Col1 = crash_check(p_bullet->GetRect(), spaceship.GetRect());
                    if(Col1 == true)
                    {
                        p_chicken->RemoveBullet(b);
                        break;
                    }
                }
            }

            bool Col2 = crash_check(spaceship.GetRect(), p_chicken->GetRectFrame());
            if(Col1||Col2)
            {
                spaceship.SetRect(SCREEN_WIDTH*2, SCREEN_HEIGHT*2);
                spaceship.set_status(false);
                spaceship.decrease_heart();
                if(spaceship.get_heart() >= 0)
                {
                    bullet_level = bullet_level , 2 ? 0 : (bullet_level - 1);
                }
            }

            std::vector<bullet*> s_bullet_list = spaceship.get_bullet_list();
            for(int sb=0;sb<s_bullet_list.size();sb++)
            {
                bullet* p_bullet = s_bullet_list.at(sb);
                if(p_bullet != NULL)
                {
                    bool Col3 = crash_check(p_bullet->GetRect(), p_chicken->GetRectFrame());
                    if(Col3)
                    {
                        p_chicken->Decresae((spaceship.get_bullet_damage()) + bullet_level * BULLET_DAMAGE_LEVEL_UP);
                        spaceship.RemoveBullet(sb);

                        if(p_chicken->get_heart() <= 0)
                        {
                            p_chicken->set_heart(CHICkEN_HEART);
                            kill++;

                            p_chicken->SetRect(p_chicken->GetRect().x, -3 * SCREEN_HEIGHT);
                            if(kill > NUMBER_OF_CHICKEN)
                            {
                                p_chicken->set_come_back(false);
                            }

                            if(kill% ONE_TURN_GIFT == 0)
                            {
                                item_.set_item_type(item_.ramdom_item());
                                item_.loadImgItem(gRenderer);
                                item_.SetRect((rand()%(SCREEN_WIDTH - 2*BULLET_TYPE_WIDTH) + BULLET_TYPE_WIDTH), -BULLET_TYPE_HEIGHT);
                                item_.set_come_back(true);
                            }
                        }
                    }
                }
            }
        }
    }
}
