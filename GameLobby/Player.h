#pragma once
#include <string>
#include <iostream>
using std::string;


class Player
{
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);
	int GetId() const;

private:
	int m_Id = -1;
	string m_Name = "";
	Player* m_PtrNext = 0; // Represent de init node of linked list
};

