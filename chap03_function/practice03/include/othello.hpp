#include "../../practice02/include/game.hpp"
#include <cstddef>

namespace game
{

template<
    size_t  BoardSize = 8               /**< Size of the board */
>
class Othello
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

    enum StatusType             /**< Status type */
    {
        E_SUCCESS,              /**< Success */
        E_GAME_NOT_RUNNING,     /**< The game is not running */
        E_POSITION_ERROR,       /**< The provided position is not able to put */
        E_SKIPPING_CANNOT_PUT   /**< The player cannot put the stone */
    };

protected:
    PlayerType **   board_;         /**< Board */
    PlayerType      current_turn_;  /**< Current turn player */
    PlayerType      winner_;        /**< Player who is the winner; valid only when the game is stopped */
    SizeType        count_;         /**< Count of stones */
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
        board_[BoardSize/2    ][BoardSize/2    ] = WHITE;
        board_[BoardSize/2    ][BoardSize/2 + 1] = BLACK;
        board_[BoardSize/2 + 1][BoardSize/2    ] = BLACK;
        board_[BoardSize/2 + 1][BoardSize/2 + 1] = WHITE;
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

    /** \brief  Check the game satisfying the winning condition

        Stop the game and determine who is the winner.
    */
    void
    SetWinner()
    {
        SizeType    black = 0,
                    white = 0;

        for(int i = 0; i < BoardSize; ++i)
        {
            for(int j = 0; j < BoardSize; ++j)
            {
                switch(board_[i][j])
                {
                case BLACK: ++black; break;
                case WHITE: ++white; break;
                }
            }
        }

        if(black > white)
            winner_ = BLACK;
        else if(black < white)
            winner_ = WHITE;
        else
            winner_ = NONE;

        is_running_ = false;
    }

    /**
        \return     
    */
    bool
    IsAbleToPut(void)
    {
        if(count_ >= BoardSize * BoardSize)
            return false;

        SizeType capturable_stones = 0;

        for(int i = 0; i < BoardSize; ++i)
        {
            for(int j = 0; j < BoardSize; ++j)
            {
                SizeType c_stones = CaptureStone(i, j, true);
                if(c_stones > capturable_stones)
                    capturable_stones = c_stones;
            }
        }

        return (capturable_stones > 0);
    }

    /**
        Search the best position
      
        \return     Count of capturable stones
        \param[out] out_x   To store the position X
        \param[out] out_y   To store the position Y
    */
    SizeType
    BestPosition(PosType & out_x, PosType & out_y)
    {
        SizeType capturable_stones = 0;

        for(int i = 0; i < BoardSize; ++i)
        {
            for(int j = 0; j < BoardSize; ++j)
            {
                SizeType c_stones = CaptureStone(i, j, true);
                if(c_stones > capturable_stones)
                {
                    capturable_stones = c_stones;
                    out_x = i;
                    out_y = j;
                }
            }
        }

        return capturable_stones;
    }

    /** Get a count of capturable stones

        \return     Count of capturable stones
        \param[in]  x   Position X
        \param[in]  y   Position Y
        \param[in]  dir Direction (Optional)
    */
    SizeType
    CaptureStone(const PosType & x, const PosType & y, const bool & spider = false)
    {
        if(IsStoneExist(x, y)) /** Cannot place stone here */
            return 0;

        SizeType capturable_stones = 0; /**< Count of capturable stones */

        for(int dir = N; dir < NW; ++dir)
            capturable_stones += CaptureStone(x, y, DirectionType(dir), spider);

        return capturable_stones;
    }
    SizeType
    CaptureStone(const PosType & x, const PosType & y, const DirectionType & dir, const bool & spider = false)
    {
        SizeType    distance = 0;
        PlayerType  player_distance; /**< player that is the first change of specific direction */

        do
        { ++distance; }
        while((player_distance = PlayerInDistance(x, y, dir, distance)) != 0 && player_distance != CurrentTurn());

        if(player_distance == CurrentTurn())
        {
            if(! spider)
            {
                for(int i = 0; i < distance; ++i)
                    CapturePlayerInDistance(x, y, dir, i);
            }

            return distance - 1; /** distance == count of (capturable stones + current player's stone) */
        }
        else
            return 0;
    }

    /** Get Player of the stone that is as far as distance from specific position

        Coordination of the board
                         x  y   board_[x][y]
        +---- y     a -> 0, 0   board_[0][0]
        | a b       b -> 0, 1   board_[0][1]
        | c d       c -> 1, 0   board_[1][0]
        x           d -> 1, 1   board_[1][1]

        \return     Player in position
        \param[in]  x       Position X
        \param[in]  y       Position Y
        \param[in]  dir     Direction
        \param[in]  dist    Distance
    */
    PlayerType
    PlayerInDistance(const PosType & x, const PosType & y, const DirectionType & dir, const SizeType & dist)
    {
        switch(dir)
        {
        case N : return ( x - dist >= 0                                ) ? board_[x - dist][y       ] : NONE;
        case NE: return ( x - dist >= 0        && y + dist < BoardSize ) ? board_[x - dist][y + dist] : NONE;
        case E : return (                         y + dist < BoardSize ) ? board_[x       ][y + dist] : NONE;
        case SE: return ( x + dist < BoardSize && y + dist < BoardSize ) ? board_[x + dist][y + dist] : NONE;
        case S : return ( x + dist < BoardSize                         ) ? board_[x + dist][y       ] : NONE;
        case SW: return ( x + dist < BoardSize && y - dist >= 0        ) ? board_[x + dist][y - dist] : NONE;
        case W : return (                         y - dist >= 0        ) ? board_[x       ][y - dist] : NONE;
        case NW: return ( x - dist >= 0        && y - dist >= 0        ) ? board_[x - dist][y - dist] : NONE;
        }
    }

    /** Capture the stone that is as far as distance from specific position

        \param[in]  x       Position X
        \param[in]  y       Position Y
        \param[in]  dir     Direction
        \param[in]  dist    Distance
    */
    void
    CapturePlayerInDistance(const PosType & x, const PosType & y, const DirectionType & dir, const SizeType & dist)
    {
        switch(dir)
        {
        case N : if( x - dist >= 0                                ) board_[x - dist][y       ] = CurrentTurn(); break;
        case NE: if( x - dist >= 0        && y + dist < BoardSize ) board_[x - dist][y + dist] = CurrentTurn(); break;
        case E : if(                         y + dist < BoardSize ) board_[x       ][y + dist] = CurrentTurn(); break;
        case SE: if( x + dist < BoardSize && y + dist < BoardSize ) board_[x + dist][y + dist] = CurrentTurn(); break;
        case S : if( x + dist < BoardSize                         ) board_[x + dist][y       ] = CurrentTurn(); break;
        case SW: if( x + dist < BoardSize && y - dist >= 0        ) board_[x + dist][y - dist] = CurrentTurn(); break;
        case W : if(                         y - dist >= 0        ) board_[x       ][y - dist] = CurrentTurn(); break;
        case NW: if( x - dist >= 0        && y - dist >= 0        ) board_[x - dist][y - dist] = CurrentTurn(); break;
        }
    }

public:
    /** Constructor */
    Othello(void)
    : board_        (nullptr)
    , current_turn_ (BLACK) /** First turn is player `BLACK' */
    , is_running_   (true)
    , count_        (0)
    , winner_       (NONE)
    { 
        MakeBoard();
        InitBoard();
    }

    /** Destructor */
    ~Othello(void)
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
        count_          = 0;
        winner_         = NONE;
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
    PutStone(const PosType & x, const PosType & y, const bool & auto_put = false)
    {
        if(! IsRunning())
            return E_GAME_NOT_RUNNING;

        if(IsStoneExist(x, y))
            return E_POSITION_ERROR;

        board_[x][y] = CurrentTurn();
        ++count_;
        CaptureStone(x, y);

        TurnToNext();

        if(! IsAbleToPut())
        {
            TurnToNext();

            if(! IsAbleToPut())
            {
                SetWinner();
                return E_GAME_NOT_RUNNING; /** Winner is set; winner_ is the winner */
            }
            else
                return E_SKIPPING_CANNOT_PUT;
        }
        else
            return E_SUCCESS;
    }

    /** Test whether the winner is set

        \return     Player, who is the winner
    */
    inline
    PlayerType
    Winner(void)
    const
    { return winner_; }

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
