#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table) {
    out << e << " ";
  }
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;

  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  //oppgave A
  vector<int>::iterator it = find_if(v1.begin(), v1.end(), [](const int &e) {
    if (e > 15) {
      return true;
    }
    return false;
  });
  cout << "første element større enn 15: " << *it << endl;

  //oppgave B
  bool equal_5 = equal(v1.begin(), v1.begin() + 5, v2.begin(), v2.begin() + 5, [](const int &e1, const int &e2) {
    if (abs(e1 - e2) <= 2) {
      return true;
    }
    return false;
  });
  cout << ((equal_5) ? "" : "ikke ") << "lik i intervallet 0-5" << endl;

  bool equal_4 = equal(v1.begin(), v1.begin() + 4, v2.begin(), v2.begin() + 4, [](const int &e1, const int &e2) {
    if (abs(e1 - e2) <= 2) {
      return true;
    }
    return false;
  });
  cout << ((equal_4) ? "" : "ikke ") << "lik i intervallet 0-4" << endl;

  //oppgave c
  replace_copy_if(
      v1.begin(), v1.end(), v1.begin(), [](const int i) { return ((i % 2) == 1); }, 100);
  cout << "v1 after replace: " << v1 << endl;
}
