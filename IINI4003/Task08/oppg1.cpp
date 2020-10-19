#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
  cout << "Type a: " << a << ", b: " << b << endl;
  if (a == b) {
    return true;
  }
  return false;
}

bool equal(double a, double b) {
  setprecision(10);
  cout << "Double a: " << a << ", b: " << b << endl;
  double error_margin = 0.00001;

  if (abs(a - b) < error_margin) {
    return true;
  }
  return false;
}

int main() {
  double a = 1.00002;
  double b = 1.000022;
  double x = 1.1;
  double y = 1.1;

  cout << ((equal(a, b)) ? "=" : "= not") << " equal" << endl;

  cout << ((equal(b, x)) ? "=" : "= not") << " equal" << endl;

  cout << ((equal(x, y)) ? "=" : "= not") << " equal" << endl;

  string str_a = "en potet";
  string str_b = "en potet";
  cout << ((equal(str_a, str_b)) ? "=" : "= not") << " equal" << endl;

  string str_x = "en potet";
  string str_y = "to potet";
  cout << ((equal(str_x, str_y)) ? "=" : "= not") << " equal" << endl;
}