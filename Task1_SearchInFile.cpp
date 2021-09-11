#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string str;
    cin >> str;
    ifstream words;
    words.open("W:\\CLionProjects\\Skillbox\\19_Files\\words.txt");
    int count = 0;
    while (!words.eof()) {
        string word;
        words >> word;
        if (word == str) ++count;
    }
    cout << count;
    words.close();
}
