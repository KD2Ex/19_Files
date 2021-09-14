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
    while (!file.eof()) {
        file.read(buffer, sizeof(buffer) - 1);
        buffer[19] = 0;
        if (file.gcount() != 19) {
            for (int i = file.gcount(); i < 19; ++i) {
                buffer[i] = 0;
            }
        }
        cout << buffer;
    }

    file.close();
}