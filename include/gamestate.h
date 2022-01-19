#pragma once

#include <string>
#include <cstring>
#include <assert.h>
#include <array>
#include <unordered_map>

namespace TTT
{

    class GameState
    {
    public:
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
            mRow = {};
        }

        std::string Serialize();

        void Deserialize(const std::string &s);

        using Row = std::array<Mark, 3>;

        Row &operator[](int i)
        {
            return mRow.at(i);
        }
        const Row &operator[](int i) const
        {
            return mRow.at(i);
        }

    private:
        static const std::array<unsigned char, 3> kMarkToChar;

        unsigned char ToChar(Mark m)
        {
            return kMarkToChar.at(int(m));
        }

        Mark FromChar(unsigned char c);

    private:
        std::array<Row, 3> mRow{};
    };

}
