#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int &b = a; //må ha en verdi
    int *c;
    c = &b;
    a = b + *c; //a er en int, ikke en referanse og b er en peker, ikke en referanse
    b = 2; //b er fortsatt ikke en referanse.
}

