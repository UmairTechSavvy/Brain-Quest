#include "QuestionClassPrototype&Implementation.cpp"

class QuestionInitializer{
private:
    //the general format for each nested vector of the form "CategoryLevel"
    //the first inner vector is the ith number of question
    //each ith question inner vector further consists of 4 more inner vectors
    //representing the form {{}, {}, {}, {}}
    //the first inner most vector holds the question text itself
    //the second inner most vector holds the level of difficulty of the question
    //the third inner most vector holds the 4 string answer options
    //and the fourth inner most vector holds the index of the correct answer for inner most vector number 3
    //the index is also in the form of a string, since the entire nested vector is a string
    //but when it is pushed into an object, it is forcefully converted into an integer using stoi

    vector<vector<vector<string>>> MathsEasyFiller = {
        {{"What is 5 + 3?"}, {"Easy"}, {"7", "8", "9", "10"}, {"1"}},
        {{"How many sides does a triangle have?"}, {"Easy"}, {"3", "4", "5", "6"}, {"0"}},
        {{"What is 10 divided by 2?"}, {"Easy"}, {"3", "4", "5", "6"}, {"2"}},
        {{"What is 2 multiplied by 4?"}, {"Easy"}, {"4", "6", "8", "10"}, {"2"}},
        {{"What is the next number in the sequence: 2, 4, 6, 8, ...?"}, {"Easy"}, {"10", "12", "14", "16"}, {"0"}},
        {{"What is the sum of the angles in a triangle?"}, {"Easy"}, {"90 degrees", "180 degrees", "270 degrees", "360 degrees"}, {"1"}},
        {{"What is 3 squared?"}, {"Easy"}, {"6", "8", "9", "12"}, {"2"}},
        {{"What is the perimeter of a square with each side of length 4?"}, {"Easy"}, {"12", "14", "16", "18"}, {"2"}},
        {{"How many millimeters are in a centimeter?"}, {"Easy"}, {"10", "100", "1000", "10000"}, {"0"}},
        {{"What is the smallest prime number?"}, {"Easy"}, {"1", "2", "3", "4"}, {"1"}},
        {{"How many sides does a square have?"}, {"Easy"}, {"3", "4", "5", "6"}, {"1"}},
        {{"What is 12 - 5?"}, {"Easy"}, {"4", "5", "6", "7"}, {"3"}},
        {{"What is the value of 5 + 2 * 3?"}, {"Easy"}, {"11", "13", "15", "17"}, {"0"}},
        {{"How many sides are there in a octagon?"}, {"Easy"}, {"4", "9", "8", "7"}, {"2"}},
        {{"What is the total angle of a circle?"}, {"Easy"}, {"90 degrees", "360 degrees", "180 degrees", "45 degrees"}, {"1"}}
    };


    vector<vector<vector<string>>> MathsMediumFiller = {
        {{"What is 24 divided by 3?"}, {"Medium"}, {"6", "8", "12", "4"}, {"1"}},
        {{"Simplify: 5 * (7 - 2)"}, {"Medium"}, {"20", "25", "30", "35"}, {"1"}},
        {{"What is the square root of 64?"}, {"Medium"}, {"6", "7", "8", "9"}, {"2"}},
        {{"How many sides does a hexagon have?"}, {"Medium"}, {"5", "6", "7", "8"}, {"1"}},
        {{"What is the value of 4^2?"}, {"Medium"}, {"8", "12", "14", "16"}, {"3"}},
        {{"If x = 8, what is 3x - 6?"}, {"Medium"}, {"18", "20", "22", "24"}, {"0"}},
        {{"What is 18 - 9?"}, {"Medium"}, {"6", "7", "8", "9"}, {"3"}},
        {{"What is the sum of the total sides of a shape called?"}, {"Medium"}, {"Radius", "Distance", "Diameter", "Perimeter"}, {"3"}},
        {{"The opposite of discrete mathematics is?"}, {"Medium"}, {"Calculus", "Integration", "CS", "Physics"}, {"0"}},
        {{"What is the principle of mathematical induction used for?"}, {"Medium"}, {"Proving theorems", "Calculating integrals", "Finding limits", "Solving differential equations"}, {"0"}},
        {{"Which of the following is a fundamental concept in calculus?"}, {"Medium"}, {"Graph theory", "Combinatorics", "Limits", "Cryptography"}, {"2"}},
        {{"What is the discrete analog of differentiation?"}, {"Medium"}, {"Summation", "Recurrence relation", "Graph traversal", "Permutation"}, {"1"}},
        {{"Which of these is a common method for finding the area under a curve?"}, {"Medium"}, {"Summation", "Recursion", "Integration", "Differentiation"}, {"2"}},
        {{"Which branch of mathematics deals with the study of graphs?"}, {"Medium"}, {"Calculus", "Combinatorics", "Graph theory", "Topology"}, {"2"}},
        {{"Which of the following is used to find the derivative of a function?"}, {"Medium"}, {"Integration", "Differentiation", "Summation", "Recursion"}, {"1"}}
    };


    vector<vector<vector<string>>> MathsHardFiller = {
        {{"What is the largest prime number less than 20?"}, {"Hard"}, {"17", "19", "21", "23"}, {"1"}},
        {{"Simplify: (8 + 2) * (6 - 3)"}, {"Hard"}, {"30", "36", "42", "48"}, {"0"}},
        {{"What is the cube root of 125?"}, {"Hard"}, {"5", "10", "15", "20"}, {"0"}},
        {{"What is the area of a rectangle with length 12 and width 5?"}, {"Hard"}, {"50", "55", "60", "65"}, {"2"}},
        {{"If a train travels at 80 km/h, how far will it travel in 2.5 hours?"}, {"Hard"}, {"180 km", "200 km", "220 km", "240 km"}, {"1"}},
        {{"Evaluate the limit: lim(x *tends to* 0) (sin(x)/x)."}, {"Hard"}, {"0", "1", "Infinity", "Undefined"}, {"1"}},
        {{"What is the chromatic number of a cycle graph with an odd number of vertices?"}, {"Hard"}, {"1", "2", "3", "4"}, {"2"}},
        {{"If f(x) = ln(x^2), what is f'(x)?"}, {"Hard"}, {"1/x", "2/x", "2/x^2", "x ln(x)"}, {"1"}},
        {{"How many spanning trees does a complete graph with 4 vertices (K4) have?"}, {"Hard"}, {"4", "8", "16", "64"}, {"2"}},
        {{"What is the value of the infinite series summation(n=1 to infinity) 1/n^2?"}, {"Hard"}, {"pi^2/6", "pi^2/4", "e", "2"}, {"0"}},
        {{"Solve for x in the equation 2^x = 32."}, {"Hard"}, {"3", "4", "5", "6"}, {"2"}},
        {{"What is the Big-O notation for the function f(n) = n log n + n^2?"}, {"Hard"}, {"O(n)", "O(n log n)", "O(n^2)", "O(n^2 log n)"}, {"3"}},
        {{"Solve the recurrence relation T(n) = 2T(n/2) + n."}, {"Hard"}, {"O(n)", "O(n log n)", "O(n^2)", "O(log n)"}, {"1"}},
        {{"Evaluate the determinant of the matrix [[1, 2], [3, 4]]."}, {"Hard"}, {"-2", "2", "5", "-1"}, {"0"}},
        {{"Find the derivative of f(x) = x^x."}, {"Hard"}, {"x^x * (ln(x) + 1)", "x^(x-1)", "x^x * ln(x)", "x^(x+1)"}, {"0"}}
    };


    vector<vector<vector<string>>> SportsEasyFiller = {
        {{"Which Pakistani cricketer is known as the 'Sultan of Swing'?"}, {"Easy"}, {"Imran Khan", "Wasim Akram", "Shoaib Akhtar", "Waqar Younis"}, {"1"}},
        {{"Who won the 2019 ICC Cricket World Cup?"}, {"Easy"}, {"India", "Australia", "England", "New Zealand"}, {"2"}},
        {{"Which Pakistani cricketer has the highest number of Test wickets?"}, {"Easy"}, {"Wasim Akram", "Waqar Younis", "Shoaib Akhtar", "Yasir Shah"}, {"0"}},
        {{"Who won the FIFA World Cup in 2018?"}, {"Easy"}, {"Brazil", "Germany", "France", "Argentina"}, {"2"}},
        {{"Who is the captain of the Pakistan national cricket team as of 2023?"}, {"Easy"}, {"Babar Azam", "Sarfraz Ahmed", "Mohammad Rizwan", "Shaheen Afridi"}, {"0"}},
        {{"Which country has won the most FIFA World Cups?"}, {"Easy"}, {"Germany", "Italy", "Brazil", "Argentina"}, {"2"}},
        {{"Which Pakistani cricketer scored a century on his Test debut?"}, {"Easy"}, {"Inzamam-ul-Haq", "Babar Azam", "Fawad Alam", "Mohammad Hafeez"}, {"2"}},
        {{"Which country won the ICC T20 World Cup in 2021?"}, {"Easy"}, {"India", "Australia", "England", "Pakistan"}, {"1"}},
        {{"Who is the leading run-scorer in international cricket?"}, {"Easy"}, {"Ricky Ponting", "Sachin Tendulkar", "Brian Lara", "Virat Kohli"}, {"1"}},
        {{"Which Pakistani bowler is famous for his hat-trick in the 2019 World Cup?"}, {"Easy"}, {"Mohammad Amir", "Shaheen Afridi", "Hasan Ali", "Wahab Riaz"}, {"1"}},
        {{"Which team won the UEFA Champions League in 2021?"}, {"Easy"}, {"Real Madrid", "Barcelona", "Chelsea", "Manchester City"}, {"2"}},
        {{"Who holds the record for the most goals in a calendar year?"}, {"Easy"}, {"Cristiano Ronaldo", "Lionel Messi", "Neymar", "Robert Lewandowski"}, {"1"}},
        {{"Who is known as the 'Little Master' in cricket?"}, {"Easy"}, {"Sunil Gavaskar", "Virat Kohli", "Sachin Tendulkar", "Ricky Ponting"}, {"2"}},
        {{"Which country hosted the 2019 ICC Cricket World Cup?"}, {"Easy"}, {"England", "Australia", "India", "South Africa"}, {"0"}},
        {{"Who is the top goal scorer in the history of the FIFA World Cup?"}, {"Easy"}, {"Pele", "Diego Maradona", "Miroslav Klose", "Cristiano Ronaldo"}, {"2"}}

    };


    vector<vector<vector<string>>> SportsMediumFiller = {
        {{"Who won the ICC Cricket World Cup in 2015?"}, {"Medium"}, {"Australia", "India", "England", "New Zealand"}, {"0"}},
        {{"Which boxer is known for his nickname 'Money'?"}, {"Medium"}, {"Floyd Mayweather", "Manny Pacquiao", "Mike Tyson", "Muhammad Ali"}, {"0"}},
        {{"In which year did England win their first and only FIFA World Cup?"}, {"Medium"}, {"1966", "1970", "1958", "1982"}, {"0"}},
        {{"Who is the current captain of the Indian cricket team in all formats?"}, {"Medium"}, {"Virat Kohli", "Rohit Sharma", "Ajinkya Rahane", "Ravindra Jadeja"}, {"0"}},
        {{"Which footballer holds the record for the most goals scored in a single FIFA World Cup tournament?"}, {"Medium"}, {"Pele", "Just Fontaine", "Gerd Muller", "Diego Maradona"}, {"1"}},
        {{"Which country won the ICC T20 World Cup in 2016?"}, {"Medium"}, {"West Indies", "India", "England", "Australia"}, {"0"}},
        {{"Who was the first boxer to hold world titles in five weight classes?"}, {"Medium"}, {"Floyd Mayweather", "Manny Pacquiao", "Oscar De La Hoya", "Sugar Ray Leonard"}, {"3"}},
        {{"Which cricketer holds the record for the highest individual score in Test cricket?"}, {"Medium"}, {"Brian Lara", "Sachin Tendulkar", "Virender Sehwag", "David Warner"}, {"0"}},
        {{"In which city is the headquarters of the International Boxing Federation (IBF) located?"}, {"Medium"}, {"London", "New York", "Lausanne", "Zurich"}, {"2"}},
        {{"Who won the UEFA Euro 2020 Championship?"}, {"Medium"}, {"England", "Italy", "Portugal", "Spain"}, {"1"}},
        {{"Which footballer has won the most Ballon d'Or awards?"}, {"Medium"}, {"Lionel Messi", "Cristiano Ronaldo", "Michel Platini", "Johan Cruyff"}, {"0"}},
        {{"Who is the only male boxer to win world titles in eight different weight divisions?"}, {"Medium"}, {"Manny Pacquiao", "Floyd Mayweather", "Oscar De La Hoya", "Sugar Ray Leonard"}, {"0"}},
        {{"Which cricketer holds the record for the fastest century in One Day Internationals (ODIs)?"}, {"Medium"}, {"AB de Villiers", "Chris Gayle", "Shahid Afridi", "Rohit Sharma"}, {"0"}},
        {{"Who won the FIFA World Cup Golden Boot in 2014?"}, {"Medium"}, {"Thomas Muller", "Lionel Messi", "Neymar", "James Rodriguez"}, {"3"}},
        {{"Which boxer famously defeated Mike Tyson in 1990 for the undisputed heavyweight championship?"}, {"Medium"}, {"Evander Holyfield", "Lennox Lewis", "Buster Douglas", "George Foreman"}, {"2"}}
    };


    vector<vector<vector<string>>> SportsHardFiller = {
        {{"Which club has won the most UEFA Champions League titles?"}, {"Hard"}, {"Real Madrid", "FC Barcelona", "Bayern Munich", "Liverpool"}, {"0"}},
        {{"Who was the top scorer of the UEFA Champions League in the 2020-2021 season?"}, {"Hard"}, {"Erling Haaland", "Robert Lewandowski", "Lionel Messi", "Kylian Mbappé"}, {"1"}},
        {{"In which year did Italy win their most recent FIFA World Cup?"}, {"Hard"}, {"2006", "2010", "2014", "2018"}, {"0"}},
        {{"Which player has won the FIFA World Cup Golden Boot award twice?"}, {"Hard"}, {"Pelé", "Diego Maradona", "Ronaldo", "Thomas Müller"}, {"2"}},
        {{"Which nation won the FIFA World Cup in 1998?"}, {"Hard"}, {"Brazil", "Argentina", "France", "Germany"}, {"2"}},
        {{"Who is the all-time top scorer in the history of the UEFA Champions League?"}, {"Hard"}, {"Lionel Messi", "Cristiano Ronaldo", "Raúl", "Karim Benzema"}, {"1"}},
        {{"Which country hosted the FIFA World Cup in 2014?"}, {"Hard"}, {"Brazil", "Germany", "Russia", "South Africa"}, {"0"}},
        {{"Which club won the UEFA Champions League in the 2018-2019 season?"}, {"Hard"}, {"Real Madrid", "Liverpool", "Bayern Munich", "Barcelona"}, {"0"}},
        {{"Who won the FIFA World Cup Golden Ball in 2010?"}, {"Hard"}, {"Lionel Messi", "Andrés Iniesta", "Thomas Müller", "Diego Forlán"}, {"1"}},
        {{"Which player scored the 'Hand of God' goal in the 1986 FIFA World Cup?"}, {"Hard"}, {"Lionel Messi", "Diego Maradona", "Pelé", "Zinedine Zidane"}, {"1"}},
        {{"In which year did Germany win their most recent FIFA World Cup?"}, {"Hard"}, {"2006", "2010", "2014", "2018"}, {"2"}},
        {{"Which club won the UEFA Champions League three consecutive times from 2016 to 2018?"}, {"Hard"}, {"Real Madrid", "FC Barcelona", "Bayern Munich", "Liverpool"}, {"0"}},
        {{"Who scored the winning goal for Spain in the 2010 FIFA World Cup final?"}, {"Hard"}, {"Andres Iniesta", "Xavi Hernandez", "David Villa", "Fernando Torres"}, {"0"}},
        {{"Which nation won the FIFA World Cup in 1966?"}, {"Hard"}, {"England", "Brazil", "Germany", "Italy"}, {"0"}},
        {{"Who holds the record for the most assists in a single UEFA Champions League season?"}, {"Hard"}, {"Lionel Messi", "Neymar", "Kevin De Bruyne", "Angel Di María"}, {"2"}}
    };


    vector<vector<vector<string>>> HistoryEasyFiller = {
        {{"Who led the Indian independence movement against British rule?"}, {"Easy"}, {"Mahatma Gandhi", "Jawaharlal Nehru", "Subhas Chandra Bose", "Sardar Patel"}, {"0"}},
        {{"In which year did India gain independence from British rule?"}, {"Easy"}, {"1947", "1950", "1945", "1960"}, {"0"}},
        {{"Who was the first Prime Minister of Pakistan?"}, {"Easy"}, {"Muhammad Ali Jinnah", "Liaquat Ali Khan", "Zulfikar Ali Bhutto", "Pervez Musharraf"}, {"1"}},
        {{"Which war resulted in the independence of Bangladesh from Pakistan?"}, {"Easy"}, {"Indo-Pakistani War of 1947", "Indo-Pakistani War of 1965", "Indo-Pakistani War of 1971", "Kargil War"}, {"2"}},
        {{"Who was the leader of the Indian National Congress during India's independence movement?"}, {"Easy"}, {"Jawaharlal Nehru", "Sardar Patel", "Subhas Chandra Bose", "Mahatma Gandhi"}, {"3"}},
        {{"Which agreement resulted in the division of British India into India and Pakistan?"}, {"Easy"}, {"Lahore Resolution", "Treaty of Amritsar", "Mountbatten Plan", "Simla Agreement"}, {"2"}},
        {{"Which British viceroy announced the partition of India in 1947?"}, {"Easy"}, {"Lord Mountbatten", "Lord Curzon", "Lord Wavell", "Lord Irwin"}, {"0"}},
        {{"Who was the first President of independent India?"}, {"Easy"}, {"Jawaharlal Nehru", "Sardar Patel", "Dr. Rajendra Prasad", "Indira Gandhi"}, {"2"}},
        {{"In which year did Pakistan become a republic?"}, {"Easy"}, {"1956", "1947", "1962", "1971"}, {"0"}},
        {{"Which war between India and Pakistan took place in 1965?"}, {"Easy"}, {"Indo-Pakistani War of 1947", "Indo-Pakistani War of 1965", "Indo-Pakistani War of 1971", "Kargil War"}, {"1"}},
        {{"Who was the last Viceroy of India?"}, {"Easy"}, {"Lord Mountbatten", "Lord Curzon", "Lord Wavell", "Lord Irwin"}, {"0"}},
        {{"Which event led to the end of British rule in India?"}, {"Easy"}, {"Quit India Movement", "Dandi March", "Jallianwala Bagh massacre", "Chauri Chaura incident"}, {"0"}},
        {{"Who was the first Prime Minister of India?"}, {"Easy"}, {"Mahatma Gandhi", "Jawaharlal Nehru", "Sardar Patel", "Indira Gandhi"}, {"1"}},
        {{"Which country was partitioned to create Pakistan in 1947?"}, {"Easy"}, {"India", "Afghanistan", "Bangladesh", "British India"}, {"3"}},
        {{"Which famous speech by Jawaharlal Nehru marked India's independence?"}, {"Easy"}, {"Quit India speech", "Tryst with Destiny speech", "Dandi March speech", "Round Table Conference speech"}, {"1"}}
    };


    vector<vector<vector<string>>> HistoryMediumFiller = {
        {{"Who was the first President of Pakistan?"}, {"Medium"}, {"Liaquat Ali Khan", "Ayub Khan", "Muhammad Ali Jinnah", "Zulfikar Ali Bhutto"}, {"0"}},
        {{"Which movement was led by Subhas Chandra Bose to liberate India from British rule during World War II?"}, {"Medium"}, {"Quit India Movement", "Dandi March", "Azad Hind Fauj", "Khilafat Movement"}, {"2"}},
        {{"Who coined the term 'Two-Nation Theory' which eventually led to the partition of India?"}, {"Medium"}, {"Jawaharlal Nehru", "Mohammad Ali Jinnah", "Mahatma Gandhi", "Sardar Patel"}, {"1"}},
        {{"Which British viceroy announced the partition plan of India in 1947?"}, {"Medium"}, {"Lord Mountbatten", "Lord Curzon", "Lord Wavell", "Lord Irwin"}, {"0"}},
        {{"Who was the first Prime Minister of Pakistan?"}, {"Medium"}, {"Liaquat Ali Khan", "Ayub Khan", "Muhammad Ali Jinnah", "Zulfikar Ali Bhutto"}, {"0"}},
        {{"Which war between India and Pakistan was sparked by the infiltration of Pakistani soldiers disguised as militants into Kargil?"}, {"Medium"}, {"Indo-Pakistani War of 1947", "Indo-Pakistani War of 1965", "Indo-Pakistani War of 1971", "Kargil War"}, {"3"}},
        {{"Which agreement led to the creation of Bangladesh as a separate nation in 1971?"}, {"Medium"}, {"Simla Agreement", "Lahore Agreement", "Tashkent Agreement", "Shimla Agreement"}, {"0"}},
        {{"Who led the Indian National Army (INA) during World War II?"}, {"Medium"}, {"Mahatma Gandhi", "Subhas Chandra Bose", "Jawaharlal Nehru", "Sardar Patel"}, {"1"}},
        {{"Which Indian leader famously gave the 'Tryst with Destiny' speech on the eve of independence?"}, {"Medium"}, {"Mahatma Gandhi", "Jawaharlal Nehru", "Sardar Patel", "Indira Gandhi"}, {"1"}},
        {{"Who wrote the Declaration of Independence of the United States?"}, {"Medium"}, {"Thomas Jefferson", "George Washington", "John Adams", "Benjamin Franklin"}, {"0"}},
        {{"In which year did the American colonies declare independence from Great Britain?"}, {"Medium"}, {"1776", "1789", "1800", "1812"}, {"0"}},
        {{"Which battle is considered a turning point in the American Revolutionary War?"}, {"Medium"}, {"Battle of Yorktown", "Battle of Bunker Hill", "Battle of Lexington and Concord", "Battle of Saratoga"}, {"0"}},
        {{"Who was the British monarch during the American Revolution?"}, {"Medium"}, {"King George III", "King George II", "King George IV", "King George V"}, {"0"}},
        {{"Which treaty formally ended the American Revolutionary War?"}, {"Medium"}, {"Treaty of Paris (1783)", "Treaty of Versailles (1789)", "Treaty of London (1781)", "Treaty of Vienna (1785)"}, {"0"}},
        {{"Which document established the first permanent English settlement in North America?"}, {"Medium"}, {"Mayflower Compact", "Jamestown Charter", "Fundamental Orders of Connecticut", "Virginia Declaration of Rights"}, {"1"}}
    };


    vector<vector<vector<string>>> HistoryHardFiller = {
        {{"Who was the Commander-in-Chief of the Indian Army during the Indo-Pakistani War of 1971?"}, {"Hard"}, {"General Sam Manekshaw", "General J. N. Chaudhuri", "General K. M. Cariappa", "General Bipin Rawat"}, {"0"}},
        {{"Which event is associated with the assassination of Mahatma Gandhi?"}, {"Hard"}, {"Jallianwala Bagh massacre", "Quit India Movement", "Dandi March", "Birla House assassination"}, {"3"}},
        {{"Who was the Governor-General of India during the First War of Indian Independence in 1857?"}, {"Hard"}, {"Lord Dalhousie", "Lord Canning", "Lord Curzon", "Lord Mountbatten"}, {"1"}},
        {{"Which British Prime Minister announced the independence of India in 1947?"}, {"Hard"}, {"Winston Churchill", "Clement Attlee", "Neville Chamberlain", "Harold Macmillan"}, {"1"}},
        {{"Which American document precedes the Declaration of Independence and emphasizes the rights of individuals?"}, {"Hard"}, {"Mayflower Compact", "Magna Carta", "Virginia Declaration of Rights", "Articles of Confederation"}, {"2"}},
        {{"Who was the last Mughal Emperor of India?"}, {"Hard"}, {"Bahadur Shah II", "Akbar II", "Shah Alam II", "Aurangzeb"}, {"0"}},
        {{"Which British general surrendered to American forces at the Battle of Yorktown?"}, {"Hard"}, {"General William Howe", "General John Burgoyne", "General Charles Cornwallis", "General Thomas Gage"}, {"2"}},
        {{"Which American founding father is known for writing the Federalist Papers with James Madison and John Jay?"}, {"Hard"}, {"Alexander Hamilton", "Thomas Jefferson", "Benjamin Franklin", "George Washington"}, {"0"}},
        {{"Who was the British Prime Minister during the American Revolutionary War?"}, {"Hard"}, {"Lord North", "William Pitt the Younger", "Robert Walpole", "George Grenville"}, {"0"}},
        {{"Which British official was responsible for the implementation of the partition plan of India in 1947?"}, {"Hard"}, {"Lord Mountbatten", "Lord Attlee", "Lord Radcliffe", "Lord Curzon"}, {"2"}},
        {{"Which American president was in office during the Mexican-American War?"}, {"Hard"}, {"James K. Polk", "Andrew Jackson", "Abraham Lincoln", "Thomas Jefferson"}, {"0"}},
        {{"Who was the President of the Continental Congress when the Declaration of Independence was adopted?"}, {"Hard"}, {"John Adams", "George Washington", "Thomas Jefferson", "Benjamin Franklin"}, {"0"}},
        {{"Which battle during the American Civil War is known as the turning point in favor of the Union forces?"}, {"Hard"}, {"Battle of Gettysburg", "Battle of Antietam", "Battle of Vicksburg", "Battle of Chickamauga"}, {"0"}},
        {{"Who was the first President of the United States to be impeached?"}, {"Hard"}, {"Andrew Johnson", "Richard Nixon", "Bill Clinton", "Donald Trump"}, {"0"}},
        {{"Which treaty ended the War of 1812 between the United States and Great Britain?"}, {"Hard"}, {"Treaty of Ghent", "Treaty of Paris (1783)", "Treaty of Versailles (1783)", "Treaty of London (1814)"}, {"0"}}
    };

    vector<vector<vector<string>>> RiddleEasyFiller = {
        {{"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"}, {"Easy"}, {"Echo", "Shadow", "Light", "Fire"}, {"0"}},
        {{"Im tall when I'm young, and I'm short when I'm old. What am I?"}, {"Easy"}, {"Tree", "Candle", "Building", "Mountain"}, {"1"}},
        {{"What has keys but can't open locks?"}, {"Easy"}, {"Piano", "Map", "Book", "Wallet"}, {"0"}},
        {{"What gets wetter as it dries?"}, {"Easy"}, {"Sponge", "Towel", "Paper", "Cloth"}, {"1"}},
        {{"The more of this there is, the less you see. What is it?"}, {"Easy"}, {"Light", "Fog", "Darkness", "Water"}, {"2"}},
        {{"What can travel around the world while staying in a corner?"}, {"Easy"}, {"Stamp", "Sun", "Bird", "Plane"}, {"0"}},
        {{"What has a heart that doesn't beat?"}, {"Easy"}, {"Robot", "Tree", "Rock", "Computer"}, {"1"}},
        {{"What has a neck but no head?"}, {"Easy"}, {"Bottle", "River", "Clock", "Chair"}, {"0"}},
        {{"I'm not alive, but I can grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?"}, {"Easy"}, {"Rock", "Plant", "Fire", "Cloud"}, {"2"}},
        {{"What comes once in a minute, twice in a moment, but never in a thousand years?"}, {"Easy"}, {"Sun", "Moon", "Star", "Letter M"}, {"3"}},
        {{"What has to be broken before you can use it?"}, {"Easy"}, {"Egg", "Seed", "Glass", "Stick"}, {"0"}},
        {{"What is full of holes but still holds water?"}, {"Easy"}, {"Net", "Sponge", "Basket", "Pipe"}, {"1"}},
        {{"What has a face and two hands, but no arms or legs?"}, {"Easy"}, {"Clock", "Mannequin", "Mirror", "Robot"}, {"0"}},
        {{"What has keys that open no locks, but space can be entered?"}, {"Easy"}, {"Keyboard", "Calculator", "Typewriter", "Phone"}, {"2"}},
        {{"What runs but never walks, has a bed but never sleeps?"}, {"Easy"}, {"River", "Car", "Train", "Road"}, {"0"}}
    };


    vector<vector<vector<string>>> RiddleMediumFiller = {
        {{"I have cities, but no houses. I have mountains, but no trees. I have water, but no fish. What am I?"}, {"Medium"}, {"Map", "Globe", "Dictionary", "Atlas"}, {"1"}},
        {{"What has keys that open no locks, but space can be entered?"}, {"Medium"}, {"Keyboard", "Calculator", "Typewriter", "Phone"}, {"0"}},
        {{"What can be cracked, made, told, and played?"}, {"Medium"}, {"Egg", "Joke", "Story", "Music"}, {"1"}},
        {{"The more you take, the more you leave behind. What am I?"}, {"Medium"}, {"Footsteps", "Memories", "Road", "Time"}, {"0"}},
        {{"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?"}, {"Medium"}, {"Echo", "Shadow", "Light", "Fire"}, {"0"}},
        {{"I have keys but open no locks. I have space but no room. You can enter, but you can't go outside. What am I?"}, {"Medium"}, {"Computer", "Keyboard", "Calculator", "Typewriter"}, {"1"}},
        {{"I have rivers, but no water. I have cities, but no buildings. I have forests, but no trees. What am I?"}, {"Medium"}, {"Map", "Globe", "Atlas", "Dictionary"}, {"0"}},
        {{"I'm not alive, but I can grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?"}, {"Medium"}, {"Rock", "Plant", "Fire", "Cloud"}, {"2"}},
        {{"What has one eye but can't see?"}, {"Medium"}, {"Cyclops", "Needle", "Storm", "Camera"}, {"1"}},
        {{"What has keys but can't open locks?"}, {"Medium"}, {"Piano", "Map", "Book", "Wallet"}, {"0"}},
        {{"What is so fragile that saying its name breaks it?"}, {"Medium"}, {"Silence", "Ice", "Whisper", "Mirror"}, {"0"}},
        {{"What begins with T, ends with T, and has T in it?"}, {"Medium"}, {"Teapot", "Tunnel", "Tower", "Twilight"}, {"1"}},
        {{"What has a neck but no head?"}, {"Medium"}, {"Bottle", "River", "Clock", "Chair"}, {"0"}},
        {{"What comes down but never goes up?"}, {"Medium"}, {"Rain", "Night", "Temperature", "Hair"}, {"0"}},
        {{"What has a face and two hands, but no arms or legs?"}, {"Medium"}, {"Clock", "Mannequin", "Mirror", "Robot"}, {"0"}}
    };


    vector<vector<vector<string>>> RiddleHardFiller = {
        {{"Forward I am heavy, but backward I am not. What am I?"}, {"Hard"}, {"Ton", "Not", "Lead", "Weight"}, {"1"}},
        {{"What has keys that open no locks, but space can be entered?"}, {"Hard"}, {"Keyboard", "Calculator", "Typewriter", "Phone"}, {"2"}},
        {{"I can be cracked, made, told, and played. What am I?"}, {"Hard"}, {"Joke", "Music", "Egg", "Game"}, {"0"}},
        {{"What has a head, a tail, but no body?"}, {"Hard"}, {"Coin", "Snake", "Comet", "Mushroom"}, {"0"}},
        {{"What can be seen once in a minute, twice in a moment, and never in a thousand years?"}, {"Hard"}, {"Star", "Lightning", "Letter M", "Hope"}, {"2"}},
        {{"What comes once in a minute, twice in a moment, but never in a thousand years?"}, {"Hard"}, {"Sun", "Moon", "Star", "Letter M"}, {"3"}},
        {{"What has keys that open no locks, space can be entered, but you can't go outside?"}, {"Hard"}, {"Keyboard", "Calculator", "Typewriter", "Phone"}, {"2"}},
        {{"What has four fingers and a thumb, but is not living?"}, {"Hard"}, {"Glove", "Mitten", "Fist", "Puppet"}, {"0"}},
        {{"I have keys but open no locks, I have space but no room. What am I?"}, {"Hard"}, {"Keyboard", "Calculator", "Typewriter", "Phone"}, {"2"}},
        {{"What has rivers but no water, cities but no buildings, and forests but no trees?"}, {"Hard"}, {"Map", "Globe", "Dictionary", "Atlas"}, {"0"}},
        {{"What has a head and a tail but no body?"}, {"Hard"}, {"Coin", "Fish", "Snake", "Comet"}, {"0"}},
        {{"What begins with T, ends with T, and has T in it?"}, {"Hard"}, {"Teapot", "Tunnel", "Tower", "Twilight"}, {"1"}},
        {{"What has one eye but cannot see?"}, {"Hard"}, {"Needle", "Cyclops", "Storm", "Peephole"}, {"1"}},
        {{"I'm light as a feather, yet the strongest person can't hold me for much longer than a minute. What am I?"}, {"Hard"}, {"Breath", "Thought", "Whisper", "Dream"}, {"0"}},
        {{"What is so fragile that saying its name breaks it?"}, {"Hard"}, {"Silence", "Ice", "Whisper", "Mirror"}, {"0"}}
    };


public:
    void initializeMathsQuestions(vector<Maths> &easy, vector<Maths> &medium, vector<Maths> &hard);
    void initializeSportsQuestions(vector<Sports> &easy, vector<Sports> &medium, vector<Sports> &hard);
    void initializeHistoryQuestions(vector<History> &easy, vector<History> &medium, vector<History> &hard);
    void initializeRiddleQuestions(vector<Riddle> &easy, vector<Riddle> &medium, vector<Riddle> &hard);
};
