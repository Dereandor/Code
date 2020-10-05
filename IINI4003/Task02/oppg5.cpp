#include <iostream>

using namespace std;

int main() {
    double number = 1;
    double &ref = number;
    double *point = &number; 

    cout << "utgangspunkt: " << number << endl;

    //first method
    *point = 2;
    cout << "første metode: " << number << endl;

    //second method
    ref = 3;
    cout << "andre metode: " << number << endl;

    //third method
    point[0] = 4;
    cout << "tredje metode: " << number << endl;

}