namespace game
{

//template<class PlayerType>
class GameInterface
{
public:
    virtual void        Restart(void)       = 0;
    virtual void        TurnToNext(void)    = 0;
    //virtual PlayerType  CurrentTurn(void)   const = 0;
    virtual bool        IsRunning(void)     const = 0;
    //virtual PlayerType  Winner(void)        const = 0;
};

} /** ns: game */
