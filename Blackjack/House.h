#pragma once
#include "GenericPlayer.h"
#include <string>

/// <summary>
/// The computer player, the house
/// </summary>
class House : public GenericPlayer
{
public:
	House(const string& aName = "House");
	virtual ~House();

	virtual bool IsHitting() const;
	void FlipFirstCard();
};

