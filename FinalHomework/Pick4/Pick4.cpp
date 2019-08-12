#include "Pick4.h"

void Pick4::play() {
    
    Game::play();
    
    getUserInfo();
    int games = getNumberOfGames();
    int gamecnt = 0;
    
    if (games > 0) {
        do {
            games--;
            gamecnt++;
            
            cout << gameName << " Game " << gamecnt << endl;
            
            playOneGame();
            
        } while (games != 0);
    }
    
    Game::calcBonus();
    Game::print();
    
}
void Pick4::playOneGame() {
    
    int inputs[length]; //The users 4 numbers input within a array
    int guesses[length]; //The randomly generated 4 0-9 numbers within a array
    int winCount = 0; //Keeps track of the number of correct numbers & determines the winning bet amount
    double betAmount = 0; //Users bet amount, defaulted at 0
    double winning = 0; //Users win amount, defaulted at 0
    
    cout << "Input your bet amount ";
    cin >> betAmount;
    cout << endl;
    
    cout << "Input your 4 numbers between 0-9" << endl;
    
    //For loop gets each guess number and stores it in a array
    for (int x = 0; x < length; x++) {
        cin >> inputs[x];
        
        while (inputs[x] < from || inputs[x] > to) {
            cout << "Input Invalid, please enter another number" << endl;
            cin >> inputs[x];
        }
    }
    
    getSequenceOfNumbers(guesses);
    
    /*For loop compares each section of array between the Input and Guess--If comparison is true, adds in a WinCount*/
    for (int x = 0; x < 4; x++) {
        if (inputs[x] == guesses[x])
            winCount++;
        
    }
    cout << "The drawn numbers are: " << endl;
    
    //For loop displays the randomly generated numbers
    for (int x = 0; x < 4; x++) {
        cout << guesses[x] << ' ';
    }
    cout << endl << endl;
    
    
    /*Switch statement for the 4 possible outcomes
     (Lose money, Break even, Win twice, quad, 50 times)*/
    switch (winCount) {
        case 0: // Lose BetAmount
            cout << "You lost " << betAmount << endl;
            winning -= betAmount;
            break;
            
        case 1: //Break Even with BetAmount
            cout << "You guessed 1 number. You broke even with $" << winning << endl;
            break;
        case 2: //Win twice the BetAmount
            winning = betAmount * 2;
            cout << "You guessed 2 numbers. You doubled your amount with $" << winning << endl;
            break;
            
        case 3: //Win quadruple the BetAmount
            winning = betAmount * 4;
            cout << "You guessed 3 numbers. You quadrupled your amount with $" << winning << endl;
            break;
            
        case 4: //Win 50 times the BetAmount
            winning = betAmount * 50;
            cout << "You matched all the numbers, you have won " << winning << endl;
            break;
    }
    cout << endl;
    
    
    setWinningAmount(winning);
}

