#include <gtest/gtest.h>

#include "gamestate.h"

static bool IsNewGame(const TTT::GameState gs)
{
    bool result = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gs.Position[i][j] != TTT::GameState::empty)
            {
                result = false;
            }
        }
    }

    return result;
}

TEST(GameState_TB, TestConstruction)
{
    TTT::GameState uut;

    ASSERT_TRUE(IsNewGame(uut));
}

TEST(GameState_TB, TestReset)
{
    TTT::GameState uut;

    ASSERT_TRUE(IsNewGame(uut));
    uut.Position[0][0] = TTT::GameState::X;
    ASSERT_FALSE(IsNewGame(uut));
    uut.Reset();
    ASSERT_TRUE(IsNewGame(uut));
}

TEST(GameState_TB, TestCopyConstruction)
{
    TTT::GameState orig;
    orig.Position[2][2] = TTT::GameState::O;

    TTT::GameState copy(orig);
    ASSERT_EQ(copy.Position[2][2], TTT::GameState::O);
    ASSERT_EQ(copy.Position[0][0], TTT::GameState::empty);
}

