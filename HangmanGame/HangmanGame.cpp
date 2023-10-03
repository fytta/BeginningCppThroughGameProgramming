// HangmanGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;


// setup
const int MAX_WRONG = 8;

int wrong = 0;

string THE_WORD = "";
string soFar = "";
string used = "";
vector<string> words;

// function definitions
void initialize();
char guessLoop();
bool checkAnswer(char guess);
void endGame();

int main()
{
    initialize();

    cout << "Welcome to Hangman. Good luck!\n";

    // game loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess = guessLoop();
        used += guess;
        
        checkAnswer(guess);
    }

    endGame();

    return 0;
}


// function implementations
void initialize()
{
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    THE_WORD = words[0];
    soFar = string(THE_WORD.size(), '-');
}

char guessLoop()
{
    char guess;

    cout << "Enter your guess: ";
    cin >> guess;

    while (used.find(guess) != string::npos)
    {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
    } 

    return guess;
}

bool checkAnswer(char guess)
{
	guess = toupper(guess);
    if (THE_WORD.find(guess) != string::npos)
    {
        cout << "That's right! " << guess << " is in the word.\n";
        //update soFar to include newly guessed letter
        for (int i = 0; i < THE_WORD.length(); ++i)
        {
            if (THE_WORD[i] == guess)
            {
                soFar[i] = guess;
            }
        }
        return true;
    }
    else
    {
        cout << "Sorry, " << guess << " isn't in the word.\n";
        wrong++;
        return false;
    }
}

void endGame()
{
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout << "\nYou guessed it!";
    }
}
























