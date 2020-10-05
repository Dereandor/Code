#include <iostream>

using namespace std;

int find_sum(const int *table, int length) 
{
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        counter += table[i];
    }
    return counter;
}

int main() {
    int number = 20;
    int table[number];

    for (int i = 0; i < number; i++)
    {
        table[i] = (i+1);
    }

    int firstTen = find_sum(table, 10);
    int nextFive = find_sum(&table[10], 5);
    int lastFive = find_sum(&table[15], 5);

    cout << firstTen << endl;
    cout << nextFive << endl;
    cout << lastFive << endl;
    
}