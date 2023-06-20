#pragma once
class TicTacToeGame
{
	public:
		void PlayGame();

	private:
		char board[3][3];

		int
			GetCoordination(char a);

		bool
			ValidatePosition(int x, int y),
			CheckForVictory();

		void
			ClearBoard(),
			RefreshProgram(),
			PrintBoard();
};

