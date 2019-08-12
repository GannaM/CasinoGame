#ifndef Pick4_h
#define Pick4_h

#include <stdio.h>

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"

class Pick4 : public Game {
    
public:
    
    Pick4() : Game("Pick4", 1, 6, 4, 1) {}
    
    virtual void play();
    
    
private:
    const string gameName = "Pick4";
    const int from = 1;
    const int to = 6;
    const int length = 4; // the length of sequence of numbers
    const int userNum = 1; // this is how many numbers a user will guess
    
    void playOneGame();
};


#endif /* Pick4_hpp */
