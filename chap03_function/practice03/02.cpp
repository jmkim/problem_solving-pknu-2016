#include "include/othello.hpp"
#include <iostream>

#define BOARD_SIZE  19

int main(void)
{
    typedef game::Othello<BOARD_SIZE>   Othello;
    typedef Othello::PosType            PosType;    /**< Position type */
    typedef Othello::SizeType           SizeType;

    Othello     game;
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
                    if(screen[i][j] == Othello::BLACK)
                        printf("  %c", 'o');
                    else if(screen[i][j] == Othello::WHITE)
                        printf("  %c", 'x');
                    else
                        printf("  %c", '.');
                }
                printf("\n");
            }
        }

        PosType x, y;
        std::cout   << "Player "
                    << ((game.CurrentTurn() == Othello::BLACK) ? "O" : "X")
                    << "'s turn."
                    << std::endl
                    << "Enter position (x y): ";
        std::cin    >> x;
        std::cin    >> y;

        Othello::StatusType status = (Othello::StatusType)game.PutStone(x, y);
        if(status == Othello::E_POSITION_ERROR)
            std::cout << "Error: E_POSITION_ERROR" << std::endl;
        if(status == Othello::E_GAME_NOT_RUNNING)
            std::cout << "Warning: E_GAME_NOT_RUNNING" << std::endl;
    }
    std::cout   << "Player "
                << ((game.Winner() == Othello::BLACK) ? "O" : "X")
                << " is the winner"
                << std::endl;

    return 0;
}
