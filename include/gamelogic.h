#pragma once

#include "gamestate.h"

namespace TTT
{

    class GameLogic
    {
    public:
        enum Winner
        {
            none = GameState::Mark::empty,
            X = GameState::Mark::X,
            O = GameState::Mark::O
        };

        static Winner CheckWinner(const GameState &gs)
        {
            Winner result = CheckRows(gs);
            if (result == Winner::none)
            {
                result = CheckCols(gs);
            }
            if (result == Winner::none)
            {
                result = CheckDiag(gs);
            }
            return result;
        }

    private:
        static Winner CheckRows(const GameState &gs)
        {
            Winner result = Winner::none;
            for (int i = 0; i < 3; i++)
            {
                if ((gs[i][0] == gs[i][1]) &&
                    (gs[i][0] == gs[i][2]))
                {
                    result = Winner(gs[i][0]);
                }
            }
            return result;
        }

        static Winner CheckCols(const GameState &gs)
        {
            Winner result = Winner::none;
            for (int j = 0; j < 3; j++)
            {
                if ((gs[0][j] == gs[1][j]) &&
                    (gs[0][j] == gs[2][j]))
                {
                    result = Winner(gs[0][j]);
                }
            }
            return result;
        }

        static Winner CheckDiag(const GameState &gs)
        {
            Winner result = Winner::none;
            if ((gs[1][1] == gs[0][0]) &&
                (gs[1][1] == gs[2][2]))
            {
                result = Winner(gs[1][1]);
            }
            else if ((gs[1][1] == gs[0][2]) &&
                     (gs[1][1] == gs[2][0]))
            {
                result = Winner(gs[1][1]);
            }
            return result;
        }
    };

}
