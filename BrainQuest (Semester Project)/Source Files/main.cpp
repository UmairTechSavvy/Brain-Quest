#include "BrainQuest class.cpp"

void serializePlayer(const Player& player, std::ofstream& ofs);
void deserializePlayer(Player& player, std::ifstream& ifs);

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
            ofstream myFile("leaderboard.bin", ios::binary | ios::app);
            if (myFile.fail()) {
                exit(1);
            }
            serializePlayer(player, myFile);        //writing this player object in append mode to the binary file
            myFile.seekp(0, ios :: end);
            myFile.close();
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
            vector<Player> players;
            ifstream myFile("leaderboard.bin", ios::binary);
            if (!myFile) {
                exit(1);
            }
            while (myFile.peek() != EOF) {
                Player dummy;
                deserializePlayer(dummy, myFile);
                players.push_back(dummy);
            }
            
            //now we need to sort it based on the scores of the players
            for(size_t pass = 1; pass < players.size(); pass++){
                for(size_t i = 0; i < players.size() - 1; i++){
                    if(players[i].getTotalScore() > players[i + 1].getTotalScore()){
                        Player temp = players[i]; players[i] = players[i + 1]; players[i + 1] = temp;
                    }
                }
            }

            sleep(1); system("cls"); cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading Leaderboard..."; sleep(3); system("cls");
            cout << "\n\t\t\t\t\t-------------------LeaderBoard-------------------" << endl << endl;
            int counter = 1;
            for(auto &player : players){
                cout << "\n\t\t\t\t\t-------------------Rank: " << counter << "-----------------------";
                cout << "\nUsername: " << player.getName() << "\nTotal Score: " << player.getTotalScore() << endl << endl;
                counter++;
            }
            myFile.close();
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

void serializePlayer(const Player& player, std::ofstream& ofs) {
    size_t nameLength = player.getName().size();
    ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    ofs.write(player.getName().c_str(), nameLength);

    size_t passwordLength = player.getPassword().size();
    ofs.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
    ofs.write(player.getPassword().c_str(), passwordLength);

    ofs.write(reinterpret_cast<const char*>(&player.totalScore), sizeof(player.totalScore));
    ofs.write(reinterpret_cast<const char*>(&player.mathsScore), sizeof(player.mathsScore));
    ofs.write(reinterpret_cast<const char*>(&player.historyScore), sizeof(player.historyScore));
    ofs.write(reinterpret_cast<const char*>(&player.sportsScore), sizeof(player.sportsScore));
    ofs.write(reinterpret_cast<const char*>(&player.riddleScore), sizeof(player.riddleScore));

    ofs.write(reinterpret_cast<const char*>(&player.totalQuesCorrect), sizeof(player.totalQuesCorrect));
    ofs.write(reinterpret_cast<const char*>(&player.mathsQuesCorrect), sizeof(player.mathsQuesCorrect));
    ofs.write(reinterpret_cast<const char*>(&player.historyQuesCorrect), sizeof(player.historyQuesCorrect));
    ofs.write(reinterpret_cast<const char*>(&player.sportsQuesCorrect), sizeof(player.sportsQuesCorrect));
    ofs.write(reinterpret_cast<const char*>(&player.riddleQuesCorrect), sizeof(player.riddleQuesCorrect));

    ofs.write(reinterpret_cast<const char*>(&player.lifelines), sizeof(player.lifelines));
}

void deserializePlayer(Player& player, std::ifstream& ifs) {
    size_t nameLength;
    ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    player.name.resize(nameLength);
    ifs.read(&player.name[0], nameLength);

    size_t passwordLength;
    ifs.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
    player.password.resize(passwordLength);
    ifs.read(&player.password[0], passwordLength);

    ifs.read(reinterpret_cast<char*>(&player.totalScore), sizeof(player.totalScore));
    ifs.read(reinterpret_cast<char*>(&player.mathsScore), sizeof(player.mathsScore));
    ifs.read(reinterpret_cast<char*>(&player.historyScore), sizeof(player.historyScore));
    ifs.read(reinterpret_cast<char*>(&player.sportsScore), sizeof(player.sportsScore));
    ifs.read(reinterpret_cast<char*>(&player.riddleScore), sizeof(player.riddleScore));

    ifs.read(reinterpret_cast<char*>(&player.totalQuesCorrect), sizeof(player.totalQuesCorrect));
    ifs.read(reinterpret_cast<char*>(&player.mathsQuesCorrect), sizeof(player.mathsQuesCorrect));
    ifs.read(reinterpret_cast<char*>(&player.historyQuesCorrect), sizeof(player.historyQuesCorrect));
    ifs.read(reinterpret_cast<char*>(&player.sportsQuesCorrect), sizeof(player.sportsQuesCorrect));
    ifs.read(reinterpret_cast<char*>(&player.riddleQuesCorrect), sizeof(player.riddleQuesCorrect));

    ifs.read(reinterpret_cast<char*>(&player.lifelines), sizeof(player.lifelines));
}