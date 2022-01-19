#include <gtest/gtest.h>

#include "gamestate.h"

using TTT::GameState;

static bool IsNewGame(const TTT::GameState &gs)
{
    bool result = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gs[i][j] != TTT::GameState::empty)
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
    uut[0][0] = TTT::GameState::X;
    ASSERT_FALSE(IsNewGame(uut));
    uut.Reset();
    ASSERT_TRUE(IsNewGame(uut));
}

TEST(GameState_TB, TestCopyConstruction)
{
    TTT::GameState orig;
    orig[2][2] = TTT::GameState::O;

    TTT::GameState copy(orig);
    ASSERT_EQ(copy[2][2], TTT::GameState::O);
    ASSERT_EQ(copy[0][0], TTT::GameState::empty);
}

TEST(GameState_TB, TestToChar)
{
    ASSERT_EQ(' ', GameState::ToChar(GameState::empty));
    ASSERT_EQ('X', GameState::ToChar(GameState::X));
    ASSERT_EQ('O', GameState::ToChar(GameState::O));
}

TEST(GameState_TB, TestFromChar)
{
    ASSERT_EQ(GameState::empty, GameState::FromChar(' '));
    ASSERT_EQ(GameState::X, GameState::FromChar('X'));
    ASSERT_EQ(GameState::O, GameState::FromChar('O'));
}

TEST(GameState_TB, TestSerializeEmpty)
{
    TTT::GameState uut;
    ASSERT_EQ("   "
              "   "
              "   ",
              uut.Serialize());
}

TEST(GameState_TB, TestSerializeOneX)
{
    TTT::GameState uut;

    uut[0][0] = GameState::Mark::X;
    ASSERT_EQ("X  "
              "   "
              "   ",
              uut.Serialize());
}

TEST(GameState_TB, TestSerializeLots)
{
    TTT::GameState uut;

    uut[0][0] = GameState::Mark::X;
    uut[0][1] = GameState::Mark::O;
    uut[0][2] = GameState::Mark::X;

    uut[1][0] = GameState::Mark::O;
    uut[1][1] = GameState::Mark::X;
    uut[1][2] = GameState::Mark::O;

    uut[2][0] = GameState::Mark::X;
    uut[2][1] = GameState::Mark::O;
    uut[2][2] = GameState::Mark::X;
    ASSERT_EQ("XOX"
              "OXO"
              "XOX",
              uut.Serialize());
}

TEST(GameState_TB, TestDeserializeEmpty)
{
    TTT::GameState uut;
    uut[0][0] = GameState::Mark::X;
    uut.Deserialize("   "
                    "   "
                    "   ");
    ASSERT_TRUE(IsNewGame(uut));
}

TEST(GameState_TB, TestDeserialize)
{
    TTT::GameState uut;

    uut.Deserialize("XOX"
                    "OXO"
                    "XOX");
    ASSERT_EQ(GameState::Mark::X, uut[0][0]);
    ASSERT_EQ(GameState::Mark::O, uut[0][1]);
    ASSERT_EQ(GameState::Mark::X, uut[0][2]);

    ASSERT_EQ(GameState::Mark::O, uut[1][0]);
    ASSERT_EQ(GameState::Mark::X, uut[1][1]);
    ASSERT_EQ(GameState::Mark::O, uut[1][2]);

    ASSERT_EQ(GameState::Mark::X, uut[2][0]);
    ASSERT_EQ(GameState::Mark::O, uut[2][1]);
    ASSERT_EQ(GameState::Mark::X, uut[2][2]);
}

TEST(GameState_TB, TestStringConstruction)
{
    TTT::GameState uut("XOX"
                       "OXO"
                       "XOX");
    ASSERT_EQ(GameState::Mark::X, uut[0][0]);
    ASSERT_EQ(GameState::Mark::O, uut[0][1]);
    ASSERT_EQ(GameState::Mark::X, uut[0][2]);

    ASSERT_EQ(GameState::Mark::O, uut[1][0]);
    ASSERT_EQ(GameState::Mark::X, uut[1][1]);
    ASSERT_EQ(GameState::Mark::O, uut[1][2]);

    ASSERT_EQ(GameState::Mark::X, uut[2][0]);
    ASSERT_EQ(GameState::Mark::O, uut[2][1]);
    ASSERT_EQ(GameState::Mark::X, uut[2][2]);
}
