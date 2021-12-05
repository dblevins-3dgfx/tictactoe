#pragma once

#include <string>

namespace TTT
{

    // Eventually this could/should be constructed from a
    // configuration file (JSON). Hardwired for now.
    class Configuration
    {
    public:
        const std::string GetBoardPNGPath() const { return "../assets/images/board.png"; }
    };

}