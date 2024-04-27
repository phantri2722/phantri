#include"game.h"

int main(int argc, char* argv[])
{
    game game_;
    game_.init("PhanTranQuangTri_23021739");
    while(game_.get_running()==true)
    {
        game_.handle_event();
        game_.handle_game();
    }
    game_.clean();
    return 0;
}
