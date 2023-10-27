//Simple Boss 2.0
//Demonstrates access control under inheritance
#include <iostream>
#include "Enemy.h"
#include "FinalBoss.h"
using namespace std;



int main()
{
	cout << "Enemy object:\n";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();
	cout << "\n\nBoss object:\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();
	cout << "\n\nFinal Boss object:\n";
	FinalBoss aFinalBoss;
	aFinalBoss.Taunt();
	aFinalBoss.Attack();
	return 0;
}