#include <gtest/gtest.h>

#include "gamelogic.h"

TEST(GameState_TB, TestNewGame_NoWinner)
{
    TTT::GameState uut;

    ASSERT_EQ(TTT::GameLogic::Winner::none, TTT::GameLogic::CheckWinner(uut));
}

TEST(GameState_TB, TestRow0_XWin)
{
    TTT::GameState uut("XXX"
                       " O "
                       "  O");

    ASSERT_EQ(TTT::GameLogic::Winner::X, TTT::GameLogic::CheckWinner(uut));
}

TEST(GameState_TB, TestRow1_XWin)
{
    TTT::GameState uut("   "
                       "XXX"
                       "OO ");

    ASSERT_EQ(TTT::GameLogic::Winner::X, TTT::GameLogic::CheckWinner(uut));
}


TEST(GameState_TB, TestCol0_OWin)
{
    TTT::GameState uut("OXX"
                       "O  "
                       "O  ");

    ASSERT_EQ(TTT::GameLogic::Winner::O, TTT::GameLogic::CheckWinner(uut));
}

TEST(GameState_TB, TestDiag_OWin)
{
    TTT::GameState uut("OXX"
                       " O "
                       "  O");

    ASSERT_EQ(TTT::GameLogic::Winner::O, TTT::GameLogic::CheckWinner(uut));
}
