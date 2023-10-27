#pragma once
#include "Hand.h"
#include "Card.h"
#include <vector>
using namespace std;

/// <summary>
/// A Blackjack hand. A collection of Card objects.
/// </summary>
class Hand
{
public:
	Hand();
	virtual ~Hand();

	void Add(Card* card);
	void Clear();
	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};

