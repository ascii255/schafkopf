//
// Created by Thomas on 18.07.2017.
//

#pragma once

#include <schafkopf/player.h>
#include <schafkopf/card.h>

namespace schafkopf {
using namespace std;

struct play {
    schafkopf::player& player;
    unique_ptr<schafkopf::card> card;
};
}
