#include "lotto.h"

void Lotto::play() {
    
    Game::play();
    getUserInfo();
    
    int games = getNumberOfGames();
    for (int i = 0; i < games; i++)
    {
        cout << "Mini Lotto Game number " << i + 1 << "\n";
        playOneGame();
        
        if (bet > 0) {
            cout << "You have won $" << bet << "\n\n";
        }
        else {
            cout << "You have lost $1\n\n";
        }
        
    }
    calcBonus();
    print();
}

void Lotto::playOneGame() {
    int choice;//choice
    int* rNumbers = new int[number];
    int *userInput = new int[number];
    
    cout << "1-Do you want to enter your numbers or\n2-play quick?\n";
    cin >> choice;
    
    switch (choice) {
        // User enters his pick
        case 1:
            cout << "Enter 5 numbers: " << endl;
            
            for (int i = 0; i < number; i++) {
                cin >> userInput[i];
                
                // Insure valid input
                while (userInput[i] < from || userInput[i] > to) {
                    cout << "Invalid input. Enter a number betwee 1 & 35: ";
                    cin >> userInput[i];
                }
            }
            
            break;
        
        // Game picks random numbers for the user
        case 2:
            getSequenceOfNumbers(userInput);
            
            // Print the picked numbers for the user
            cout << "The random pick for you is: ";
            for (int i = 0; i < number; i++) {
                cout << userInput[i] << " ";
            }
            cout << endl;
            break;
    }
    
    // Create and print winning numbers
    getSequenceOfNumbers(rNumbers);
    cout << "The winning numbers are: ";
    for (int i = 0; i < number; i++) {
        cout << rNumbers[i] << " ";
    }
    cout << endl << endl;
    
    
    // compare the arrays
    match = 0;
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            if (rNumbers[i] == userInput[j]) {
                match++;
                break;
            }
        }
    }
    cout << "You have guessed " << match << " number(s)" << endl;
    calcWinning();
}


void Lotto::calcWinning() {
    
    switch (match) {
        case 3:
            bet = 5;
            break;
            
        case 4:
            bet = 1000;
            break;
            
        case 5:
            bet = 250000;
            break;
            
        default:
            bet = -1;
            break;
    }
    setWinningAmount(bet);
    
}
// change the bool
// change the userInput
//make it more user friendly
//everygame
