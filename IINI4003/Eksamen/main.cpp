#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string spaces_to_underscore1(string input1) {
    replace(input1.begin(), input1.end(), ' ', '_');
    return input1;
}

void spaces_to_underscore2(string &input2) {
    replace(input2.begin(), input2.end(), ' ', '_');
}

string spaces_to_underscore_or_character(string input3, const char* chr) {
    if (chr != nullptr) {
        replace(input3.begin(), input3.end(), ' ', *chr);
    } else {
        replace(input3.begin(), input3.end(), ' ', '_');
    }
    return input3;
}

string spaces_to_underscore_or_character(string input4) {
    replace(input4.begin(), input4.end(), ' ', '_');
    return input4;
}

int main() {
    cout << "Task1" << endl;
    cout << spaces_to_underscore1("this is a string") << endl;

    string str("this is a string");
    spaces_to_underscore2(str);
    cout << str << endl;

    char chr('+');
    cout << spaces_to_underscore_or_character("this is a string", &chr) << endl;
    cout << spaces_to_underscore_or_character("this is a string", nullptr) << endl;
    cout << spaces_to_underscore_or_character("this is a string") << endl;
}
