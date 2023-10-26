// GameLobby.cpp : It simulates a game lobby where exists a waiting area for players.
// Menu options: He can add a person to the lobby, remove a person from the lobby (the first person in line is the first to leave), clear out the lobby, or quit the simulation.

#include "Lobby.h"
#include <iostream>
using namespace std;



int main()
{
	Lobby myLobby;
	int choice;

	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cout << endl << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
			case 0: 
				cout << "Good bye.\n"; 
				break;
			case 1: 
				myLobby.AddPlayer(); 
				break;
			case 2: 
				myLobby.RemovePlayer(); 
				break;
			case 3: 
				myLobby.Clear(); 
				break;
			default:
				cout << "That was not a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}


