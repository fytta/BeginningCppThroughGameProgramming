#pragma once
#include <string>
#include <vector>
using namespace std;

/// <summary>
/// Displays the game instructions.
/// </summary>
void instructions();

/// <summary>
/// Asks a yes or no question. Receives a question. Returns either a 'y' or an 'n'.
/// </summary>
char askYesNo(string question);

/// <summary>
/// Asks for a number within a range. Receives a question, a low number, and a high number.Returns a number in the range from low to high.
/// </summary>
int askNumber(string question, int high, int low = 0);

/// <summary>
/// Determines the human’s piece. Returns either an ’X’ or an ’O’.
/// </summary>
char humanPiece();

/// <summary>
/// Calculates the opposing piece given a piece. Receives either an ’X’ or an ’O’.Returns either an ’X’ or an ’O’.
/// </summary>
char opponent(char piece);

/// <summary>
/// Displays the board on the screen. Receives a board.
/// </summary>
void displayBoard(const vector<char>& board);

/// <summary>
/// Determines the game winner. Receives a board. Returns an ’X’, ’O’, ’T’(to indicate a tie), or ’N’(to indicate that no one has won yet).
/// </summary>
char winner(const vector<char>& board);

/// <summary>
/// Determines whether a move is legal. Receives a board and a move.Returns either true or false.
/// </summary>
bool isLegal(const vector<char>& board, int move);

/// <summary>
/// Gets the human’s move. Receives a board and the human’s piece.Returns the human’s move.
/// </summary>
int humanMove(const vector<char>& board, char human);

/// <summary>
/// Calculates the computer's move. Receives a board and the computer's piece.Returns the computer's move.
/// 1. If the computer can win on this move, make that move.
/// 2. Otherwise, if the human can win on his next move, block him.
/// 3. Otherwise, take the best remaining open square. The best square is the center.The next best squares are the corners, and then the rest of the squares.
/// </summary>
int computerMove(const vector<char>& board, char computer);

/// <summary>
/// Congratulates the winner or declares a tie. Receives the winning side, the computer’s piece, and the human’s piece.
/// </summary>
void announceWinner(char winner, char computer, char human);