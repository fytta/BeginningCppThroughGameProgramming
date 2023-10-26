#include "Lobby.h"
#include "Player.h"
#include <iostream>
using namespace std;

Lobby::Lobby()
{
	srand(static_cast<unsigned int>(time(0)));
}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	Player* ptrPlayer = new Player("Player");
	
	if (m_PtrHead == 0)
	{
		m_PtrHead = ptrPlayer;
	}
	else
	{
		Player* ptrIter = m_PtrHead;
		while (ptrIter->GetNext() != 0)
		{
			ptrIter = ptrIter->GetNext();
		}
		ptrIter->SetNext(ptrPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_PtrHead == 0)
	{
		cout << "The Game Lobby is empty" << endl;
	}
	else
	{
		Player* ptrTemp = m_PtrHead;        
		m_PtrHead = m_PtrHead->GetNext(); // set next player to current first player.
		delete ptrTemp; // clean memory of previous first player.
	}
}

void Lobby::Clear()
{
	while (m_PtrHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* ptrIter = aLobby.m_PtrHead;
	os << "\nHere's who's in the game lobby:\n";
	if (ptrIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (ptrIter != 0)
		{
			//os << ptrIter->GetName() << endl;
			os << ptrIter;
			ptrIter = ptrIter->GetNext();

		}
	}
	return os;
}