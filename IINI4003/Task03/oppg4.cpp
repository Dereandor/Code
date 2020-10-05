#include <iostream>
#include <string>

using namespace std;

int main() {

  string word1, word2, word3;

  //a
  cout << "Please type 3 words separated by enter" << endl;
  cin >> word1;
  cin >> word2;
  cin >> word3;

  //b
  string sentence = word1 + " " + word2 + " " + word3 + ".";

  cout << sentence << endl;

  //c
  cout << "Length of first word: " << word1.length() << endl;
  cout << "Length of second word: " << word2.length() << endl;
  cout << "Length of third word: " << word3.length() << endl;
  cout << "Length of sentence: " << sentence.length() << endl;

  //d
  string sentence2 = sentence;

  //e
  if (sentence2.length() >= 12) {
    sentence2.replace(9, 3, "XXX", 3);
  }

  cout << sentence << endl;
  cout << sentence2 << endl;

  //f
  string sentence_start;
  if (sentence.length() >= 5) {
    sentence_start = sentence.substr(0, 5);
  }
  cout << sentence << endl;
  cout << sentence_start << endl;

  //g
  if (sentence.find("hallo") != string::npos) {
    cout << "Found the word \"hallo\"" << endl;
  } else {
    cout << "Did not find the word \"hallo\"" << endl;
  }

  //h
  int count = 0;
  for (int i = 0; i < sentence.length(); i++) {
    if (sentence.substr(i, 2) == "er") {
      count++;
    }
  }
  cout << "Found " << count << " occurrences of \"er\"." << endl;
}