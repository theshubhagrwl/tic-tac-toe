#include <iostream>
using namespace std;

#define Player1 1
#define Player2 2

int whoseTurn;

string moves[3] = {"empty", "cross", "zero"};
string board[9] = {"empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty"};
//An array to avoid duplicate input
int playedPos[9] = {0};

void printBoard()
{
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			cout << endl;
			cout << endl;
		}
		if (board[i] == "empty")
		{
			cout << "\t"
				 << " | ";
		}
		else
		{
			cout << "\t" << board[i] << " ";
		}
	}
	cout << endl;
}

//Checking if any paper has won
bool check_for_victory(string board[])
{
	if ((board[0] != "empty") && (board[0] == board[1]) && (board[1] == board[2]))
		return true;
	if ((board[3] != "empty") && (board[3] == board[4]) && (board[4] == board[5]))
		return true;
	if ((board[6] != "empty") && (board[6] == board[7]) && (board[7] == board[8]))
		return true;
	if ((board[0] != "empty") && (board[0] == board[3]) && (board[3] == board[6]))
		return true;
	if ((board[1] != "empty") && (board[1] == board[4]) && (board[4] == board[7]))
		return true;
	if ((board[2] != "empty") && (board[2] == board[5]) && (board[5] == board[8]))
		return true;
	if ((board[0] != "empty") && (board[0] == board[4]) && (board[4] == board[8]))
		return true;
	if ((board[6] != "empty") && (board[6] == board[4]) && (board[4] == board[2]))
		return true;
	return false;
}

void makeMove(int whoseTurn)
{
	//Variable for counting how many times the game is played
	int gameCount = 0;
	int pos, move;
	while ((check_for_victory(board) == false) && (gameCount != 9))
	{
		cout << "Where you want to make move: ";
		cin >> pos;
		if (pos < 10 && pos > 0) //Checking if the user entered a valid move
		{
			pos--;
			//incrementing the position at the pos index to 1
			playedPos[pos]++;
			if (playedPos[pos] <= 1)
			{
				if (whoseTurn == Player1)
				{
					move = Player1;
					board[pos] = moves[move];
					printBoard();
					whoseTurn = Player2;
					gameCount++;
				}
				else if (whoseTurn == Player2)
				{
					move = Player2;
					board[pos] = moves[move];
					printBoard();
					whoseTurn = Player1;
					gameCount++;
				}
			}
			else
			{
				cout << "You have played this move" << endl;
			}
		}
		else
		{
			cout << "Enter a valid position" << endl;
		}
	}

	if ((check_for_victory(board) == false) && gameCount != 9)
	{
		cout << "Math is draw" << endl;
	}
	else
	{
		if (whoseTurn == Player1)
		{
			cout << "Player 2 is WINNER!" << endl;
		}
		else
		{
			cout << "Player 1 is WINNNER!" << endl;
		}
	}
}

int main()
{
	whoseTurn = Player1;
	printBoard();
	makeMove(Player1);
}
