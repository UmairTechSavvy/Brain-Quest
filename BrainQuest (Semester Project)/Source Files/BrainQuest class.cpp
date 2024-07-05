#include "PlayerClass.cpp"
#include "QuestionInitializerClassImplementation.cpp"

class BrainQuest{
public:
    void initialize(Player &user);
    void logout(Player user) const;
    static void displayStartingMenu(void);
    static void displayAdvancedMenu(void);
    static void displayRules(void);
    void generateIQAnalysis(Player user) const;

    template<typename T>
    void playGame(vector<T> &questionsVec, Player &user, string cat);
};

void BrainQuest :: initialize(Player &user){
    string Name, Password;
    cout << "\nEnter your name:";
    getline(cin >> ws, Name);
    while(true){
        string p;
        cout << "\nEnter your password (atmost 15 characters):";
        getline(cin >> ws, p);
        if(p.length() > 15){
            cout << "\nThe password must consist of 15 characters atmost!!";
        }
        else{
            Password = p; break;
        }
    }
    user.name = Name; user.password = Password;
    cout << "\nYour credentials have successfully been initialized, " << user.name << "!" << endl; sleep(2);
}

void BrainQuest :: logout(Player user) const{
    system("cls");
    while(true){
        string p;
        cout << "\nEnter your password for saving your finals stats:";
        getline(cin >> ws, p);
        if(p == user.password){
            break;
        }
        else{
            cout << "\nInvalid password entered!" << endl;
        }
    }
    cout << "\nPassword Verified. Your stats have been successfully saved!"; sleep(3);
}

void BrainQuest :: displayStartingMenu(void){
    cout << "\n\t\t\t\t\t-------------------Welcome to BrainQuest-------------------";
    cout << "\n\nPlease refer to the rules if this is your first time on the menu..." << endl;
    cout << "\n1. Check Stats" << "\n2. Play Maths Category" << "\n3. Play Sports Category" << "\n4. Play History Category";
    cout << "\n5. Play Riddle Category" << "\n6. IQ Analysis" << "\n7. Show Rules" << "\n8. Display Leaderboard";
    cout << "\n9. Exit Game" << endl << endl; sleep(4);
}

void BrainQuest :: displayAdvancedMenu(void){
    cout << "\n\t\t\t\t\t-------------------Select Your Level Of Difficulty-------------------";
    cout << "\n1. Easy" << "\n2. Medium" << "\n3. Hard" << "\n4. Random" << endl << endl; sleep(4);
}

void BrainQuest :: displayRules(void){
    system("cls");
    cout << "\n\t\t\t\t\t-------------------Rules For Playing BrainQuest-------------------";
    cout << "\n\nEach category has Easy, Medium, Hard, and Random modes.";
    cout << "\n3 wrong guesses and you're out!";
    cout << "\nEach category has 15 Easy, 15 Medium, and 15 Hard questions.";
    cout << "\nPoints: Easy (100), Medium (250), Hard (400).";
    cout << "\nEach category level can only be played once, so CHOOSE WISELY!";
    cout << "\nPoints in Random Mode don't affect other modes.";
    cout << "\nComplete a category for a 500-point bonus!";
    cout << "\nCompleted categories cannot be replayed.";
    cout << "\n*IT IS ADVISED TO PLAY ALL CATEGORIES BEFORE GENERATING YOUR IQ SCORE*";
    sleep(12);
    cout << "\n\n\nPress any key to return to the menu:"; string key; getline(cin >> ws, key);
    system("cls");
}

void BrainQuest :: generateIQAnalysis(Player user) const{
    float mathsIQ = (user.mathsScore / 10000.0) * 100.0;
    float sportsIQ = (user.sportsScore / 10000.0) * 100.0;
    float historyIQ = (user.historyScore / 10000.0) * 100.0;
    float riddleIQ = (user.riddleScore / 10000.0) * 100.0;

    float totalIQ = ((mathsIQ + sportsIQ + historyIQ + riddleIQ) / 4.0);

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGenerating IQ Analysis...";
    sleep(3);
    system("cls");

    cout << "\n\t\t\t\t-------------------IQ Analysis Report (Categorical and Combined)-------------------\n\n";

    cout << "Maths IQ Analysis Score: " << mathsIQ << " (";
    if (mathsIQ < 40) {
        cout << "Mental Disability)";
    } else if (mathsIQ <= 70) {
        cout << "Average)";
    } else if (mathsIQ <= 90) {
        cout << "Above Average)";
    } else {
        cout << "Mentally Gifted)";
    }
    cout << endl << endl;

    cout << "Sports IQ Analysis Score: " << sportsIQ << " (";
    if (sportsIQ < 40) {
        cout << "Mental Disability)";
    } else if (sportsIQ <= 70) {
        cout << "Average)";
    } else if (sportsIQ <= 90) {
        cout << "Above Average)";
    } else {
        cout << "Mentally Gifted)";
    }
    cout << endl << endl;

    cout << "History IQ Analysis Score: " << historyIQ << " (";
    if (historyIQ < 40) {
        cout << "Mental Disability)";
    } else if (historyIQ <= 70) {
        cout << "Average)";
    } else if (historyIQ <= 90) {
        cout << "Above Average)";
    } else {
        cout << "Mentally Gifted)";
    }
    cout << endl << endl;

    cout << "Riddle IQ Analysis Score: " << riddleIQ << " (";
    if (riddleIQ < 40) {
        cout << "Mental Disability)";
    } else if (riddleIQ <= 70) {
        cout << "Average)";
    } else if (riddleIQ <= 90) {
        cout << "Above Average)";
    } else {
        cout << "Mentally Gifted)";
    }
    cout << endl << endl;

    cout << "Total IQ Analysis Score: " << totalIQ << " (";
    if (totalIQ < 40) {
        cout << "Mental Disability)";
    } else if (totalIQ <= 70) {
        cout << "Average)";
    } else if (totalIQ <= 90) {
        cout << "Above Average)";
    } else {
        cout << "Mentally Gifted)";
    }
    cout << endl << endl;

    sleep(10);
}

template<typename T>
void BrainQuest :: playGame(vector<T> &questionsVec, Player &user, string cat){
    int size = questionsVec.size(), lives = user.getLifelines(), currScore = 0, currQues = 0;
    unordered_set<int> questionIndices;
    for(int i = 0; i < size; i++){
        questionIndices.insert(i);
    }
    bool unsolvedQuestionExists = false;
    while(lives > 0 && !questionIndices.empty()){
        int ans = 0;
        auto index = questionIndices.begin();
        system("cls");
        if(!questionsVec[*index].getQuestionSolved()){
            unsolvedQuestionExists = true;
            questionsVec[*index].displayQuestion(); cout << "Lifelines Remaining: " << lives;
            cout << "\nCurrent Score: " << currScore << endl << endl; sleep(4);
            cout << "\nEnter your answer: ";
            cin >> ans;
            if(ans - 1 == questionsVec[*index].getCorrectAnswer()){
                questionsVec[*index].setQuestionSolved(true);
                cout << "\nThat is the correct answer!" << endl; sleep(2);
                if(questionsVec[*index].getLevel() == "Easy"){
                    currQues++; currScore += 100;
                }
                else if(questionsVec[*index].getLevel() == "Medium"){
                    currQues++; currScore += 250;
                }
                else{
                    currQues++; currScore += 400;
                }
            }
            else{
                cout << "\nIncorrect answer..." << endl; sleep(2);
                lives--;
            }
            questionIndices.erase(*index);
        }
        else{
            questionIndices.erase(*index);
        }
    }
    system("cls");
    if(!unsolvedQuestionExists){
        cout << user.getName() << ", you have already solved this entire category!" << endl << endl;
        sleep(3); system("cls");
    }
    else{
        if(lives == 3 && questionIndices.empty()){
            //giving the user a bonus score of 500 for answering all the questions correctly
            cout << "\nCongratulations, " << user.getName() << "! You have answered all the questions correctly...";
            cout << "\nYou have been given a bonus of 500 points!" << endl; sleep(5);
            user.setTotalScore(500); // Adjust according to the category
            if(cat == "Maths") {user.setMathsScore(500);}
            else if(cat == "Sports") {user.setSportsScore(500);}
            else if(cat == "History") {user.setHistoryScore(500);}
            else{ user.setRiddleScore(500);}
        }
        user.setTotalScore(currScore); user.setTotalQuesCorrect(currQues); // Adjust according to the category
        if(cat == "Maths") {user.setMathsScore(currScore); user.setMathsQuesCorrect(currQues);}
        else if(cat == "Sports") {user.setSportsScore(currScore); user.setSportsQuesCorrect(currQues);}
        else if(cat == "History") {user.setHistoryScore(currScore); user.setHistoryQuesCorrect(currQues);}
        else {user.setRiddleScore(currScore); user.setRiddleQuesCorrect(currQues);}
        cout << "\nYour stats after this round are:" << endl << endl;
        cout << "\nTotal Questions Correct:" << "  " << user.getTotalQuesCorrect();
        cout << "\nTotal Score:" << "  " << user.getTotalScore();
        if(cat == "Maths") {cout << "\nTotal Maths Score: " << user.getMathsScore() << "\nTotal Maths Questions Correct: " << user.getMathsQuesCorrect() << endl;}
        else if(cat == "Sports") {cout << "\nTotal Sports Score: " << user.getSportsScore() << "\nTotal Sports Questions Correct: " << user.getSportsQuesCorrect() << endl;}
        else if(cat == "History") {cout << "\nTotal History Score: " << user.getHistoryScore() << "\nTotal History Questions Correct: " << user.getHistoryQuesCorrect() << endl;}
        else {cout << "\nTotal Riddle Score: " << user.getRiddleScore() << "\nTotal Riddle Questions Correct: " << user.getRiddleQuesCorrect() << endl;}
        sleep(6); system("cls");
    }
}