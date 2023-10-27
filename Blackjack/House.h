#pragma once
#include "GenericPlayer.h"

/// <summary>
/// The computer player, the house
/// </summary>
class House : public GenericPlayer
{
public:
	virtual bool IsHitting() const;
	void FlipFirstCard();

private:


};

