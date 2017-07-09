//
// Created by Thomas on 09.07.2017.
//

#pragma once

namespace schafkopf
{
	template<typename T>
	int rank(const T& deck, const card& card)
	{
		const auto match = std::find(std::begin(deck), std::end(deck), card);
		return std::distance(std::begin(deck), match);
	}
}
