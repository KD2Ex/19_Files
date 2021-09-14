#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string str;
    cout << "Enter a word to find in text:\n";
    cin >> str;
    ifstream words;
    words.open("W:\\CLionProjects\\Skillbox\\19_Files\\words.txt");
    int count = 0;
    while (!words.eof()) {
        string word;
        words >> word;
        if (word == str) ++count;
    }
    cout << "The word appears in the text " << count << " times.";
    words.close();
}
