#include "Enemy.h"
#include <iostream>
using namespace std;



Enemy::Enemy(int damage, int damageMultiplier): 
	m_Damage(damage),
	m_DamageMultiplier(damageMultiplier)
{}

void Enemy::Taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
	cout << "Attack! Inflicts " << m_Damage * m_DamageMultiplier << " damage points.";
}