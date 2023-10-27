#pragma once
#include "Boss.h"
class FinalBoss: public Boss
{
public:
	FinalBoss(int damage = 30, int damageMultiplier = 10);
	//virtual ~FinalBoss();
	
	void virtual Taunt() const; //optional use of keyword virtual
	void virtual Attack() const; //optional use of keyword virtual
};

