//
// Created by Thomas on 08.07.2017.
//

#pragma once

#include <vector>
#include <schafkopf/card.h>

namespace schafkopf {

using namespace std;

struct player {
	vector<unique_ptr<schafkopf::card>> cards{};

	void reset()
	{
		cards.clear();
	}
};

}
