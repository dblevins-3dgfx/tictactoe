#include "gamestate.h"

namespace TTT
{
    const std::array<unsigned char, 3> GameState::kMarkToChar{' ', 'X', 'O'};

    std::string GameState::Serialize()
    {
        std::string result;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                result.append(1, ToChar(mRow[i][j]));
            }
        }
        return result;
    }

    void GameState::Deserialize(const std::string &s)
    {
        assert(s.size() == 9);
        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mRow[i][j] = FromChar(s[idx++]);
            }
        }
    }

    GameState::Mark GameState::FromChar(unsigned char c)
    {
        static const std::unordered_map<unsigned char, Mark> charToMark = [this]()
        {
            std::unordered_map<unsigned char, Mark> c2m;

            for (int i = 0; i < kMarkToChar.size(); i++)
            {
                auto mark = Mark(i);
                c2m[ToChar(mark)] = mark;
            }

            return c2m;
        }();
        return charToMark.at(c);
    }

}
