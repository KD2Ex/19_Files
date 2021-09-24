#include <iostream>
#include <fstream>
using namespace std;
int main() {
    string path;
    cout << "Enter a path to the file:" << endl;
    cin >> path;
    ifstream file;
    file.open(path, ios::binary);
    if (file.is_open()) {
        char buffer[5];
        file.read(buffer, sizeof(buffer));
        if (buffer[0] == (char)-119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G'
        && path.substr(path.length() - 4,4) == ".png") {
            cout << "y";
        } else {
            cout << "n";
        }
        file.close();
    } else {
        cout << "Invalid path to the file";
    }
}
