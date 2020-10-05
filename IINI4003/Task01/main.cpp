#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    /* Kommenter ut den oppgaven du ikke skal kjøre. */
    // a)
    /*int below = 0;
    int between = 0;
    int above = 0;
    string input;
    const int length = 5;
    for (int i = 0; i < length; ++i) {
        cout << "Temperatur nr " << i+1 << ": " << endl;
        cin >> input;
        int answer = stoi(input);
        if(answer < 10) {
            below++;
        } else if (answer < 20) {
            between++;
        } else {
            above++;
        }
    }

    cout << "Antall temperaturer under 10: " << below << endl;
    cout << "Antall temperaturer mellom 10 og 20: " << between << endl;
    cout << "Antall temperaturer over 20: " << above << endl;*/

    // b)
    const int length = 5;
    double temperatures[10]; // litt større i tilfelle det har ramlet inn ekstra tall i filen

    read_temperatures(temperatures, length);

}


void read_temperatures(double temperatures[], int length) {
    const char filename[] = "/home/dereandor/Code/IINI4003/Task01/tallfil.dat";
    ifstream file;       // definerer filvariabel
    file.open(filename); // åpner filen
    if (!file) {         // innfil kan brukes som et logisk uttrykk
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE); // uthopp fra programmet
    }

    int number;
    int sum = 0;
    int counter = 0;
    while (file >> number) {
        temperatures[counter] = number;
        counter++;
    }
    file.close();
    int below = 0;
    int between = 0;
    int above = 0;

    for (int i = 0; i < length; ++i) {
        if(temperatures[i] < 10) {
            below++;
        } else if (temperatures[i] >= 10 && temperatures[i] <= 20) {
            between++;
        } else {
            above++;
        }
    }

    cout << "Antall temperaturer under 10: " << below << endl;
    cout << "Antall temperaturer mellom 10 og 20: " << between << endl;
    cout << "Antall temperaturer over 20: " << above << endl;
}