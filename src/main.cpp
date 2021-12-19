#include "application.h"
#include "sdlshim.h"

int main(int argc, char *argv[])
{
    SDL::SDLShim sdlShim;
    TTT::Configuration config;
    TTT::Application app(sdlShim, config);

    app.Run();

    return 0;
}
