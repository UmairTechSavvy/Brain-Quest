#include <iostream>
#include <unistd.h>
using namespace std;

class Player{
private:
    string name, password;      //password is for initializing the user before playing the game
    int totalScore, mathsScore, historyScore, sportsScore, riddleScore;
    int totalQuesCorrect, mathsQuesCorrect, historyQuesCorrect, sportsQuesCorrect, riddleQuesCorrect;
    int lifelines;
public:
    //default constructor
    Player() : totalScore(0), mathsScore(0), historyScore(0), sportsScore(0), riddleScore(0), totalQuesCorrect(0), 
    mathsQuesCorrect(0), historyQuesCorrect(0), sportsQuesCorrect(0), riddleQuesCorrect(0), lifelines(3) {}

    //getters and setters
    string getName(void) const;
    string getPassword(void) const;
    int getTotalScore(void) const;
    int getMathsScore(void) const;
    int getHistoryScore(void) const;
    int getSportsScore(void) const;
    int getRiddleScore(void) const;
    int getTotalQuesCorrect(void) const;
    int getMathsQuesCorrect(void) const;
    int getHistoryQuesCorrect(void) const;
    int getSportsQuesCorrect(void) const;
    int getRiddleQuesCorrect(void) const;
    int getLifelines(void) const;

    void setTotalScore(int score);
    void setMathsScore(int score);
    void setHistoryScore(int score);
    void setSportsScore(int score);
    void setRiddleScore(int score);
    void setTotalQuesCorrect(int score);
    void setMathsQuesCorrect(int score);
    void setHistoryQuesCorrect(int score);
    void setSportsQuesCorrect(int score);
    void setRiddleQuesCorrect(int score);
    void setLifelines(int Lifelines);

    //important methods
    void displayPlayerInfo(void) const;             //for displaying the information of the user (current)

    friend class BrainQuest;
    friend void serializePlayer(const Player& player, std::ofstream& ofs);
    friend void deserializePlayer(Player& player, std::ifstream& ifs);
};

//implementation of methods of the class

string Player :: getName(void) const{
    return name;
}
string Player :: getPassword(void) const{
    return password;
}
int Player :: getTotalScore(void) const{
    return totalScore;
}
int Player :: getMathsScore(void) const{
    return mathsScore;
}
int Player :: getHistoryScore(void) const{
    return historyScore;
}
int Player :: getSportsScore(void) const{
    return sportsScore;
}
int Player :: getRiddleScore(void) const{
    return riddleScore;
}
int Player :: getTotalQuesCorrect(void) const{
    return totalQuesCorrect;
}
int Player :: getMathsQuesCorrect(void) const{
    return mathsQuesCorrect;
}
int Player :: getHistoryQuesCorrect(void) const{
    return historyQuesCorrect;
}
int Player :: getSportsQuesCorrect(void) const{
    return sportsQuesCorrect;
}
int Player :: getRiddleQuesCorrect(void) const{
    return riddleQuesCorrect;
}
int Player :: getLifelines(void) const{
    return lifelines;
}
void Player :: setTotalScore(int score){
    totalScore += score;
}
void Player :: setMathsScore(int score){
    mathsScore += score;
}
void Player :: setHistoryScore(int score){
    historyScore += score;
}
void Player :: setSportsScore(int score){
    sportsScore += score;
}
void Player :: setRiddleScore(int score){
    riddleScore += score;
}
void Player :: setTotalQuesCorrect(int score){
    totalQuesCorrect += score;
}
void Player :: setMathsQuesCorrect(int score){
    mathsQuesCorrect += score;
}
void Player :: setHistoryQuesCorrect(int score){
    historyQuesCorrect += score;
}
void Player :: setSportsQuesCorrect(int score){
    sportsQuesCorrect += score;
}
void Player :: setRiddleQuesCorrect(int score){
    riddleQuesCorrect += score;
}
void Player :: setLifelines(int Lifelines){
    lifelines = Lifelines;
}

void Player :: displayPlayerInfo(void) const{
    cout << "\nName: " << name;
    cout << "\nTotal Score: " << totalScore << "\nTotal Questions Correct: " << totalQuesCorrect << endl;
    cout << "\nCategorical Score: ";
    cout << "\nMaths Score: " << mathsScore << "\nMaths Questions Correct: " << mathsQuesCorrect << endl;
    cout << "\nHistory Score: " << historyScore << "\nHistory Questions Correct: " << historyQuesCorrect << endl;
    cout << "\nSports Score: " << sportsScore << "\nSports Questions Correct: " << sportsQuesCorrect << endl;
    cout << "\nRiddle Score: " << riddleScore << "\nRiddle Questions Correct: " << riddleQuesCorrect << endl;

    sleep(14); system("cls");
}