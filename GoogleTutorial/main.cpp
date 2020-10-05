#include <iostream>
#include <time.h>

using namespace std;


int main() {
    int Secret, guess;

    //Initialize random seed
    srand (time(NULL));

    //Generate random number between 1 and 100
    Secret = rand() % 100 + 1;

    cout << "Guess our number (1-100)" << endl;
    if (!(cin >> guess)) {
        cout << "Please enter only numbers" << endl;
    } else {
        if (Secret < guess) cout << "The secret number is lower than " << guess << endl;
        else if (Secret > guess) cout << "The secret number is higher than " << guess << endl;
        else cout << "You guessed it!: " << Secret << endl;
    }

    cout << "Your random number is: " << Secret << endl;

    return 0;
}
