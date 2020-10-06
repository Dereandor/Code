#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color {
    WHITE,
    BLACK
  };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    virtual std::string symbol() const = 0;
  };

  class King : public Piece {
    // missing implementations
  public:
    King(Color color) : Piece(color) {}

    string type() const override {
      return color_string() + " king";
    }

    string symbol() const override {
      if (color == Color::WHITE) {
        return "♚";
      } else {
        return "♔";
      }
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int length_x = from_x - to_x;
      int length_y = from_y - to_y;

      if (abs(length_y) > 1 || abs(length_x) > 1) {
        return false;
      }

      return true;
    }
  };

  class Knight : public Piece {
    // missing implementations
  public:
    Knight(Color color) : Piece(color) {}

    string type() const override {
      return color_string() + " knight";
    }

    string symbol() const override {
      if (color == Color::WHITE) {
        return "♞";
      } else {
        return "♘";
      }
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int length_x = from_x - to_x;
      int length_y = from_y - to_y;

      if ((abs(length_x) == 2 && abs(length_y) == 1) || (abs(length_x) == 1 && abs(length_y) == 2)) {
        return true;
      } else {
        return false;
      }
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  function<void(const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares)> after_move;
  function<void(const Piece &piece, const string &from, const string &to)> on_move;
  function<void(Piece &piece, const string &square)> on_remove;
  function<void(Color color)> on_loss;
  function<void(const Piece &piece, const string &from, const string &to)> on_invalid;
  function<void(const string &square)> on_missing;

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece = squares.at(from_x).at(from_y);
    if (piece) {
      if (piece->valid_move(from_x, from_y, to_x, to_y)) {
        on_move(*piece, from, to);

        auto &piece_at_to_pos = squares.at(to_x).at(to_y);
        if (piece_at_to_pos) {
          if (piece->color != piece_at_to_pos->color) {
            on_remove(*piece_at_to_pos, to);
            if (auto king = dynamic_cast<King *>(piece_at_to_pos.get()))
              on_loss(king->color);
          } else {
            // piece in the from square has the same color as the piece in the to square
            on_invalid(*piece, from, to);
            return false;
          }
        }
        piece_at_to_pos = move(piece);
        after_move(squares);
        return true;
      } else {
        on_invalid(*piece, from, to);
        return false;
      }
    } else {
      on_missing(from);
      return false;
    }
  }
};
class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board) {
    board.after_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) {
      for (size_t i = 0; i < squares.size(); i++) {
        cout << "[" << (i + 1) << "]";
        for (size_t j = 0; j < squares.at(i).size(); j++) {
          if (!squares.at(j).at(i)) {
            cout << "[□]";
          } else {
            auto &piece = squares.at(j).at(i);
            cout << "[" << piece->symbol() << "]";
          }
        }
        cout << endl;
      }
      cout << "   "
           << "|A||B||C||D||E||F||G||H|" << endl;
    };
    board.on_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.symbol() << " moving from " << from << " to " << to << endl;
    };
    board.on_remove = [](const ChessBoard::Piece &piece, const string &square) {
      cout << piece.symbol() << " is being removed from " << square << endl;
    };
    board.on_loss = [](ChessBoard::Color color) {
      if (color == ChessBoard::Color::WHITE) {
        cout << "Black";
      } else {
        cout << "White";
      }
      cout << " win the game!" << endl;
    };
    board.on_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.symbol() << " from " << from << " to " << to << " is an invalid move";
    };
    board.on_missing = [](const string &square) {
      cout << "No piece on " << square << endl;
    };
  }
};

int main() {
  ChessBoard board;
  ChessBoardPrint print(board);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}