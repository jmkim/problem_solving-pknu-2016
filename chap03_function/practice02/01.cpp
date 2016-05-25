#include "include/gomoku.hpp"
#include <iostream>

#define BOARD_SIZE  19

int main(void)
{
    typedef unsigned int    PosType;    /**< Position type */
    typedef size_t          SizeType;
    enum PlayerType
    {
        NONE    = 0,
        BLACK   = 1,
        WHITE   = 2
    };
    enum StatusType         /**< Status type */
    {
        E_SUCCESS,          /**< Success */
        E_GAME_NOT_RUNNING, /**< The game is not running */
        E_POSITION_ERROR    /**< The provided position is not able to put */
    };

    game::Gomoku<BOARD_SIZE>    game;
    PosType                     screen[BOARD_SIZE][BOARD_SIZE];

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
                    if(screen[i][j] == BLACK)
                        printf("  %c", 'o');
                    else if(screen[i][j] == WHITE)
                        printf("  %c", 'x');
                    else
                        printf("  %c", '.');
                }
                printf("\n");
            }
        }

        PosType x, y;
        std::cout   << "Player "
                    << ((game.CurrentTurn() == BLACK) ? "O" : "X")
                    << "'s turn."
                    << std::endl
                    << "Enter position (x y): ";
        std::cin >> x;
        std::cin >> y;

        StatusType status = (StatusType)game.PutStone(x, y);
        if(status == E_POSITION_ERROR)
            std::cout << "Error: E_POSITION_ERROR" << std::endl;
        if(status == E_GAME_NOT_RUNNING)
            std::cout << "Warning: E_GAME_NOT_RUNNING" << std::endl;
    }
    std::cout   << "Player "
                << ((game.Winner() == BLACK) ? "O" : "X")
                << " is the winner"
                << std::endl;

    return 0;
}
