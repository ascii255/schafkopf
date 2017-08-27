//
// Created by Thomas on 09.07.2017.
//

#pragma once

#include <memory>
#include <vector>
#include <schafkopf/player.h>
#include <schafkopf/trick.h>
#include <numeric>
#include <random>

namespace schafkopf {

using namespace std;

class game {
    using cards_type = vector<unique_ptr<card>>;
    using players_type = vector<shared_ptr<player>>;
public:
    cards_type cards;
    players_type players = players_type(4, make_shared<player>());
    mt19937 generator{random_device{}()};

    template<typename T>
    explicit game(const T& deck) { for (auto& card : deck) cards.emplace_back(make_unique<schafkopf::card>(card)); }

    void shuffle() { std::shuffle(begin(cards), end(cards), generator); }

    void deal()
    {
        auto iterator = begin(cards);
        auto player_card_count = size(cards)/size(players);
        for (auto& player : players) {
            player->cards.resize(player_card_count);
            move(iterator, iterator += player_card_count, begin(player->cards));
            sort(begin(player->cards), end(player->cards));
        }
        cards.clear();
    }

    unique_ptr<card>&& move_card(const shared_ptr<player>& player, unique_ptr<card>&& card)
    {
        auto card_of_player = find(begin(player->cards), end(player->cards), card);
        auto&& result = move(card);
        player->cards.erase(card_of_player);
        return move(result);
    }

    void add_player()
    {
        players.emplace_back(make_shared<schafkopf::player>());
    }
};

}
