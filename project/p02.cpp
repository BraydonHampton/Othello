//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Name: Braydon Hampton
// File: p02.cpp
//
// FUNCTIONS FOR OTHELLO
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>

// FUNCTION PROTOTYPES
void help();
void play();

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
    bool black = true;    
    while (1)
    {
        std::cout << '\n' << "*** Othello board: TO BE IMPLEMENTED ***" << '\n';
        
        char turn[100];

        if (black) //blacks turn
        {
            std::cout << '\n' << "BLACK's turn: ";
            black = false;
        }

        else //white turn
        {
            std::cout << '\n' << "WHITE's turn: ";
            black = true;
        }

        std::cin >> turn;
        std::cout << '\n';
    }
}
