#pragma once

#include <cstring>

namespace TTT
{

    struct GameState
    {
        enum Mark
        {
            empty = 0,
            X = 1,
            O = 2
        };

        void Reset()
        {
            memset(Position, empty, sizeof(Position));
        }

        Mark Position[3][3] = {};
    };

}
