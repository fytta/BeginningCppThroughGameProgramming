#pragma once
#include "Hand.h"
#include "Card.h"
#include "GenericPlayer.h"
#include <vector>
using namespace std;

/// <summary>
/// A Blackjack deck. Has extra functionality that Hand doesn't, such as shuffling and dealing.
/// </summary>
class Deck : public Hand
{
public:
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);

private:
	//vector<Card*> cards;

};

