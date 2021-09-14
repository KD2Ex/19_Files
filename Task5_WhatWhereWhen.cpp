#include <iostream>
#include <fstream>
using namespace std;

void printFileContent(ifstream file[]) {
    while (!file.eof()) {
        string str;
        file >> str;
        cout << str;
    }
}

bool answer(int position, ifstream answer[]) {
    to_string(position);
    string answersPath = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\"
            + to_string(position) + ".txt";
    answer[position].open(answersPath);
    string rightAnswer;
    string playerAnswer;
    answer[position] >> rightAnswer;
    cin >> playerAnswer;
    if (playerAnswer == rightAnswer) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ifstream questions[13];
    ifstream answers[13];
    int offset;
    int position = 1;
    int expertsScore = 0;
    int viewersScore = 0;
    bool sectors[13];
    string questionsPath;
    string answersPath;

    //path = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\" + to_string(position) + ".txt";
    cout << "The game has begun!" << endl;
    while (expertsScore != 6 && viewersScore != 6) {
        cout << "Current position is " << position << endl;
        cout << "Enter the offset:";
        cin >> offset;
        position = (position + offset) % 13;
        if (position == 0) position = 13;

        questionsPath = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\"
                + to_string(position) + ".txt";
        /*answersPath = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\"
                + to_string(position) + ".txt";*/

        questions[position].open(questionsPath);
        //answers[position].open(answersPath);

        printFileContent(questions);

        cout << "Enter your answer:\n";

        if (answer(position, answers)) {
            ++expertsScore;
        } else {
            ++viewersScore;
        }
    }
}

