//
// Created by Thomas on 08.07.2017.
//

#pragma once

#include <array>
#include <numeric>
#include <random>
#include <memory>
#include <schafkopf/player.h>
#include <schafkopf/deck.h>
#include <schafkopf/card.h>

namespace schafkopf {

using namespace std;

class engine {
public:
		vector<shared_ptr<player>> player;
		mt19937 generator{random_device{}()};

//		void start()
//		{
//			shuffle();
//			deal();
//			sort();
//		}
//
//		void restart()
//		{
//			reset();
//			start();
//		}

//		void shuffle()
//		{
//			const auto end = std::end(card);
//			std::iota(std::begin(card), std::end(card), 0);
//			std::shuffle(std::begin(card), std::end(card), generator);
//		}
//
//		void deal()
//		{
//			auto begin = std::begin(card);
//			for (auto& player : player)
//			{
//				player.hand.resize(6);
//				std::move(begin, begin + 6, std::begin(player.hand));
//				begin += 6;
//			}
//		}
//
//		void sort()
//		{
//			for (auto& player : player) std::sort(std::begin(player.hand), std::end(player.hand));
//		}
//
//		void reset()
//		{
//			for (auto& player : player) player.reset();
//		}
};

}
