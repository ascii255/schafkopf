//
// Created by Thomas on 09.07.2017.
//

#pragma once

#include <schafkopf/card.h>
#include <schafkopf/deck.h>

namespace schafkopf {
using namespace std;

template<typename T>
int rank(const T &deck, const card &card) {
  const auto match = find(begin(deck), end(deck), card);
  return static_cast<int>(distance(begin(deck), match));
}
}
