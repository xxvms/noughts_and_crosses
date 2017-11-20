
#include <iostream>
#include <string>
#include <vector>
#include "tictactoe.hpp"

int main() {
  bool another_game = true;
  auto O = tictactoe::entry::nought;
  auto X = tictactoe::entry::cross;

  Player player1, player2;

  std::cout << "Type player 1 name: " << '\n';
  std::string name;
  std::cin >> name;

  std::cout << "Pick your X or 0: ";
  char mode;
  std::cin >> mode;

  std::cout << "Type player 2 name: " << '\n';
  std::cin >> name;

  while (another_game) {
    player1.setName(name);

    if (mode == 'X' || mode == 'x') {
      player1.setType(X);
      player2.setType(O);
      std::cout << "Player 1 is X" << '\n';
      std::cout << '\n';
    } else if (mode == 'O' || mode == 'o') {
      player1.setType(O);
      player2.setType(X);
      std::cout << "Player 1 is O" << '\n';
      std::cout << '\n';
    } else {
      std::cout << "please make valid choice!" << '\n';
      continue;
    }

    player2.setName(name);
    if (player2.getType() == O) {
      std::cout << "Player 2 is O" << '\n';

    } else {
      std::cout << "Player 2 is X" << '\n';
    }

    // initial board draw
    tictactoe::board board_;
    std::cout << board_ << '\n';

    // game terminates after 9 move
    int moves_counter = 0;

    while (moves_counter < 9) {
      tictactoe::entry e;
      if (tictactoe::check_draw(board_, e, moves_counter)) {
        std::cout << "this is a draaaw" << '\n';
        break;
      }
      int row, col;
      std::cout << "Please enter your move range 0-2" << '\n';
      std::cout << "Row: ";
      std::cin >> row;
      std::cout << "Column: ";
      std::cin >> col;

      if (tictactoe::is_valid_move(board_, row, col)) {
        if (moves_counter % 2 == 0) {
          board_(row, col) = player1.getType();
          std::cout << board_ << '\n';
          moves_counter++;

          if (tictactoe::check_winner(board_, player1.getType())) {
            std::cout << "Player 1 is victorious" << '\n';
            player1.setScore();

            break;
          }
        } else {
          board_(row, col) = player2.getType();
          std::cout << board_ << '\n';
          moves_counter++;

          if (tictactoe::check_winner(board_, player2.getType())) {
            std::cout << "Player 1 is victorious" << '\n';
            player2.setScore();
            break;
          }
        }
      }
    }
    std::cout << "Score is: " << '\n';

    std::cout << "Player 1: " << player1.getScore() << '\n';
    std::cout << "Player 2: " << player2.getScore() << '\n';

    std::cout << "Do you want to play again? (y/n)";
    char answer;
    std::cin >> answer;
    another_game = answer == 'y' || answer == 'Y';
  }
  return 0;
}
