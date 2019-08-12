#pragma once
#include "Game.h"


class Lotto : public Game {
    
public:
    Lotto() : Game("Mini Lotto", 1, 35, 5, 5){}
    
    virtual void play();
    
    
private:
    virtual void playOneGame();
    void calcWinning();
    
    const string Name = "Mini Lotto";
    const int from = 1;
    const int to = 35;
    const int number = 5;//The number of numbers user have to guess
    
    int match = 0; // the quantity of numbers the user guessed
    double bet = 0; // amount a player may win a lose for one game
};
