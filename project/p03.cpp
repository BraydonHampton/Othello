#include <iostream>

void help();
void play();
void setup();
void load();

void init(char [8][8]);
void draw(char [8][8]);
void test_draw();



int main()
{
    test_draw();
    
}

void init(char b[8][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (i == 3 && j == 3 || i == 4 && j == 4)
            {
                b[i][j] = '0';
            }
            else if (i == 3 && j == 4 || i == 4 && j == 3)
            {
                b[i][j] = '@';
            }
            else
            {
            b[i][j] = ' ';
            }
        }
    }
    
}


void draw(char b[8][8])
{
    std::cout << '\n'
              << "  ABCDEFGH" << '\n'
              << " +--------+" << '\n';
    for (int i = 0; i < 8; ++i)
    {
        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; ++j)
        {
            std::cout << b[i][j];
        }
        std::cout << "|" << i + 1 << '\n';
    }
    std::cout << " +--------+" << '\n'
              << "  ABCDEFGH" << '\n'
              << '\n';
}


void test_draw()
{
    char b[8][8];
    std::cout << "Testing draw() function ...\n";
    init(b);
    draw(b);

    b[0][0] = '@';
    draw(b);
}
