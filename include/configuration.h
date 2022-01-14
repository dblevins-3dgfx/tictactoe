#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace TTT
{

    // Eventually this could/should be constructed from a
    // configuration file (JSON). Hardwired for now.
    class Configuration
    {
    public:
        Configuration()
        {
            const int coloff = 90;
            const int colw = 160;
            const int rowoff = 40;
            const int rowh = 140;
            const int col[3] {coloff, coloff+colw, coloff+(2*colw)};
            const int row[3] {rowoff, rowoff+rowh, rowoff+(2*rowh)};

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    Position[i][j] = {col[j], row[i], 110, 110};
                }
            }

            CurrentPlayerIndicator = {0, 0, 55, 55};
        }

        const std::string GetBoardPNGPath() const { return "../assets/images/board.png"; }
        const std::string GetXPNGPath() const { return "../assets/images/X.png"; }
        const std::string GetOPNGPath() const { return "../assets/images/O.png"; }

        SDL_Rect Position[3][3];
        SDL_Rect CurrentPlayerIndicator;
    };

}