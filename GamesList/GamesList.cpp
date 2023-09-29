// GamesList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void listGames(vector<string> games)
{
	for (vector<string>::iterator it = games.begin(); it < games.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}

void displayMenu()
{
	cout << "Select an option: " << endl;
	cout << "1.Add game" << endl;
	cout << "2.Delete game" << endl;
	cout << "3.List games" << endl;
	cout << "4.Sort games" << endl;
	cout << "5.Shuffle games" << endl;
	cout << "4.Exit" << endl;
	cout << ">> Select an option: ";
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	vector<string> games{ "Counter-Strike", "S.K.I.L.L SF2", "Metin2", "World of Warcraft" };
	int option = -1;
	string input;
	vector<string>::iterator iter;

	cout << "### My games list ###!\n";
	cout << "This is your current list of games:" << endl;
	listGames(games);

	do {


		displayMenu();
		cin.clear();
		cin >> option;

		switch(option)
		{
			case 1:
				cout << "Type name: ";
				cin >> input;
				games.push_back(input);
				listGames(games);
				break;

			case 2:
				cout << "Type name: ";
				cin >> input;
				cout << "typed " << input << endl;
				iter = find(games.begin(), games.end(), input);
				if (iter == games.end())
				{
					cout << "Not found." << endl;
				}
				else
				{
					games.erase(iter);
					cout << "\nDeleted successfully" << endl;
				}
				listGames(games);
				break;

			case 3:
				listGames(games);
				break;
			case 4:
				sort(games.begin(), games.end());
				listGames(games);
				break;

			case 5:
				random_shuffle(games.begin(), games.end());
				listGames(games);
				break;
		}

	} while (4 != 0);

	cout << "Good bye!\n";
}