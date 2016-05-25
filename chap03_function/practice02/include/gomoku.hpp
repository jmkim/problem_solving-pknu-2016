#include "game.hpp"
#include <cstddef>

namespace game
{

template<
    size_t  BoardSize = 19              /**< Size of the board */
>
class Gomoku
: public GameInterface
{
public:
    typedef unsigned int    PosType;    /**< Position type */
    typedef size_t          SizeType;

    enum PlayerType
    {
        NONE    = 0,
        BLACK   = 1,
        WHITE   = 2
    };

    enum DirectionType
    { N, NE, E, SE, S, SW, W, NW };

    enum StatusType         /**< Status type */
    {
        E_SUCCESS,          /**< Success */
        E_GAME_NOT_RUNNING, /**< The game is not running */
        E_POSITION_ERROR    /**< The provided position is not able to put */
    };

protected:
    PlayerType **   board_;         /**< Board */
    PlayerType      current_turn_;  /**< Current turn player */
    bool            is_running_;    /**< Is the game running?

                                         Currently, the game is stopped with these causes:
                                         *  The winner is set.
                                            In this case, the winner is the player `current_turn_'.
                                    */

    /** Allocate the memory for the game board */
    void
    MakeBoard(void)
    {
        if(board_ == nullptr)
        {
            board_ = new PlayerType*[BoardSize];

            for(PosType i = 0; i < BoardSize; ++i)
                board_[i] = new PlayerType[BoardSize];
        }
    }

    /** Deallocate the memory that is the game board */
    void
    FreeBoard(void)
    {
        for(PosType i = 0; i < BoardSize; ++i)
            delete[] board_[i];

        delete[] board_;
    }

    /** Initialise the board */
    void
    InitBoard(void)
    {
        for(PosType i = 0; i < BoardSize; ++i)
        {
            for(PosType j = 0; j < BoardSize; ++j)
                board_[i][j] = NONE; /** Initialise to player `NONE' */
        }
    }

    /** Test whether the stone is exist on the position

        \return     true if the stone exists; otherwise false
        \param[in]  x   Position X
        \param[in]  y   Position Y
    */
    inline
    bool
    IsStoneExist(const PosType & x, const PosType & y)
    const
    { return (board_[x][y] != NONE); }

    /** \breif  Check the game satisfying the winning condition

        Check the game satisfying the winning condition.
        If satisfying, then stop the game.
    */
    void
    CheckWin(const PosType & x, const PosType & y)
    {
        for(int dir = N; dir < S; ++dir)
        {
            PlayerType stone[11];

            for(int i = -5; i <= 5; ++i)
            {
                if(x + i < 0 ||
                   x - i < 0 ||
                   x + i > BoardSize ||
                   x - i > BoardSize ||
                   y + i < 0 ||
                   y - i < 0 ||
                   y + i > BoardSize||
                   y - i > BoardSize)
                    continue;

                switch(dir)
                {
                case N:  stone[i + 5] = board_[x + i][y    ]; break;
                case NE: stone[i + 5] = board_[x - i][y + i]; break;
                case E:  stone[i + 5] = board_[x    ][y + i]; break;
                case SE: stone[i + 5] = board_[x + i][y + i]; break;
                }
            }

            for(int i = 0; i < 11; i++)
            {
                int j;
                for(j = i + 6 ; i < j; i++)
                {
                    if(stone[i] != current_turn_)
                        break;
                }

                if(i == j - 1)
                    is_running_ = false; /** Stop the game; current player is the winner */
            }
        }
    }

public:
    /** Constructor */
    Gomoku(void)
    : board_        (nullptr)
    , current_turn_ (BLACK) /** First turn is player `BLACK' */
    , is_running_   (true)
    { 
        MakeBoard();
        InitBoard();
    }

    /** Destructor */
    ~Gomoku(void)
    { FreeBoard(); }

    /** Restart the game */
    inline
    virtual
    void
    Restart(void)
    {
        InitBoard();
        current_turn_   = BLACK; /** First turn is player `BLACK' */
        is_running_     = true;
    }

    /** Skip to next player */
    inline
    virtual
    void
    TurnToNext(void)
    { current_turn_ = (current_turn_ == BLACK) ? WHITE : BLACK; }

    /** Get the current turn

        /return     Current turn player
    */
    inline
    PlayerType
    CurrentTurn(void)
    const
    { return current_turn_; }

    /** Is the game running?

        \return     true if the game running; otherwise false
    */
    inline
    virtual
    bool
    IsRunning(void)
    const
    { return is_running_; }

    /** Put the stone on position

        \return     Depends on StatusType
        \param[in]  x   Position X
        \param[in]  y   Position Y
    */
    StatusType
    PutStone(const PosType & x, const PosType & y)
    {
        if(! IsRunning())
            return E_GAME_NOT_RUNNING;

        if(IsStoneExist(x, y))
            return E_POSITION_ERROR;

        board_[x][y] = CurrentTurn();
        CheckWin(x, y);

        if(! IsRunning())
            return E_GAME_NOT_RUNNING; /** Winner is set; current player is the winner */
        else
        {
            TurnToNext();
            return E_SUCCESS;
        }
    }

    /** Test whether the winner is set

        \return     Player, who is the winner
    */
    inline
    PlayerType
    Winner(void)
    const
    { return (is_running_) ? NONE : current_turn_; }

    /** Copy out the current board

        \param[in]  out_array   2-dimension array to copy the current board
    */
    void
    CopyBoard(PosType out_array[BoardSize][BoardSize])
    {
        for(PosType i = 0; i < BoardSize; ++i)
        {
            for(PosType j = 0; j < BoardSize; ++j)
                out_array[i][j] = board_[i][j];
        }
    }
};

} /** ns: game */
