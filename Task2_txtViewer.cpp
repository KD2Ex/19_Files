#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string path;
    ifstream file;
    char buffer[20];
    cout << "Enter a path to the file\n";
    cin >> path;
    file.open(path);
    if (file.is_open()) {
        while (!file.eof()) {
            file.read(buffer, sizeof(buffer) - 1);
            buffer[file.gcount()] = 0;
            cout << buffer;
        }
        file.close();
    } else {
        cout << "Invalid path file";
    }   
}
