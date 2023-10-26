#pragma once
#include "Player.h"
#include <iostream>
using namespace std;

class Lobby
{
public:
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_PtrHead = 0;
};

