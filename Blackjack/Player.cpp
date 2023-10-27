#include "Player.h"
#include <iostream>
using namespace std;



Player::Player(const string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
	cout << m_Name << " , do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (tolower(response) == 'y');
}

void Player::Win() const
{
	cout << m_Name << " wins.\n";
}

void Player::Lose() const
{
	cout << m_Name << " loses.\n";
}

void Player::Push() const
{
	cout << m_Name << " pushed.\n";
}

