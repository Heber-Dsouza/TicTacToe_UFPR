#include<iostream>
#include<string>
#include <limits>
#include <cstdlib>
#include "TicTacToeGame.h"

using std::cin;
using std::cout;
using std::endl;

int TicTacToeGame::GetCoordination(char a)
{
	int x;
	bool isValid = false;

	while (isValid == false)
	{
		cout << "Digite a coordenada " << a <<": ";
		try
		{
			cin >> x;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw 402;
			}
			else if (x < 1 || x > 3)
				throw 400;

			isValid = true;
		} 
		catch(int ErrorNum)
		{
			switch (ErrorNum) {
				case 400:
					cout << "Digite um número entre 1-3 para continuar..." << endl;
					break;
				case 402:
					cout << "Digite uma coordenada válida" << endl;
					break;
				default:
					cout << "ErMac: not found error origin..." << endl;
					break;
			}
		}
	}

	
	return x - 1;
}

bool TicTacToeGame::ValidatePosition(int x, int y)
{
	return board[x][y] == ' ' ? true : false;
}

void TicTacToeGame::ClearBoard()
{
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void TicTacToeGame::RefreshProgram()
{
	system("cls");
}

void TicTacToeGame::PrintBoard()
{
	cout << endl << "     | 1 | 2 | 3 | " << endl << " ------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " | " << i+1 << " |";
		for (int j = 0; j < 3; j++)
		{
			cout << " " << board[i][j] << " |";
		}
		cout << endl << " ------------------" << endl;
	}
}

bool TicTacToeGame::CheckForVictory()
{
	for (int i = 0; i < 3; i++)
	{
		if
			(
				((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) ||
				((board[0][i] != ' ') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) ||
				((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) ||
				((board[2][0] != ' ') && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))

			) return true;
	}

	return false;
}

void TicTacToeGame::PlayGame()
{
	ClearBoard();
	RefreshProgram();

	char
		currentPlayer,
		player1 = 'X',
		player2 = '0';

	currentPlayer = player1;

	bool isRunning = true;

	int x, y;
	int turn = 0;

	while (isRunning)
	{
		cout << "Vez do jogador " << (currentPlayer == player1 ? "1" : "2") << endl;

		PrintBoard();
		bool markPhase = true;

		while (markPhase)
		{
			x = GetCoordination('X');
			y = GetCoordination('Y');

			if (ValidatePosition(x, y) != true)
			{
				cout << "Espaço já ocupado, selecione outra cordenada..." << endl;
			}
			else
			{
				board[x][y] = currentPlayer;
				turn++;

				if (CheckForVictory() || turn == 9)
				{
					isRunning = false;
					break;
				}

				markPhase = false;
				currentPlayer = currentPlayer == player1
					? player2
					: player1;

				RefreshProgram();
			}
		}
	}

	RefreshProgram();
	PrintBoard();

	if(turn == 9)
		cout << "Empate!" << endl;
	else
		cout << "Jogador " << (currentPlayer == player1 ? "1" : "2") << " Venceu!" << endl;
}