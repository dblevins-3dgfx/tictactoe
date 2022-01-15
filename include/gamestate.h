#pragma once

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

        GameState(const std::string& s)
        {
            Deserialize(s);
        }

        void Reset()
        {
            memset(Position, empty, sizeof(Position));
        }

        static unsigned char ToChar(Mark m)
        {
            unsigned char result = ' ';
            switch (m)
            {
                case X:
                    result = 'X';
                    break;
                case O:
                    result = 'O';
                    break;
            }
            return result;
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

        void Deserialize(const std::string& s)
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
