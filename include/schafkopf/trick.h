//
// Created by Thomas on 09.07.2017.
//

#pragma once

#include <schafkopf/card.h>
#include <schafkopf/player.h>

namespace schafkopf {

using namespace std;

struct trick {
  vector<unique_ptr<schafkopf::card>> cards;
  shared_ptr<schafkopf::player> winner;

  void add(unique_ptr<schafkopf::card>&& card, shared_ptr<player>& player)
  {
      this->cards.emplace_back(move(card));
      if (winner==nullptr) winner = player;
  }
};

}
