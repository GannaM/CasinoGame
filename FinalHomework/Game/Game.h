#ifndef Game_h
#define Game_h


#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
    
public:
    Game(const string gameName, int from, int to, int length, int userNum);
    
    virtual void play() = 0;
    
protected:
    
    virtual void playOneGame() = 0;  // pure virtual
    
    void print() const;                 // prints the result of the games
    
    void getUserInfo();                 // get user name and details
    int getRandomNumber() const;        // generates one random number
    void getSequenceOfNumbers(int *array);    // generates a sequence of numbers
    void calcBonus();                       // calculates the amount of bonus winning
    
    void varifyInput(); // checks if user input a number withing range
    
    // GETTERS
    string getName() const;  // returns user name
    int getNumberOfGames() const; // returns number of games a user wants to play
    double getWinningAmount() const;
    //double getBetAmount() const;
    double getBonus() const;
    double getPercentage() const;
    
    // SETTERS
    void setWinningAmount(double amount);
    //void getUserNumber();


    
    
private:
    
    string name;         // the name of a game
    int rangeFrom;      // range from to generate random numbers
    int rangeTo;        // range to for random numbers
    int arrayLength;       // this is how many numbers the game will generate
    
    string userName;     // full name of the user
    int games;           // how many times a user play one game
    
    int userLen;        // this is how many numbers a user will input
    
    
    double winning = 0;     // amount of money won
    //double betAmount = 0;   // amount of money bet for one game
    double bonus = 0;       // bonus winnings
    double percentage = 0;  // the percentage amount - needed to print the output
};

#endif /* Game_h */
