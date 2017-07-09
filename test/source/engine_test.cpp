//
// Created by Thomas on 08.07.2017.
//

#include <gtest/gtest.h>
#include <schafkopf/engine.h>
#include <schafkopf/algorithm.h>

class engine_test : public testing::Test
{
public:
	schafkopf::engine engine;

	void SetUp() override final
	{
		engine = {};
	}
};

TEST_F(engine_test, construct_game_object)
{
	EXPECT_EQ(size(engine.player), 4);
}

TEST_F(engine_test, sum_cards)
{
	auto card1 = schafkopf::card{schafkopf::color::acorn, schafkopf::value::knight};
	auto card2 = schafkopf::card{schafkopf::color::acorn, schafkopf::value::ace};
	EXPECT_EQ(card1 + card2, 14);
	const auto& deck = schafkopf::bierkopf_deck;
	const auto sum = std::accumulate(std::begin(deck), std::end(deck), 0);
	EXPECT_EQ(sum, 120);
}

TEST_F(engine_test, rank_of_card)
{
	const auto& deck = schafkopf::bierkopf_deck;
	const auto acorn_knight_card = schafkopf::card{schafkopf::color::acorn, schafkopf::value::knight};
	const auto bell_seven_card = schafkopf::card{schafkopf::color::bell, schafkopf::value::seven};
	const auto acorn_knight_rank = rank(deck, acorn_knight_card);
	const auto bell_seven_rank = rank(deck, bell_seven_card);
	EXPECT_EQ(acorn_knight_rank, 31);
	EXPECT_EQ(bell_seven_rank, 0);
}

TEST_F(engine_test, reset_game)
{
	engine.player[0].card.emplace_back(0);
	engine.reset();
	EXPECT_EQ(engine.player[0].card.empty(), true);
}

TEST_F(engine_test, restart_game)
{
	engine.restart();
	std::cout << "\n";
	for (const auto& player : engine.player)
	{
		std::copy(std::begin(player.card), std::end(player.card), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n";
	}
}
