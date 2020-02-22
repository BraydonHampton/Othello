//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Name: Braydon Hampton
// File: p01.cpp
//
// MAIN MENU and user interface
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>

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
            case '?':
                std::cout << '\n' << "*** ?: TO BE IMPLEMENTED ***" << '\n';
                std::cout << '\n';
            continue;

            case 'p':
            case 'P':
                std::cout << '\n' << "*** P/p: TO BE IMPLEMENTED ***" << '\n';
                std::cout << '\n';
                continue;

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
                std::cout << '\n' << "Thanks for playing Super Othello Versino 0.1";
                break;
        }        
    }

    
    return 0;
}
