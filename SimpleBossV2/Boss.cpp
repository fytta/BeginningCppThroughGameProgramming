#include "Boss.h"
#include "Enemy.h"
#include <iostream>
using namespace std;



Boss::Boss(int damage, int damageMultiplier) : Enemy(damage, damageMultiplier)
{}

void Boss::Taunt() const 
{
	cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const
{
	Enemy::Attack(); //call base class member function
	cout << " And laughs heartily at you.\n";
}