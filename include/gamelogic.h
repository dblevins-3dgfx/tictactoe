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

        static Winner CheckWinner(const GameState& gs)
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

        static Winner CheckRows(const GameState& gs)
        {
            Winner result = Winner::none;
            for (int i = 0; i < 3; i++)
            {
                if ((gs.Position[i][0] == gs.Position[i][1]) && 
                    (gs.Position[i][0] == gs.Position[i][2]))
                {
                    result = Winner(gs.Position[i][0]);
                    break;
                }
            }
            return result;
        }

        static Winner CheckCols(const GameState& gs)
        {
            Winner result = Winner::none;
            for (int j = 0; j < 3; j++)
            {
                if ((gs.Position[0][j] == gs.Position[1][j]) && 
                    (gs.Position[0][j] == gs.Position[2][j]))
                {
                    result = Winner(gs.Position[0][j]);
                    break;
                }
            }
            return result;
        }

        static Winner CheckDiag(const GameState& gs)
        {
            Winner result = Winner::none;
            if ((gs.Position[1][1] == gs.Position[0][0]) &&
                (gs.Position[1][1] == gs.Position[2][2]))
            {
                result = Winner(gs.Position[1][1]);
            }
            else if ((gs.Position[1][1] == gs.Position[0][2]) &&
                     (gs.Position[1][1] == gs.Position[2][0]))
            {
                result = Winner(gs.Position[1][1]);
            }
            return result;
        }



    };

}
