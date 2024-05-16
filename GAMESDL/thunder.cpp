#include"thunder.h"

Thunder::Thunder()
{
    frame_ = 0;
    isActive = false;

}

Thunder::~Thunder() {}

void Thunder::set_clip()
{
    for(int i=0;i<4;i++)
    {
        clip_[i].x = i * 213;
        clip_[i].y = 0;
        clip_[i].w = 213;
        clip_[i].h = 600;
    }
}

SDL_Rect Thunder::GetRectFrame()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = 213;
    rect.h = 600;
    return rect;
}

void Thunder::HandleThunder(SDL_Renderer* screen, bool& isPause)
{
    int random = rand()%100;
    if(isActive == true && isPause == false && random <= 3)
    {
        frame_ ++;
        if(frame_/ 5 >=4){
            frame_ = 0;
            isActive = false;
        }
        SDL_Rect renderQuad = {rect_.x, rect_.y, 213, 600};
        SDL_RenderCopy(screen, object_, &clip_[frame_/ 5], &renderQuad);
    }
}
