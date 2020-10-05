#include <iostream>

using namespace std;

int main(){
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Adressen til i er: " << &i << endl;
    cout << "Adressen til pekeren til i er: " << p << endl;
    cout << "Adressen til j er: " << &j << endl;
    cout << "Adressen til pekeren til j er: " << q << endl;

    cout << "Verdien til i er: " << i << endl;
    cout << "Verdien til pekeren til i er: " << *p << endl;
    cout << "Verdien til j er: " << j << endl;
    cout << "Verdien til pekeren til j er: " << *q << endl;

    //Oppgave b
    *p = 7; // p = 7, q = 5
    *q += 4; //p = 7, q = 9
    *q = *p + 1; //p = 7, q = 8
    p = q; //p = 8, q = 8
    cout << *p << " " << *q << endl; // Dette skal skrive ut 8 8
}