#include <vector>
#include <iostream>
#include <unordered_set>
#include <unistd.h>
using namespace std;

class Question{
protected:
    string question, level;
    vector<string> answers;
    int correctAnswer;
    bool questionSolved = false;
public:
    //default constructor
    Question() : correctAnswer(0) {}

    //getters and setters
    string getQuestion(void) const;
    string getLevel(void) const;
    int getCorrectAnswer(void) const;
    void getAnswers(void) const;
    bool getQuestionSolved(void) const;

    void setQuestion(string q);
    void setLevel(string level);
    void setCorrectAnswer(int ans);
    void setAnswers(vector<string> answerVector);
    void setQuestionSolved(bool solved);

    virtual void displayQuestion(void) const = 0;       //for displaying the question, based on the sub class it belongs to
};

string Question::getQuestion(void) const{
    return question;
}
string Question::getLevel(void) const{
    return level;
}
int Question::getCorrectAnswer(void) const{
    return correctAnswer;
}
void Question::getAnswers(void) const{
    for(size_t i = 0; i < answers.size(); i++){
        cout << "\nAnswer #:" << i + 1  << "  " << answers[i];
    }
}
bool Question::getQuestionSolved(void) const{
    return questionSolved;
}

void Question::setQuestion(string q){
    question = q;
}
void Question::setLevel(string level){
    this->level = level;
}
void Question::setCorrectAnswer(int ans){
    correctAnswer = ans;
}
void Question::setAnswers(vector<string> answerVector){
    for(auto &answer : answerVector){
        this->answers.push_back(answer);
    }
}
void Question::setQuestionSolved(bool solved){
    questionSolved = solved;
}

class Maths : public Question{
public:
    void displayQuestion(void) const{
        cout << "\n\t\t\t\t\t-------------------Question Category : Mathematics-------------------";
        cout << "\n\t\t\t\t\t---------------------Difficulty Level: " << level << "--------------------------"<< endl << endl;
        cout << "" << question << "";
        getAnswers();
        cout << endl << endl;
    }
};

class Sports : public Question{
public:
    void displayQuestion(void) const{
        cout << "\n\t\t\t\t\t-------------------Question Category : Sports-------------------";
        cout << "\n\t\t\t\t\t---------------------Difficulty Level: " << level << "--------------------------"<< endl << endl;
        cout << "" << question << "";
        getAnswers();
        cout << endl << endl;
    }
};

class History : public Question{
public:
    void displayQuestion(void) const{
        cout << "\n\t\t\t\t\t-------------------Question Category : History-------------------";
        cout << "\n\t\t\t\t\t---------------------Difficulty Level: " << level << "--------------------------"<< endl << endl;
        cout << "" << question << "";
        getAnswers();
        cout << endl << endl;
    }
};

class Riddle : public Question{
public:
    void displayQuestion(void) const{
        cout << "\n\t\t\t\t\t-------------------Question Category : Riddle-------------------";
        cout << "\n\t\t\t\t\t---------------------Difficulty Level: " << level << "--------------------------"<< endl << endl;
        cout << "" << question << "";
        getAnswers();
        cout << endl << endl;
    }
};