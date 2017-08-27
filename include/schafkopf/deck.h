//
// Created by Thomas on 09.07.2017.
//

#pragma once

#include <array>
#include <schafkopf/card.h>

namespace schafkopf {

using namespace std;

constexpr static const array<card, 32> bierkopf_deck{
        card{color::bell, value::seven},
        card{color::bell, value::eight},
        card{color::bell, value::nine},
        card{color::bell, value::king},
        card{color::bell, value::ten},
        card{color::bell, value::ace},
        card{color::leave, value::seven},
        card{color::leave, value::eight},
        card{color::leave, value::nine},
        card{color::leave, value::king},
        card{color::leave, value::ten},
        card{color::leave, value::ace},
        card{color::acorn, value::seven},
        card{color::acorn, value::eight},
        card{color::acorn, value::nine},
        card{color::acorn, value::king},
        card{color::acorn, value::ten},
        card{color::acorn, value::ace},
        card{color::heart, value::seven},
        card{color::heart, value::eight},
        card{color::heart, value::nine},
        card{color::heart, value::king},
        card{color::heart, value::ten},
        card{color::heart, value::ace},
        card{color::bell, value::jack},
        card{color::heart, value::jack},
        card{color::leave, value::jack},
        card{color::acorn, value::jack},
        card{color::bell, value::knight},
        card{color::heart, value::knight},
        card{color::leave, value::knight},
        card{color::acorn, value::knight},
};

}
