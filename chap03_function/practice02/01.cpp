#include "include/gomoku.hpp"
#include <iostream>

#define BOARD_SIZE  19

int main(void)
{
    typedef game::Gomoku<BOARD_SIZE>    Gomoku;
    typedef Gomoku::PosType             PosType;    /**< Position type */
    typedef Gomoku::SizeType            SizeType;

    Gomoku      game;
    PosType     screen[BOARD_SIZE][BOARD_SIZE];

    while(game.IsRunning())
    {
        {
            game.CopyBoard(screen);

            printf("    ");
            for(SizeType i = 0; i < BOARD_SIZE; ++i)
                printf("%2d ", i);
            printf("\n");

            for(SizeType i = 0; i < BOARD_SIZE; ++i)
            {
                printf("%2d ", i);
                for(SizeType j = 0; j < BOARD_SIZE; ++j)
                {
                    if(screen[i][j] == Gomoku::BLACK)
                        printf("  %c", 'o');
                    else if(screen[i][j] == Gomoku::WHITE)
                        printf("  %c", 'x');
                    else
                        printf("  %c", '.');
                }
                printf("\n");
            }
        }

        PosType x, y;
        std::cout   << "Player "
                    << ((game.CurrentTurn() == Gomoku::BLACK) ? "O" : "X")
                    << "'s turn."
                    << std::endl
                    << "Enter position (x y): ";
        std::cin >> x;
        std::cin >> y;

        Gomoku::StatusType status = (Gomoku::StatusType)game.PutStone(x, y);
        if(status == Gomoku::E_POSITION_ERROR)
            std::cout << "Error: E_POSITION_ERROR" << std::endl;
        if(status == Gomoku::E_GAME_NOT_RUNNING)
            std::cout << "Warning: E_GAME_NOT_RUNNING" << std::endl;
    }
    std::cout   << "Player "
                << ((game.Winner() == Gomoku::BLACK) ? "O" : "X")
                << " is the winner"
                << std::endl;

    return 0;
}
