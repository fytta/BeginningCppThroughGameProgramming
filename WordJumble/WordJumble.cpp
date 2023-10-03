// Word Jumble Game
// Player has to guess the word. He can ask for hints.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout, std::cin, std::endl, std::string, std::vector;


class Menu
{
private :
    enum difficulty { EASY = 10, MEDIUM = 5, HARD = 3 };

    // param int with the position of difficulty. Return difficulty enum element.
    difficulty intToDifficulty(int diff)
    {
        if (diff == 1) {
            return EASY;
        }
        else if (diff == 2) {
            return MEDIUM;
        }
        else {
            return HARD;
        }
    };

public:
    void displayWelcome()
    {
        cout << "###\tWelcome to Word Jumble!\t###" << endl;
        cout << "Unscramble the letters to make a word." << endl;
        cout << "Enter 'hint' for a hint." << endl;
        cout << "Enter 'quit' to quit the game.\n" << endl;
    }

    int chooseDifficulty()
    {
        cout << "You have to choose a difficulty level: " << endl;
        cout << "1. EASY: 10 attempts." << endl;
        cout << "2. MEDIUM: 5 attempts." << endl;
        cout << "3. HARD: 3 attempts." << endl;
        cout << "Enter your choice (1,2,3): " << endl;

        int difficultyLevel;
		cin >> difficultyLevel;
        return intToDifficulty(difficultyLevel);
    }
};

/// <summary>
/// Gets a string a returns a jumbled version of the word.
/// </summary>
/// <param name="word">string that is to be scrambled.</param>
/// <returns>
///     string with the jumble word
/// </returns>
string jumbleWord(string word)
{
    string jumble = word;
    int length = jumble.size();
    for (int i = 0; i < length; i++) {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumble[index1];

        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    return jumble;
}

// Global variables
enum fields { WORD, HINT, NUM_FIELDS };
const int NUM_WORDS = 5;
const string WORDS[NUM_WORDS][NUM_FIELDS] =
{
    {"wall", "Do you feel you’re banging your head against something?"},
    {"glasses", "These might help you see the answer."},
    {"labored", "Going slowly, is it?"},
    {"persistent", "Keep at it."},
    {"jumble", "It’s what the game is all about."}
};

/// <summary>
/// Gets a random word from the array of words and returns an array with the word, hint and its jumble.
/// </summary>
/// <returns>vector<string>{ word, hint, jumble }</returns>
vector<string> getRandomWord()
{
    int choice = (rand() % NUM_WORDS);
    string word = WORDS[choice][0]; // word to guess
    string hint = WORDS[choice][1]; // hint for the player
    string jumble = jumbleWord(word);

    return vector<string>{ word, hint, jumble };
}

//TODO: Remove the words previously guessed by the player.
//      Scoring points
int main()
{
    // Setup game props
    srand(static_cast<unsigned int>(time(0)));
    int score = 0;

	// Pick random word from the list of words
	vector<string> choice = getRandomWord();
	string word = choice[WORD]; // word to guess
	string hint = choice[HINT]; // hint for the player
	string jumble = choice[2];

    // Welcome and start the game
    Menu menu;
	menu.displayWelcome();
    int attempts = menu.chooseDifficulty();

    cout << "The jumble word is: " << jumble;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;


    // Game loop
    while (guess != "quit" && attempts > 0) 
    {
        if (guess == "hint")
        {
            cout << hint;
        }
        else if (guess == word)
        {
            score += 25;
            cout << "You got it! The word was: " << word << endl;
            cout << "You have " << score << " points!" << endl;
			char continueGame = 'n';
            cout << "Do you want to play again? (y/n): ";
			cin >> continueGame;

            if (continueGame == 'y')
            {
                vector<string> choice = getRandomWord();
                string word = choice[WORD]; // word to guess
                string hint = choice[HINT]; // hint for the player
                string jumble = choice[2];
            }
            else
            {
                break;
            }
        }
        else
        {
			cout << "Sorry, that's not it. Try again." << endl;
            attempts--;
            score -= 10;
            cout << "You have " << score << " points" << endl;
        }
        cout << "\nYour guess: ";
        cin >> guess;
    }

    // Exit the game
    if (attempts == 0) {
        cout << "oh! You've spent all your attempts." << endl;
        cout << "Final score: " << score << " points." << endl;
        cout << "See you next time!" << endl;
    }
    else
    {
        cout << "Final score: " << score << " points." << endl;
        cout << "Good bye! See you next time!" << endl;
    }

    return 0;
}