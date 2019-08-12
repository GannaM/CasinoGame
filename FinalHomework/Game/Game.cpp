#include "Game.h"

#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>


// Constructor
Game::Game(const string gameName, int from, int to, int length, int userNum) {
    name = gameName;
    rangeFrom = from;
    rangeTo = to;
    arrayLength = length;
    userLen = userNum;

}


// Generates and returns a random number within a certain range
int Game::getRandomNumber() const {
    
    if (rangeFrom == 0) {
        return (rand() % (rangeTo + 1));
    }
    
    return (rand() % rangeTo) + rangeFrom;
}

// Generates a sequence of random numbers
void Game::getSequenceOfNumbers(int *arrayOfNumbers) {    
    for (int i = 0; i < arrayLength; i++) {
        arrayOfNumbers[i] = getRandomNumber();
    }
}

// Get user Name and number of games to play
void Game::getUserInfo() {
    
    //cin.ignore(10, '\n');
    cout << "What is your full name? ";
    getline(cin, userName);
    
    //cin.ignore(10, '\n');
    
    cout << "How many times would you like to play " << name << "? ";
    cin >> games;
    
    // If the number of games is less than 1, the game will stop
    if (games < 1) {
        games = 0;
        return;
    }
    
    //cin.ignore(10, '\n');
    
    cout << endl;
}

void Game::setWinningAmount(double amount) {
    winning += amount;
}

//void Game::setBetAmount(double amount) {
//    betAmount = amount;
//}

// Calculates bonus based on the winning
void Game::calcBonus() {
    if (winning <= 50.00) {
        bonus = winning * 0.015;
        percentage = 1.5;
    }
    else if (winning <= 100.00) {
        bonus = winning * 0.019;
        percentage = 1.9;
    }
    else if (winning <= 1000.00) {
        bonus = winning * 0.025;
        percentage = 2.5;
    }
    else if (winning > 1000.00) {
        bonus = winning * 0.029;
        percentage = 2.9;
    }
}

string Game::getName() const {
    return this->name;
}

int Game::getNumberOfGames() const {
    return this->games;
}

double Game::getWinningAmount() const {
    return this->winning;
}

double Game::getBonus() const {
    return this->bonus;
}

double Game::getPercentage() const {
    return this->percentage;
}

void Game::print() const {
    
    cout << setprecision(2) << showpoint << fixed;
    
    // if it's one game it will print "1 game", if more than "n gameS"
    string gameString = games == 1 ? " game":" games";
    
    cout << "Final results for " << userName << " after " << games
    << gameString << " of " << name << ": " << endl;
    
    if (winning > 0) {
        cout << userName << " won a total of $" << winning << endl;
        cout << "The casino will add a bonus of " << percentage << "% to your winnings" << endl;
        cout << "The casino bonus is $" << bonus << endl;
        cout << userName << " total winnings are $" << winning + bonus << endl;
    }
    else {
        cout << userName << " lost a total of $" << abs(winning) << endl;
    }
    
    cin.ignore(10, '\n');
    
    cout << endl << endl;
    
}


void Game::play() {
    time_t t;
    srand((unsigned)time(&t));
    
}

