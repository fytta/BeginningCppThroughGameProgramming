#pragma once
#include "Hand.h"
#include <vector>
#include <string>
using namespace std;

/// <summary>
/// Abstract class.
/// A generic Blackjack player. Not a full player, but the common elements of a human player and the computer player.
/// </summary>
class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	/// <summary>
	///		Indicates whether the generic players wants another hit. Pure virtual function.
	/// </summary>
	/// <returns>
	///		bool indicating true if wants another, false otherwise
	/// </returns>
	virtual bool IsHitting() const = 0;

	/// <summary>
	///		Busted is when exceeds 21
	/// </summary>
	/// <returns> 
	///		bool: true when is busted, false otherwise. 
	/// </returns>
	bool IsBusted() const; 
	
	/// <summary>
	///		Announces that the generic player is busted.
	/// </summary>
	void Bust() const;

protected:
	string m_Name;

};

