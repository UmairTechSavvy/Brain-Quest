#include "QuestionInitializerClassPrototype.cpp"

void QuestionInitializer :: initializeMathsQuestions(vector<Maths> &easy, vector<Maths> &medium, vector<Maths> &hard){
    for(auto &question : MathsEasyFiller){
        Maths dummy;
        dummy.setQuestion(question[0][0]);      //initializes the question part of the object
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        easy.push_back(dummy);
    }
    for(auto &question : MathsMediumFiller){
        Maths dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        medium.push_back(dummy);
    }
    for(auto &question : MathsHardFiller){
        Maths dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        hard.push_back(dummy);
    }

}
void QuestionInitializer ::initializeSportsQuestions(vector<Sports> &easy, vector<Sports> &medium, vector<Sports> &hard){
    for(auto &question : SportsEasyFiller){
        Sports dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        easy.push_back(dummy);
    }
    for(auto &question : SportsMediumFiller){
        Sports dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        medium.push_back(dummy);
    }
    for(auto &question : SportsHardFiller){
        Sports dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        hard.push_back(dummy);
    }
}
void QuestionInitializer :: initializeHistoryQuestions(vector<History> &easy, vector<History> &medium, vector<History> &hard){
    for(auto &question : HistoryEasyFiller){
        History dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        easy.push_back(dummy);
    }
    for(auto &question : HistoryMediumFiller){
        History dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        medium.push_back(dummy);
    }
    for(auto &question : HistoryHardFiller){
        History dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        hard.push_back(dummy);
    }
}
void QuestionInitializer :: initializeRiddleQuestions(vector<Riddle> &easy, vector<Riddle> &medium, vector<Riddle> &hard){
    for(auto &question : RiddleEasyFiller){
        Riddle dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        easy.push_back(dummy);
    }
    for(auto &question : RiddleMediumFiller){
        Riddle dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        medium.push_back(dummy);
    }
    for(auto &question : RiddleHardFiller){
        Riddle dummy;
        dummy.setQuestion(question[0][0]);
        dummy.setLevel(question[1][0]);
        dummy.setCorrectAnswer(stoi(question[3][0]));
        dummy.setAnswers(question[2]);
        hard.push_back(dummy);
    }
}