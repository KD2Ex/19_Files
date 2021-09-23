#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream words;
    words.open("words.txt");
    if (!words.is_open()) {
        cout << "Invalid file path" << endl;
    } else {
        string str;
        cout << "Enter a word to find in text:\n";
        cin >> str;
        int count = 0;
        while (!words.eof()) {
            string word;
            words >> word;
            if (word == str) ++count;
        }
        cout << "The word appears in the text " << count << " times.";
        words.close();
    }
}
