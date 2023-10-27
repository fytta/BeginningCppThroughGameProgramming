#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"

/// <summary>
/// A Blackjack game
/// </summary>
class Game
{
public:
	Game(const vector<string>& aNames);
	~Game();

	/// <summary>
	///		Plays a round of Blackjack.
	/// </summary>
	void Play();

private:
	/// <summary>
	///		A deck of cards.
	/// </summary>
	Deck m_Deck;

	/// <summary>
	///		The casino's hand, the house.
	/// </summary>
	House m_House;

	/// <summary>
	///		Collection of human players. A vector of Player objects.
	/// </summary>
	vector<Player> m_Players;


};

