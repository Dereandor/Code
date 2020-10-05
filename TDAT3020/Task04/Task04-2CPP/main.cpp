#include <iostream>

using namespace std;

string replace(string input) {
    size_t pos = input.find("&");
    while(input.find("&", pos) != string::npos) {
        input = input.replace(pos, 1, "&amp");
        pos = input.find("&", pos+1);
    }
    pos = input.find("<");
    while(input.find("<", pos) != string::npos) {
        input = input.replace(pos, 1, "&lt");
        pos = input.find("<", pos + 1);
    }
    pos = input.find(">");
    while(input.find(">", pos) != string::npos) {
        input = input.replace(pos, 1, "&gt");
        pos = input.find(">", pos + 1);
    }
    return input;
}

int main() {
    string str = "Hello & welcome < user >";
    cout << str << endl;
    cout << replace(str) << endl;
}
