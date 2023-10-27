#include "FinalBoss.h"
#include "Boss.h"
#include <iostream>
using namespace std;


FinalBoss::FinalBoss(int damage, int damageMultiplier): Boss(damage, damageMultiplier)
{}

void FinalBoss::Taunt() const
{
	cout << "The boss says he will end your pitiful existence.\n";
}

void FinalBoss::Attack() const
{
	Enemy::Attack(); //call base class member function
	cout << " And laughs heartily at you.\n";
}