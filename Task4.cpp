#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file;
    char buffer[5];
    string path;
    cin >> path;
    file.open(path, ios::binary);
    file.read(buffer, sizeof(buffer));
    buffer[4] = 0;
    if (buffer[0] == (char)-119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
        cout << "y";
    } else {
        cout << "n";
    }
    file.close();
}
