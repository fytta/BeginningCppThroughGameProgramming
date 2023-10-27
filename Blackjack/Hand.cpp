#include "Hand.h"


Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter; iter != m_Cards.end(); iter++)
	{
		delete *iter;
		*iter = nullptr;
	}
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty() || m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}
	
	int total = 0;
	bool containsAce = false;

	vector<Card*>::const_iterator iter = m_Cards.begin();
	for (iter; iter != m_Cards.end(); iter++)
	{
		int cardValue = (*iter)->GetValue();
		total += cardValue;

		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 11)
	{
		total += 10; // add only 10 since we've already added 1 for the ace
	}

	return total;
}