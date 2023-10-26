#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Player::Player(const string& name)
{
	m_Id = rand() % 100 + 1;
	m_Name = name + to_string(m_Id);
	m_PtrNext = 0;
}

Player* Player::GetNext() const
{
	return m_PtrNext;
}

void Player::SetNext(Player* next)
{
	m_PtrNext = next;
}

string Player::GetName() const
{
	return m_Name;
}

int Player::GetId() const
{
	return m_Id;
}