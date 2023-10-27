#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

/// <summary>
/// A Blackjack deck. Has extra functionality that Hand doesn't, such as shuffling and dealing.
/// </summary>
class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();

	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};

