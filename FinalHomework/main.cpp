#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

//#include "Game.h"
#include "ChuckALuck.h"
#include "lotto.h"
#include "Pick4.h"
#include "Coin.h"

using namespace std;

int main() {
    
    ChuckALuck game1;
    
    Pick4 game2;
    
    Lotto game3;
    
    Coin game4;
    
    game1.play();
    game2.play();
    game3.play();
    game4.play();
    
    return 0;
}
