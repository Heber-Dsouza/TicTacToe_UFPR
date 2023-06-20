import os

class TicTacToeGame:
    def __init__(self):
        self.board = [[' ' for _ in range(3)] for _ in range(3)]

    def play_game(self):
        self.clear_board()
        self.refresh_program()

        player1 = 'X'
        player2 = '0'
        current_player = player1

        is_running = True
        turn = 0

        while is_running:
            print(f"Vez do jogador {1 if current_player == player1 else 2}")

            self.print_board()
            mark_phase = True

            while mark_phase:
                x = self.get_coordination('X')
                y = self.get_coordination('Y')

                if not self.validate_position(x, y):
                    print("Espaço já ocupado, selecione outra coordenada...")
                else:
                    self.board[x][y] = current_player
                    turn += 1

                    if self.check_for_victory() or turn == 9:
                        is_running = False
                        break

                    mark_phase = False
                    current_player = player2 if current_player == player1 else player1

                    self.refresh_program()

        self.refresh_program()
        self.print_board()

        if turn == 9:
            print("Empate!")
        else:
            print(f"Jogador {1 if current_player == player1 else 2} Venceu!")

    def get_coordination(self, a):
        is_valid = False
        while not is_valid:
            try:
                x = int(input(f"Digite a coordenada {a}: "))
                if x < 1 or x > 3:
                    raise ValueError
                is_valid = True
            except ValueError:
                print("Digite um número entre 1-3 para continuar...")

        return x - 1

    def validate_position(self, x, y):
        return self.board[x][y] == ' '

    def clear_board(self):
        self.board = [[' ' for _ in range(3)] for _ in range(3)]

    def refresh_program(self):
        os.system("cls" if os.name == "nt" else "clear")

    def print_board(self):
        print("\n     | 1 | 2 | 3 | ")
        print(" ------------------")
        for i in range(3):
            print(f" | {i + 1} |", end="")
            for j in range(3):
                print(f" {self.board[i][j]} |", end="")
            print("\n ------------------")

    def check_for_victory(self):
        for i in range(3):
            if (
                (self.board[i][0] != ' ' and self.board[i][0] == self.board[i][1] == self.board[i][2]) or
                (self.board[0][i] != ' ' and self.board[0][i] == self.board[1][i] == self.board[2][i]) or
                (self.board[0][0] != ' ' and self.board[0][0] == self.board[1][1] == self.board[2][2]) or
                (self.board[2][0] != ' ' and self.board[2][0] == self.board[1][1] == self.board[0][2])
            ):
                return True
        return False

game = TicTacToeGame()
game.play_game()