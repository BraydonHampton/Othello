//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Name: Braydon Hampton
// File: p05.cpp
//
// Create logic for taking enemy pieces and win condition
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>

// CONSTANT PROPERTIES
const int BSIZE = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BL = '@';
const char WH = '0';


// TYPEDEFS
typedef char Board[BSIZE][BSIZE];


// FUNCTION PROTOTYPES
void help();
void play();
void setup();
void load();

void init(Board board);
void draw(Board board);
void test_draw();
bool gameover(Board board, int no_move_count);


int get_row(char input[]);
int get_col(char input[]);

bool valid_move(char piece, char opPiece, Board board);
bool invalid_move(char piece, char opPiece, Board board, int row, int col);
void capture(Board board, int row, int col, char piece, char opPiece);

bool North(char piece, char opPiece,  int row, int col, Board board);
bool South(char piece, char opPiece,  int row, int col, Board board);
bool East(char piece, char opPiece,  int row, int col, Board board);
bool West(char piece, char opPiece,  int row, int col, Board board);
bool NEast(char piece, char opPiece,  int row, int col, Board board);
bool NWest(char piece, char opPiece,  int row, int col, Board board);
bool SEast(char piece, char opPiece,  int row, int col, Board board);
bool SWest(char piece, char opPiece,  int row, int col, Board board);

//bool valid(int row, int col);


int main()
{

    char choice;
    while (choice != 'q')
    {
        std::cout << "Welcome to Super Othello Version 0.1" << '\n'
                  << "by Braydon Hampton" << '\n' << '\n'
                  << "[?]   Help" << '\n'
                  << "[P/p] Play a new game" << '\n'
                  << "[L/l] Load a previous game" << '\n'
                  << "[S/s] Setup the board" << '\n'
                  << "[Q/q] Quit" << '\n'
                  << "Enter option: ";
                
        std::cin >> choice;

        switch (choice)
        {
            case '?': help(); continue;

            case 'p':
            case 'P': play(); continue;

            case 'l':
            case 'L':
                std::cout << '\n' << "*** L/l: TO BE IMPLEMENTED ***" << '\n';
                std::cout << '\n';
                continue;

            case 's':
            case 'S':
                std::cout << '\n' << "*** S/s: TO BE IMPLEMENTED ***" << '\n';
                std::cout << '\n';
                continue;

            case 'q':
            case 'Q':
                std::cout << '\n' << "Thanks for playing Super Othello Version 0.1";
                break;
        }
        std::cout << std::endl;
    }
    return 0;
}


// FUNCTION DEFINITIONS
void help()
{
    std::cout << '\n' << "The official rules can be found at" << '\n'
              << "http://en.wikipedia.org/wiki/Reversi" << '\n'
              << '\n'
              << "The Othello board is set up in the following manner" << '\n'
              << '\n'
              << "  ABCDEFGH" << '\n'
              << " +--------+" << '\n'
              << "1|        |1" << '\n'
              << "2|        |2" << '\n'
              << "3|        |3" << '\n'
              << "4|   0@   |4" << '\n'
              << "5|   @0   |5" << '\n'
              << "6|        |6" << '\n'
              << "7|        |7" << '\n'
              << "8|        |8" << '\n'
              << " +--------+" << '\n'
              << "  ABCDEFGH" << '\n'
              << '\n'
              << "BLACK plays @ and WHITE plays 0. Players take turn in entering" << '\n'
              << "moves. The first player to enter a move is BLACK. To place a @" << '\n'
              << "at row 6 and column E, BLACK enters 6E. The result of the move" << '\n'
              << "is" << '\n'
              << '\n' 
              << "  ABCDEFGH" << '\n'
              << " +--------+" << '\n'
              << "1|        |1" << '\n'
              << "2|        |2" << '\n'
              << "3|        |3" << '\n'
              << "4|   0@   |4" << '\n'
              << "5|   @@   |5" << '\n'
              << "6|    @   |6" << '\n'
              << "7|        |7" << '\n'
              << "8|        |8" << '\n'
              << " +--------+" << '\n'
              << "  ABCDEFGH" << '\n'
              << '\n'
              << "Note that the WHITE  piece at E5 is now a BLACK piece." << '\n'
              << '\n';
}


void play()
{
    bool quit = false;
    Board board;
    init(board);
    draw(board);
    bool turn = BLACK;
    int no_move_count = 0;
    
    while (1)
    {
        char input[100];
        char piece, opPiece;
        std::cout << (!turn ? "BLACK's turn:  \n" : "WHITE's turn: \n"); // Say who's turn
        piece = (!turn ? BL : WH); // define which piece prints
        opPiece = (!turn ? WH : BL); // define opp piece

        if (!valid_move(piece, opPiece, board)) // check if player has valid moves
        {
            turn = (!turn ? WHITE : BLACK);
            no_move_count++;
            if (gameover(board, no_move_count)) break;
            continue;
        }

        no_move_count = 0;
        std::cin >> input;
        
        if (input[0] == 'q' || input[0] == 'Q') // quit
        {
            if (input[1] == '\0')
            {
                quit = true;
                std::cout << std::endl;
            }
        }
        if (quit) break;

        int row = get_row(input);
        int col = get_col(input);

        if (input[0] < 'A' || input[0] > 'H'
            || input[1] < '1' || input[1] > '8'
            || input[2] != '\0' || board[row][col] != ' '
            || invalid_move(piece, opPiece, board, row, col))
        {
            std::cout << "Invalid position" << '\n';
            continue;
        }

        capture(board, row, col, piece, opPiece);
        std::cout << "ROW: " << row << "COL: " << col << '\n';
        board[row][col] = piece;
        turn = (!turn ? WHITE : BLACK);
        std::cout << '\n';

        draw(board);
    }
}


void init(Board board)
{
    for (int i = 0; i < BSIZE; ++i)
    {
        for (int j = 0; j < BSIZE; ++j)
        {
            if (i == 3 && j == 3 || i == 4 && j == 4)
            {
                board[i][j] = WH;
            }
            else if (i == 3 && j == 4 || i == 4 && j == 3)
            {
                board[i][j] = BL;
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }    
}


void draw(Board board)
{
    std::cout << '\n'
              << "  ABCDEFGH" << '\n'
              << " +--------+" << '\n';
    for (int i = 0; i < BSIZE; ++i)
    {
        std::cout << i + 1 << "|";
        for (int j = 0; j < BSIZE; ++j)
        {
            std::cout << board[i][j];
        }
        std::cout << "|" << i + 1 << '\n';
    }
    std::cout << " +--------+" << '\n'
              << "  ABCDEFGH" << '\n'
              << '\n';
}


void test_draw()
{
    Board board;
    std::cout << "Testing draw() function ...\n";
    init(board);
    draw(board);

    board[0][0] = BL;
    draw(board);
}


int get_row(char input[])
{
    int row = input[1] - '1';
     
        return row;
}


int get_col(char input[])
{
    int col = input[0] - 'A';

        return col;
}

bool gameover(Board board, int no_move_count)
{
    bool gameover = false;
    int BLcount = 0, WHcount = 0, spCount = 0;

    if (no_move_count == 2)
    {
        draw(board);

        for (int row = 0; row < BSIZE; ++row)
        {
            for (int col = 0; col < BSIZE; ++col)
            {
                if (board[row][col] == BL) ++BLcount;
    

                else if (board[row][col] == WH) ++WHcount;

                else ++spCount;
            }
        }
        std::cout << '\n' << "GAMEOVER" << '\n'
                  << "FINAL SCORE: " << '\n'
                  << "BLACK: " << BLcount << '\n'
                  << "WHITE: " << WHcount << '\n'
                  << "SPACES LEFT: " << spCount << '\n';
        if (BLcount > WHcount)
        {
            std::cout << '\n' << "BLACK WINS!!!!!" << '\n';
        }
        else if (WHcount > BLcount)
        {
            std::cout << '\n' << "WHITE WINS!!!!!" << '\n';
        }
        else
        {
            std::cout << '\n' << ".....draw......" << '\n';
        }
        return true;
    }
    return false;
}


bool valid_move(char piece, char opPiece, Board board) // needs proto
{
    bool valid = false;
    for (int row = 0; row < BSIZE; ++row)
    {
        for (int col = 0; col < BSIZE; ++col)
        {
            if (North(piece, opPiece, row, col, board)
                || South(piece, opPiece, row, col, board)
                || East(piece, opPiece, row, col, board)
                || West(piece, opPiece, row, col, board)
                || NEast(piece, opPiece, row, col, board)
                || NWest(piece, opPiece, row, col, board)
                || SEast(piece, opPiece, row, col, board)
                || SWest(piece, opPiece, row, col, board))
            {
                //std::cout << "Valid move: " << col << ' ' << row << '\n';
                valid = true;
            }
        }
    }
    return valid;
}

bool invalid_move(char piece, char opPiece, Board board, int row, int col)
{
    if (!North(piece, opPiece, row, col, board)
        && !South(piece, opPiece, row, col, board)
        && !East(piece, opPiece, row, col, board)
        && !West(piece, opPiece, row, col, board)
        && !NEast(piece, opPiece, row, col, board)
        && !NWest(piece, opPiece, row, col, board)
        && !SEast(piece, opPiece, row, col, board)
        && !SWest(piece, opPiece, row, col, board))
    {
        return true;
    }
    return false;
}

void capture(Board board, int row, int col, char piece, char opPiece)
{
    if (North(piece, opPiece, row, col, board))
    {
        for (int i = row - 1; i >= 0; --i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
        }
    }

    if (South(piece, opPiece, row, col, board))
    {
        for (int i = row + 1; i < BSIZE; ++i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
        }
    }

    if (West(piece, opPiece, row, col, board))
    {
        for (int i = col - 1; i >= 0; --i)
        {
            if (board[row][i] == piece)
            {
                break;
            }

            board[row][i] = piece;
        }
    }

    if (East(piece, opPiece, row, col, board))
    {
        for (int i = col + 1; i >= 0; ++i)
        {
            if (board[row][i] == piece)
            {
                break;
            }

            board[row][i] = piece;
        }
    }

    if (NEast(piece, opPiece, row, col, board))
    {
        col++;
        for (int i = row - 1; i >= 0; --i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
            col++;
        }
    }

    if (NWest(piece, opPiece, row, col, board))
    {
        col--;
        for (int i = row - 1; i >= 0; --i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
            col--;
        }
    }

    if (SEast(piece, opPiece, row, col, board))
    {
        col++;
        for (int i = row + 1; i < BSIZE; ++i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
            col++;
        }
    }

    if (SWest(piece, opPiece, row, col, board))
    {
        col--;
        for (int i = row + 1; i < BSIZE; ++i)
        {
            if (board[i][col] == piece)
            {
                break;
            }

            board[i][col] = piece;
            col--;
        }
    }
}

bool North(char piece, char opPiece, int row, int col, Board board)
{
    bool opp_found = false;
    //std::cout << row << ' ' << col;
    //draw(board);
    for (int i = row - 1; i >= 0; --i)
    {
        //std::cout << "Board: " << board[i][col] << '\n';
        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool South(char piece, char opPiece,  int row, int col, Board board)
{
    bool opp_found = false;
    //std::cout << row << ' ' << col;
    //draw(board);
    for (int i = row + 1; i < BSIZE; ++i)
    {
        //std::cout << "Board: " << board[i][col] << '\n';
        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
    }
    return false;    
}
bool East(char piece, char opPiece,  int row, int col, Board board)
{
        bool opp_found = false;
    //std::cout << row << ' ' << col;
    //draw(board);
    for (int i = col + 1; i < BSIZE; ++i)
    {
        //std::cout << "Board: " << board[i][col] << '\n';
        if (board[row][i] == ' ')
        {
            return false;
        }
        else if (board[row][i] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
    }
    return false;    
}
bool West(char piece, char opPiece,  int row, int col, Board board)
{
    bool opp_found = false;
    //std::cout << row << ' ' << col;
    //draw(board);
    for (int i = col - 1; i >= 0; --i)
    {
        //std::cout << "Board: " << board[i][col] << '\n';
        if (board[row][i] == ' ')
        {
            return false;
        }
        else if (board[row][i] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
    }
    return false;    
}
bool NEast(char piece, char opPiece,  int row, int col, Board board)
{
    bool opp_found = false;

    ++col;
    for (int i = row - 1; i >= 0; --i)
    {
        if (col >= BSIZE)
        {
            return false;
        }

        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
        ++col;
    }
    return false;    
}
bool NWest(char piece, char opPiece,  int row, int col, Board board)
{
    bool opp_found = false;

    --col;
    for (int i = row - 1; i >= 0; --i)
    {
        if (col < 0)
        {
            return false;
        }

        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
        --col;
    }
    return false;     
}
bool SEast(char piece, char opPiece,  int row, int col, Board board)
{
     bool opp_found = false;

    ++col;
    for (int i = row + 1; i < BSIZE; ++i)
    {
        if (col >= BSIZE)
        {
            return false;
        }

        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
        ++col;
    }
    return false;    
}
bool SWest(char piece, char opPiece,  int row, int col, Board board)
{
 
     bool opp_found = false;

    --col;
    for (int i = row + 1; i < BSIZE; ++i)
    {
        if (col < 0)
        {
            return false;
        }

        if (board[i][col] == ' ')
        {
            return false;
        }
        else if (board[i][col] == opPiece)
        {
            opp_found = true;
        }
        else
        {
            if (opp_found)
            {
                return true;
            }
            return false;
        }
        --col;
    }
    return false;    
}

