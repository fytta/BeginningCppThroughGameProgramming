#include "House.h"
#include <string>
#include <iostream>
using namespace std;


House::House(const string& aName): GenericPlayer(aName)
{}

House::~House()
{}

bool House::IsHitting() const
{
	return GetTotal() <= 16;
}

void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
	{
		m_Cards[0]->Flip();
	}
	else
	{
		cout << "No card to flip!" << endl;
	}
}
