#include "application.h"

int main(int argc, char *argv[])
{
    TTT::Configuration config;
    TTT::Application app(config);

    app.Run();

    return 0;
}
