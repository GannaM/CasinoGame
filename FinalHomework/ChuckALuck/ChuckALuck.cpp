#include "ChuckALuck.h"

void ChuckALuck::play() {

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

        } while (games !=0 );
    }

    calcBonus();
    print();

}

void ChuckALuck::playOneGame() {
    double betAmount = 0;
    int betNumber;
    double winning = 0;
    
    cout << "How much would you like to bet? " ;
    cin >> betAmount;
    
    cout << "What number would you like to bet on? ";
    cin >> betNumber;
    
    // Varify that user entered a valid input
    while (betNumber < 1 || betNumber > 6) {
        cout << "Invalid input. Select a number between 1 & 6: ";
        cin >> betNumber;
    }
    
    // Generate a sequence of 5 random numbers
    int array[length];
    getSequenceOfNumbers(array);
    
    cout << "The dice came up ";
    // compare the dice results with user's guess and print the array
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
        if (array[i] == betNumber) {
            winning += betAmount;
        }
    }
    cout << endl;
    
    // if the user didn't guess any number, subtract betAmount from winnings
    if (winning > 0) {
        cout << "You win $" << winning << endl;
    }
    else {
        cout << "You lose $" << betAmount << endl;
        winning -= betAmount;
    }
    cout << endl;
    
    setWinningAmount(winning);
}
