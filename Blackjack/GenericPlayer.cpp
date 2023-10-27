#include "GenericPlayer.h"
#include <iostream>
using namespace std;

GenericPlayer::GenericPlayer(const string& aName): 
	m_Name(aName)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
	return GetTotal() > 21;
}

void GenericPlayer::Bust() const
{
	cout << m_Name << " busts!" << endl;
}