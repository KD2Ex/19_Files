#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file;
    file.open("C:\\WEB\\.vscode\\t.txt");
    //cout << file.is_open();
    int sum = 0;
    int maxCash = 0;
    string name;
    string surname;
    string date;
    string bufName;
    string bufSurname;
    string bufDate;
    
    int cash;
    while (!file.eof()) {
        file >> bufName >> bufSurname >> cash >> bufDate;
        sum += cash;
        if (cash > maxCash) {
            maxCash = cash;
            name = bufName;
            surname = bufSurname;
            date = bufDate;
        }
    }
    cout << name << " " << surname << " " << maxCash << " " << date << endl;
    cout << sum;
    file.close();
}
