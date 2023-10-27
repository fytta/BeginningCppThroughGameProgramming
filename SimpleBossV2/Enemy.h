#pragma once

class Enemy
{
public:
	Enemy(int damage = 10, int damageMultiplier = 1);
	//virtual ~Enemy();

	void virtual Taunt() const; //made virtual to be overridden
	void virtual Attack() const; //made virtual to be overridden
protected:
	int m_Damage;
	int m_DamageMultiplier = 1;
};

