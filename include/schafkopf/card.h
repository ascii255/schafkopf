//
// Created by Thomas on 09.07.2017.
//
// http://www.schafkopfschule.de/index.php/regeln.html
// https://en.wikipedia.org/wiki/Tarot_card_games

#pragma once

#include <map>

namespace schafkopf {

using namespace std;

enum struct color {
    bell,
    heart,
    leave,
    acorn,
};

enum struct value {
    seven,
    eight,
    nine,
    jack,
    knight,
    king,
    ten,
    ace,
};

static const map<value, int> value_points =
        {
                {value::seven, 0},
                {value::eight, 0},
                {value::nine, 0},
                {value::jack, 2},
                {value::knight, 3},
                {value::king, 4},
                {value::ten, 10},
                {value::ace, 11},
        };

struct card {
    schafkopf::color color;
    schafkopf::value value;

    explicit operator int() const
    {
        return value_points.at(value);
    }

    int operator+(const card& other_card) const
    {
        return static_cast<int>(other_card)+static_cast<int>(*this);
    }

    bool operator==(const card& other_card) const
    {
        return color==other_card.color &&
                value==other_card.value;
    }

    bool operator!=(const card& other_card) const
    {
        return !(other_card==*this);
    }
};

}
