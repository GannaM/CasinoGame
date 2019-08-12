#ifndef ChuckALuck_h
#define ChuckALuck_h


#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>



#include "Game.h"

class ChuckALuck: public Game {
    
public:
    
    ChuckALuck(): Game("Chuck-A-Luck", 1, 6, 5, 1) {}
    
    virtual void play();
    
    
private:
    const char *gameName = "Chuck-A-Luck";
    const int from = 1;
    const int to = 6;
    const int length = 5; // the length of sequence of numbers
    const int userNum = 1; // this is how many numbers a user will guess
    
    virtual void playOneGame();
    
};

#endif /* GameOne_h */
