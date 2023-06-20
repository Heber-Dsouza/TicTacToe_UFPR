#include<iostream>
#include<vector>
#include"TicTacToeGame.h"

using std::endl;
using std::cin;
using std::cout;
using std::vector;

int main()
{
	TicTacToeGame game;
	bool isRunning = true;
	char selection;

	int score_player1, score_player2;

	while (isRunning)
	{
		game.PlayGame();
		cout << "Deseja jogar novamente? [Y/n]:";
		cin >> selection;

		if (selection != ' ' && selection != 'Y' && selection != 'y')
			isRunning = false;
	}


	system("pause");
	return 0;
}