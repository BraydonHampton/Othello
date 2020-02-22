//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Name: Braydon Hampton
// File: p04.cpp
//
// Working on the play() function.
// - Quit midgame ability
// - Place piece
// Cleanup code
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>

// CONSTANT PROPERTIES
const int BSIZE = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = '0';


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
    while (1)
    {
        char input[100];
        char piece = ' ';
        std::cout << (!turn ? "BLACK's turn: " : "WHITE's turn: "); // Say who's turn
        piece = (!turn ? '@' : '0'); // define which piece prints
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

        int col = input[0] - 'A';
        int row = input[1] - '1';

        if (input[0] < 'A' || input[0] > 'H'
            || input[1] < '1' || input[1] > '8'
            || input[2] != '\0' || board[row][col] != ' ')
        {
            std::cout << "Invalid position" << '\n';
            continue;
        }

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
                board[i][j] = '0';
            }
            else if (i == 3 && j == 4 || i == 4 && j == 3)
            {
                board[i][j] = '@';
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

    board[0][0] = '@';
    draw(board);
}
