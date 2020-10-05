#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  vector<double> douVect = {1.0, 3.0, 5.0, 7.0, 9.0};

  cout << "første element med front(): " << douVect.front() << endl;

  cout << "siste element med back(): " << douVect.back() << endl;

  double filler = 2.0;

  douVect.emplace(douVect.begin() + 1, filler);

  cout << "front() etter emplace(): " << douVect.front() << endl;

  vector<double>::iterator it = find(douVect.begin(), douVect.end(), 7);

  if (it != douVect.end()) {
    cout << "fant " << *it << endl;
  } else {
    cout << "fant ikke tallet" << endl;
  }
}
