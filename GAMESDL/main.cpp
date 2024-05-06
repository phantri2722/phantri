#include"game.h"

int main(int argc, char* argv[])
{
    game game_;
    game_.init("PhanTranQuangTri_23021739");
    game_.menu("START");
    while(game_.get_running()==true)
    {
        game_.handle_event();
        game_.handle_game();
    }
    game_.clean();
    return 0;
}
