#pragma once
#include "Enemy.h"

class Boss: public Enemy
{
public:
	Boss(int damage = 30, int damageMultiplier = 2);
	//virtual ~Boss();

	void virtual Taunt() const; //optional use of keyword virtual
	void virtual Attack() const; //optional use of keyword virtual
};

