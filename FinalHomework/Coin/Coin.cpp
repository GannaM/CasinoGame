#include "Coin.h"
#include <cmath>

void Coin::playOneGame()
{
    int number;
    double betAmount;
    int hot;//Head or tail
    
    cout << "How much would you like to bet? ";
    cin >> betAmount;
    
    cout << "Which side do you want to bet on\n"
    << "1-Heads\n2-Tails" << endl;
    cin >> hot;
    
    while (hot != 1 && hot != 2) {
        cout << "Invalid input. Type 1 for Heads, 2 for Tails" << endl;;
        cin >> hot;
    }
    
    number = getRandomNumber();
    
    switch (number) {
        case 1:
            cout << "The coin has flipped Heads" << endl;
            break;
            
        case 2:
            cout << "The coin has flipped Tails" << endl;
            break;
    }
    
    if (number == hot) {
        cout << "You have won $" << betAmount << endl << endl;
        setWinningAmount(betAmount);
    }
    else {
        cout << "You have lost $" << betAmount << endl << endl;
        setWinningAmount(-betAmount);
    }
    
    
}

void Coin::play()
{
    Game::play();
    
    
    getUserInfo();
    
    for (int i = 0; i < getNumberOfGames(); i++) {
        cout << "Flip-A-Coin Game " << i + 1 << endl;
        playOneGame();
    }
    
    calcBonus();
    print();
}

