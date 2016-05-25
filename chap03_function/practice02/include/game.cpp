template<class PlayerType>
class GameInterface
{
public:
    virtual void        Restart(void)       = 0;
    virtual void        TurnToNext(void)    = 0;
    virtual PlayerType  CurrentTurn(void)   = 0;
    virtual bool        IsRunning(void)     = 0;
    virtual PlayerType  Winner(void)        = 0;
};
