#pragma once
#include <ostream>
using namespace std;

/// <summary>
/// A Blackjack playing card.
/// </summary>
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONS, HERATS, SPADES };

	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r, suit s, bool isFaceUp);

	/// <summary>
	///		Return value of the card, 1 to 11.
	/// </summary>
	int GetValue() const;

	/// <summary>
	///		Flips a card
	/// </summary>
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};