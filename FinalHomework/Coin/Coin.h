#include "Game.h"

class Coin : public Game {
    
public:
    Coin() : Game("Flip-A-Coin", 1, 2, 1, 1){}
    
    virtual void play();
    
    
private:
    virtual void playOneGame();
    
    double playAGame();
    
    const string name = "Flip-A-Coin";
    const int from = 1;
    const int to = 2;
    const int number = 1; //The number of numbers user have to guess
    
    };
