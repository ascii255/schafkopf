#include <catch_with_main.hpp>
#include <schafkopf/deck.h>
#include <schafkopf/game.h>

using namespace std;

//! \test player can be added to game
SCENARIO("player is added to game", "[game]")
{
    GIVEN("a freshly constructed game with bierkopf deck") {
        schafkopf::game game{schafkopf::bierkopf_deck};
        REQUIRE(size(game.players)==4);
        REQUIRE(size(game.cards)==32);
        WHEN("player is added to game") {
            game.add_player();
            THEN("size of player container is increased by 1") {
                REQUIRE(size(game.players)==5);
            }
        }
    }
}

//! \test cards can be shuffled
SCENARIO("all cards of a game are shuffled", "[game][!mayfail]")
{
    GIVEN("a freshly constructed game with bierkopf deck") {
        schafkopf::game game{schafkopf::bierkopf_deck};
        REQUIRE(size(game.players)==4);
        REQUIRE(size(game.cards)==32);
        WHEN("cards are shuffled") {
            game.shuffle();
            THEN("cards are not in initial order") {
                REQUIRE(size(game.players)==4);
                REQUIRE(*game.cards[0]!=schafkopf::bierkopf_deck[0]);
            }
        }
    }
}

//! \test cards can be dealt
SCENARIO("8 cards are dealt to each player", "[game]")
{
    GIVEN("a freshly constructed game with bierkopf deck") {
        schafkopf::game game{schafkopf::bierkopf_deck};
        REQUIRE(size(game.players)==4);
        REQUIRE(size(game.cards)==32);
        schafkopf::player& player1 = *game.players[0];
        schafkopf::player& player2 = *game.players[1];
        schafkopf::player& player3 = *game.players[2];
        schafkopf::player& player4 = *game.players[3];
        WHEN("cards are dealt") {
            game.deal();
            THEN("cards are moved to players") {
                REQUIRE(size(game.cards)==0);
                REQUIRE(size(player1.cards)==8);
                REQUIRE(size(player2.cards)==8);
                REQUIRE(size(player3.cards)==8);
                REQUIRE(size(player4.cards)==8);
            }
        }
    }
}

//! \brief As a user, I want to play a card after the cards were shuffled and dealt.
//! \test player can play card
SCENARIO("player plays card", "[game]")
{
    GIVEN("a freshly constructed game with shuffled bierkopf deck") {
        schafkopf::game game{schafkopf::bierkopf_deck};
        REQUIRE(size(game.players)==4);
        REQUIRE(size(game.cards)==32);
        schafkopf::player& player1 = *game.players[0];
        schafkopf::player& player2 = *game.players[1];
        schafkopf::player& player3 = *game.players[2];
        schafkopf::player& player4 = *game.players[3];
        game.shuffle();
        game.deal();
        WHEN("player1 plays card") {
            THEN("card is moved to trick") {
                REQUIRE(size(player1.cards)==8);
            }
        }
    }
}
