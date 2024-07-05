#include "BrainQuest class.cpp"
#include <fstream>

int main(void){

    vector<Maths> MathsEasy, MathsMedium, MathsHard;
    vector<Sports> SportsEasy, SportsMedium, SportsHard;
    vector<History> HistoryEasy, HistoryMedium, HistoryHard;
    vector<Riddle> RiddleEasy, RiddleMedium, RiddleHard;

    QuestionInitializer initializerDummy;
    //used for bombarding (or filling up) all the above declared vectors with their relevant questions
    //this is implemented in the QuestionInitializerClassPrototype file

    initializerDummy.initializeMathsQuestions(MathsEasy, MathsMedium, MathsHard);
    initializerDummy.initializeSportsQuestions(SportsEasy, SportsMedium, SportsHard);
    initializerDummy.initializeHistoryQuestions(HistoryEasy, HistoryMedium, HistoryHard);
    initializerDummy.initializeRiddleQuestions(RiddleEasy, RiddleMedium, RiddleHard);

    Player player; BrainQuest dummy;
    dummy.initialize(player); system("cls");
    bool mathsRandomPlayed = false, sportsRandomPlayed = false, historyRandomPlayed = false, riddleRandomPlayed = false;
    bool mathsEasyPlayed = false, mathsMediumPlayed = false, mathsHardPlayed = false;
    bool sportsEasyPlayed = false, sportsMediumPlayed = false, sportsHardPlayed = false;
    bool historyEasyPlayed = false, historyMediumPlayed = false, historyHardPlayed = false;
    bool riddleEasyPlayed = false, riddleMediumPlayed = false, riddleHardPlayed = false;

    while(true){
        BrainQuest :: displayStartingMenu();
        int startingMenuChoice = 0;
        while(true){
            int c = 0;
            cout << "\nEnter your choice from the above menu: ";
            cin >> c;
            if(c >= 1 && c <= 9){
                startingMenuChoice = c; break;
            }
            cout << "\nInvalid Menu Option Entered!" << endl;
        }
        if(startingMenuChoice == 1){
            sleep(1);
            system("cls"); cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Player Info......"; sleep(3); system("cls");
            player.displayPlayerInfo();
        }
        else if(startingMenuChoice == 6){
            sleep(1); system("cls"); dummy.generateIQAnalysis(player); system("cls");
        }
        else if(startingMenuChoice == 9){
            ofstream file("leaderboard.txt", ios :: app);
            string name; long long score;
            name = player.getName(); score = player.getTotalScore();
            if(file.fail()){
                exit(1);
            }
            file << name; file << score; file << "*" << endl;
            file.close();
            sleep(1);
            dummy.logout(player); system("cls");
            dummy.generateIQAnalysis(player); system("cls");
            cout << "\nThankyou for playing BrainQuest, " << player.getName() << "!";
            cout << "\nYour final stats are: " << endl;
            player.displayPlayerInfo(); break;
        }
        else if(startingMenuChoice == 7){
            sleep(1);
            system("cls"); cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Gameplay Rules......"; sleep(3);
            BrainQuest :: displayRules();
        }
        else if(startingMenuChoice == 8){
            ifstream file("leaderboard.txt", ios :: in);
            if(file.fail()){
                exit(1);
            }
            vector<vector<string>> players; vector<string> temp; string name; string score; char ch;
            while(file.get(ch)){
                if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                    name.push_back(ch);
                }
                else if((int)ch >= 48 && (int)ch <= 57){
                    score.push_back(ch);
                }
                else if(ch == '*'){
                    temp.push_back(name); temp.push_back(score); players.push_back(temp); temp.clear(); name = ""; score = "";
                }
                else{
                    continue;
                }
            }
            //now we need to sort it based on the scores of the players
            for(size_t pass = 1; pass < players.size(); pass++){
                for(size_t i = 0; i < players.size() - 1; i++){
                    long long scoreone = stoll(players[i][1]), scoretwo = stoll(players[i + 1][1]);
                    if(scoreone < scoretwo){
                        vector<string> temp = players[i];
                        players[i] = players[i + 1];
                        players[i + 1] = temp;
                    }
                }
            }
            sleep(1); system("cls"); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Leaderboard..."; sleep(3); system("cls");
            cout << "\n\t\t\t\t\t-------------------LeaderBoard-------------------" << endl << endl;
            int counter = 1;
            for(auto &player : players){
                cout << "\n\t\t\t\t\t-------------------Rank: " << counter << "-----------------------";
                cout << "\nUsername: " << player[0] << "\nTotal Score: " << player[1] << endl << endl;
                counter++;
            }
            file.close();
            string exit; cout << "\nEnter any key to return to main menu:"; getline(cin >> ws, exit);
        }
        else{
            sleep(1); system("cls"); BrainQuest :: displayAdvancedMenu();
            int advancedMenuChoice = 0;
            while(true){
                int c = 0;
                cout << "\nEnter your choice from the above menu: ";
                cin >> c;
                if(c >= 1 && c <= 4){
                    advancedMenuChoice = c; break;
                }
                cout << "\nInvalid Menu Option Entered!" << endl;
            }

            //here we need to check all the combinations of startingMenuChoice(2-5) and advancedMenuChoice(1-4)

            if(startingMenuChoice == 2 && advancedMenuChoice == 1){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Maths Easy Category......"; sleep(3);
                if(!mathsEasyPlayed){
                    mathsEasyPlayed = true;
                    dummy.playGame<Maths>(MathsEasy, player, "Maths");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 2 && advancedMenuChoice == 2){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Maths Medium Category......"; sleep(3);
                if(!mathsMediumPlayed){
                    mathsMediumPlayed = true;
                    dummy.playGame<Maths>(MathsMedium, player, "Maths");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 2 && advancedMenuChoice == 3){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Maths Hard Category......"; sleep(3);
                if(!mathsHardPlayed){
                    mathsHardPlayed = true;
                    dummy.playGame<Maths>(MathsHard, player, "Maths");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 2 && advancedMenuChoice == 4){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Maths Random Category......"; sleep(3);
                if(!mathsRandomPlayed){
                    mathsRandomPlayed = true;
                    vector<Maths> combinedQuestionVec;
                    for(auto &obj : MathsEasy){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : MathsMedium){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : MathsHard){ combinedQuestionVec.push_back(obj);}
                    dummy.playGame<Maths>(combinedQuestionVec, player, "Maths");
                }
                else{
                    system("cls"); cout << "\nYou have already played the Random mode for this category! Remember, you can play Random Mode only once per category..." << endl; sleep(5);
                }
            }
            else if(startingMenuChoice == 3 && advancedMenuChoice == 1){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Sports Easy Category......"; sleep(3);
                if(!sportsEasyPlayed){
                    sportsEasyPlayed = true;
                    dummy.playGame<Sports>(SportsEasy, player, "Sports");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 3 && advancedMenuChoice == 2){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Sports Medium Category......"; sleep(3);
                if(!sportsMediumPlayed){
                    sportsMediumPlayed = true;
                    dummy.playGame<Sports>(SportsMedium, player, "Sports");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 3 && advancedMenuChoice == 3){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Sports Hard Category......"; sleep(3);
                if(!sportsHardPlayed){
                    sportsHardPlayed = true;
                    dummy.playGame<Sports>(SportsHard, player, "Sports");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 3 && advancedMenuChoice == 4){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Sports Random Category......"; sleep(3);
                if(!sportsRandomPlayed){
                    sportsRandomPlayed = true;
                    vector<Sports> combinedQuestionVec;
                    for(auto &obj : SportsEasy){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : SportsMedium){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : SportsHard){ combinedQuestionVec.push_back(obj);}
                    dummy.playGame<Sports>(combinedQuestionVec, player, "Sports");
                }
                else{
                    system("cls"); cout << "\nYou have already played the Random mode for this category! Remember, you can play Random Mode only once per category..." << endl; sleep(5);
                }
            }
            else if(startingMenuChoice == 4 && advancedMenuChoice == 1){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading History Easy Category......"; sleep(3);
                if(!historyEasyPlayed){
                    historyEasyPlayed = true;
                    dummy.playGame<History>(HistoryEasy, player, "History");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 4 && advancedMenuChoice == 2){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading History Medium Category......"; sleep(3);
                if(!historyMediumPlayed){
                    historyMediumPlayed = true;
                    dummy.playGame<History>(HistoryMedium, player, "History");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 4 && advancedMenuChoice == 3){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading History Hard Category......"; sleep(3);
                if(!historyHardPlayed){
                    historyHardPlayed = true;
                    dummy.playGame<History>(HistoryHard, player, "History");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 4 && advancedMenuChoice == 4){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading History Random Category......"; sleep(3);
                if(!historyRandomPlayed){
                    historyRandomPlayed = true;
                    vector<History> combinedQuestionVec;
                    for(auto &obj : HistoryEasy){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : HistoryMedium){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : HistoryHard){ combinedQuestionVec.push_back(obj);}
                    dummy.playGame<History>(combinedQuestionVec, player, "History");
                }
                else{
                    system("cls"); cout << "\nYou have already played the Random mode for this category! Remember, you can play Random Mode only once per category..." << endl; sleep(5);
                }
            }
            else if(startingMenuChoice == 5 && advancedMenuChoice == 1){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Riddle Easy Category......"; sleep(3);
                if(!riddleEasyPlayed){
                    riddleEasyPlayed = true;
                    dummy.playGame<Riddle>(RiddleEasy, player, "Riddle");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 5 && advancedMenuChoice == 2){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Riddle Medium Category......"; sleep(3);
                if(!riddleMediumPlayed){
                    riddleMediumPlayed = true;
                    dummy.playGame<Riddle>(RiddleMedium, player, "Riddle");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else if(startingMenuChoice == 5 && advancedMenuChoice == 3){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Riddle Hard Category......"; sleep(3);
                if(!riddleHardPlayed){
                    riddleHardPlayed = true;
                    dummy.playGame<Riddle>(RiddleHard, player, "Riddle");
                }
                else{system("cls"); cout << "\nYou have already tested your intelligence in this category!" << endl; sleep(3);}
            }
            else{
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Riddle Random Category......"; sleep(3);
                if(!riddleRandomPlayed){
                    riddleRandomPlayed = true;
                    vector<Riddle> combinedQuestionVec;
                    for(auto &obj : RiddleEasy){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : RiddleMedium){ combinedQuestionVec.push_back(obj);}
                    for(auto &obj : RiddleHard){ combinedQuestionVec.push_back(obj);}
                    dummy.playGame<Riddle>(combinedQuestionVec, player, "Riddle");
                }
                else{
                    system("cls"); cout << "\nYou have already played the Random mode for this category! Remember, you can play Random Mode only once per category..." << endl; sleep(5);
                }
            }
        }
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tReturning to Main Menu......"; sleep(3); system("cls");
    }

    return 0;
}