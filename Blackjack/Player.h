#pragma once
#include "GenericPlayer.h"

/// <summary>
/// A human Blackjack player.
/// </summary>
class Player : public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;

};
