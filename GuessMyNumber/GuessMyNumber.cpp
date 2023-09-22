#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl, std::string, std::srand, std::time, std::exception, std::vector;

// You can choose the player. Machine has to guess the number of your choice or you have to guess it.
// There are 3 difficulties with different number of attempts to guess the number.

class Menu {

private: 
    // Number of attempts to guess the 
    enum DIFFICULTY { EASY = 10, MEDIUM = 5, HARD = 3 };
    int guessNumber = -1;

    // Menu options text
    string playerMenu = "\nNumber has to be greater or equals than 0.\nWho guess the number?\n1.You\n2.Machine\n";
    string diffMenu = "\nChoose difficulty level\n1.EASY\n2.MEDIUM\n3.HARD\n";


public:
    void displayPlayerSelection() {
        cout << playerMenu;
    };

    void displayDifficultySelection() {
        cout << diffMenu;
    };

    // param int with the position of difficulty. Return DIFFICULTY enum element.
    DIFFICULTY intToDifficulty(int diff) {
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
};


class Player {

private:
    int number = -1;

public:
    vector<int> oldNumbers; // array with the numbers typed
    bool isMachine = false;
    
    // Return a rand number between 0 and 20
    int chooseRandomNumber() {
        do {
            number = rand() % 20 + 1;
        } while (isAlreadySelected(number));

        return number;
    };

    // type a number from standar input
    int chooseNumber() {
        try {
            do {
                cin >> number;
            } while (isAlreadySelected(number));

            return number;
        }
        catch (const exception& e) {
            return -1;
        }
    };

    int play() {
        if (isMachine) {
            cout << "Machine type a number: ";
            return chooseRandomNumber();
        }
        else {
            cout << "You type a number: ";
            return chooseNumber();
        }
    }

    bool isAlreadySelected(int n) {
        for (int i = 0; i < oldNumbers.size(); i++) {
            if (oldNumbers[i] == n) return true;
        }
        return false;
    }
};


int main()
{
    std::cout << "##################################" << endl;
    std::cout << "¡¡ Welcome to Guess the Number !! " << endl;
    std::cout << "##################################" << endl;

    srand(time(nullptr)); // inicializar la semilla de los numeros aleatorios
    Menu menu;
    Player player;

    int mode = -1; 
    int chosenNumber = -1;
    int guessNumber = -1;
    int difficulty = -1;
    bool exit = false;

    do {
        // first time for choose difficulty and mode
        if (difficulty < 0) {
            menu.displayDifficultySelection();
            cin >> difficulty; // attempts to guess
            difficulty = menu.intToDifficulty(difficulty);

            cout << "Number of attempts set to: " << difficulty << endl;

            menu.displayPlayerSelection();
            cin >> mode; // who guess the number

            switch (mode) {
            case 1: // You guess, machine play
                player.isMachine = false;

                cout << "\nMachine type a number to guess" << endl;
                guessNumber = player.chooseRandomNumber();
                break;

            case 2: // machine guess, you play
                player.isMachine = true;;

                cout << "\nYou type a number to guess: ";
                guessNumber = player.chooseNumber();
                break;

            default:
                continue;
            }
        }

        chosenNumber = player.play();
        player.oldNumbers.push_back(chosenNumber);

        cout << "CHOICE NUMBER ##################" << guessNumber << "######################" << endl;

        // play again question
        if (guessNumber == chosenNumber) {
            cout << "\nNumber guessed! The number was " << chosenNumber << "\nDo you want to play again ?" << endl;
            cout << "Type: Yes or No" << endl;
            
            string response = "No";
            cin >> response;
            cout << response;

            if (response == "Yes") {
                exit = false;
                difficulty = -1;
            }
            else exit = true;
        }
        else {
            cout << "Fail! Remaining attempts: " << --difficulty << endl;

            if (difficulty == 0) {
                cout << "You lost!" << endl;
                exit = true;
            }
        }

    } while (!exit);
    

    cout << "Thanks for playing. See you next time!" << endl;

    return 0;
}