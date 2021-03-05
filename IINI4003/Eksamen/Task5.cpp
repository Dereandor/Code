#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
template <typename Func>
auto Map(Func func) {

}
template <typename Func>
auto Filter(Func func) {

}

int main() {
    vector<int> vec = {1, 2, 3};



    vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
    cout << vecMultipliedBy2 << endl;



    vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1; });
    cout << vecFiltered << endl;
}