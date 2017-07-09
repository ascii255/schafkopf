//
// Created by Thomas on 09.07.2017.
//
// http://www.schafkopfschule.de/index.php/regeln.html
// https://en.wikipedia.org/wiki/Tarot_card_games

#pragma once

namespace schafkopf
{
	enum struct color
	{
		bell,
		heart,
		leave,
		acorn,
	};

	enum struct value
	{
		seven = 0,
		eight = 0,
		nine = 0,
		jack = 2,
		knight = 3,
		king = 4,
		ten = 10,
		ace = 11,
	};

	struct card
	{
		schafkopf::color color;
		schafkopf::value value;

		operator int() const
		{
			return static_cast<int>(value);
		}

		int operator+(const card& other_card) const
		{
			return static_cast<int>(other_card) + static_cast<int>(*this);
		}

		bool operator==(const card& other_card) const
		{
			return color == other_card.color &&
			       value == other_card.value;
		}

		bool operator!=(const card& other_card) const
		{
			return !(other_card == *this);
		}
	};
}