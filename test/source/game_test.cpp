#include <catch_with_main.hpp>
#include <schafkopf/deck.h>
#include <schafkopf/game.h>

using namespace std;

SCENARIO("game can be initialized", "[game]") {
    GIVEN("a freshly constructed game") {
        schafkopf::game game{schafkopf::bierkopf_deck};

        REQUIRE(size(game.players) == 4);
        REQUIRE(size(game.cards) == 32);

        WHEN("player is added") {
            game.players.emplace_back(make_shared<schafkopf::player>());

            THEN("size of player container is increased") {
                REQUIRE(size(game.players) == 5);
            }
        }
    }
}
