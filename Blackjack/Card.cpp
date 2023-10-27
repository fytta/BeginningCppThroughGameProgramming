#include "Card.h"
using namespace std;


Card::Card(rank r, suit s, bool isFaceUp): m_Rank(r), m_Suit(s), m_IsFaceUp(isFaceUp)
{}

int Card::GetValue() const
{
	int value = 0; // cards is face down, value is 0
	if (m_IsFaceUp)
	{
		value = m_Rank; // value is number showing on card
		if (value > 10) // face cards
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
}