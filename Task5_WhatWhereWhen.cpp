#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void printFileContent(ifstream &file) {
    char buffer[6];
    while (!file.eof()) {
        file.read(buffer, sizeof(buffer) - 1);
        buffer[5] = 0;
        if (file.gcount() != 5) {
            for (int  i = file.gcount();  i < 5; ++ i) {
                buffer[i] = 0;
            }
        }
        cout << buffer;
    }
}

bool answer(ifstream &answer) {
    string rightAnswer;
    string playerAnswer;
    answer >> rightAnswer;
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

    for (int i = 0; i < 13; ++i) {
        sectors[i] = true;
    }
    //path = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\" + to_string(position) + ".txt";
    cout << "The game has begun!" << endl;
    while (expertsScore < 6 && viewersScore < 6) {
        cout << "Current position is " << position << endl;
        cout << "Enter the offset:";
        cin >> offset;
        if (position + offset == 13) {
            position += offset;
        } else {
            position = (position + offset) % 13;
            if (position == 0) position = 13;
        }

        while (sectors[position - 1] != true) {
            ++position;
        }

        questionsPath = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Questions\\"
                + to_string(position) + ".txt";
        answersPath = "W:\\CLionProjects\\Skillbox\\19_Files\\TheGame\\Answers\\"
                + to_string(position) + ".txt";

        questions[position - 1].open(questionsPath);
        answers[position - 1].open(answersPath);

        printFileContent(questions[position]);

        cout << "Enter your answer:\n";

        if (answer(answers[position])) {
            ++expertsScore;
        } else {
            ++viewersScore;
        }
        cout << "Current state is " << expertsScore << ":" << viewersScore << endl;
        sectors[position - 1] = false;
        questions[position].close();
        answers[position].close();
    }
}

