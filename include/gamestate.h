#pragma once

#include <string>
#include <cstring>
#include <assert.h>

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

        GameState() = default;

        GameState(const std::string &s)
        {
            Deserialize(s);
        }

        void Reset()
        {
            memset(Position, empty, sizeof(Position));
        }

        static unsigned char ToChar(Mark m)
        {
            switch (m)
            {
            case empty:
                return ' ';
                break;
            case X:
                return 'X';
                break;
            case O:
                return 'O';
                break;
            }
            return ' ';
        }

        static Mark FromChar(unsigned char c)
        {
            Mark result = Mark::empty;
            switch (c)
            {
            case 'X':
                result = Mark::X;
                break;
            case 'O':
                result = Mark::O;
                break;
            }
            return result;
        }

        std::string Serialize()
        {
            std::string result;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    result.append(1, ToChar(Position[i][j]));
                }
            }
            return result;
        }

        void Deserialize(const std::string &s)
        {
            assert(s.size() == 9);
            int idx = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Position[i][j] = FromChar(s[idx++]);
                }
            }
        }

        Mark Position[3][3] = {};
    };

}
