#include "util.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

  string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVQXYZ0123456789";
  string hash = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
  string salt = "Saltet til Ola";
  int keylength = (hash.length() / 2);
  int iterations = 2048;
  char password[5];

  for (char c : alphabet) {
    password[0] = c;
    string key = hex(pkcs5(password, salt, iterations, keylength));
    if (key == hash) {
      cout << "password: " << password << endl;
      return 0;
    }
  }
  cout << "password is longer then 1 character" << endl;

  for (char c : alphabet) {
    password[0] = c;
    for (char c : alphabet) {
      password[1] = c;
      string key = hex(pkcs5(password, salt, iterations, keylength));
      if (key == hash) {
        cout << "password: " << password << endl;
        return 0;
      }
    }
  }
  cout << "password is longer then 2 characters" << endl;

  for (char c : alphabet) {
    password[0] = c;
    for (char c : alphabet) {
      password[1] = c;
      for (char c : alphabet) {
        password[2] = c;
        string key = hex(pkcs5(password, salt, iterations, keylength));
        if (key == hash) {
          cout << "password: " << password << endl;
          return 0;
        }
      }
    }
  }
  cout << "password is longer then 3 characters" << endl;
}