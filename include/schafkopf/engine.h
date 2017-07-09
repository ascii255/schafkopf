//
// Created by Thomas on 08.07.2017.
//

#pragma once

#include <array>
#include <numeric>
#include <random>
#include <schafkopf/player.h>
#include <schafkopf/deck.h>
#include <schafkopf/card.h>

namespace schafkopf
{
	class engine
	{
	public:
		std::array<player, 4> player{};
		std::array<int, 24> card{};
		std::mt19937 generator{std::random_device{}()};

		void start()
		{
			shuffle();
			deal();
			sort();
		}

		void restart()
		{
			reset();
			start();
		}

		void shuffle()
		{
			const auto end = std::end(card);
			std::iota(std::begin(card), std::end(card), 0);
			std::shuffle(std::begin(card), std::end(card), generator);
		}

		void deal()
		{
			auto begin = std::begin(card);
			for (auto& player : player)
			{
				player.card.resize(6);
				std::move(begin, begin + 6, std::begin(player.card));
				begin += 6;
			}
		}

		void sort()
		{
			for (auto& player : player) std::sort(std::begin(player.card), std::end(player.card));
		}

		void reset()
		{
			for (auto& player : player) player.card.clear();
		}
	};
}
