#include <iostream>
#include <functional>
#include <list>

using namespace std;

void func() {
    cout << "func() called" << endl;
}

int main() {
    list<function<void()>> tasks;

    tasks.emplace_back(func);
    tasks.emplace_back([]() {
        cout << "lambda called" << endl;
    });

    for (auto it = tasks.begin(); it!= tasks.end(); it++) {
        auto &task = *it;
        task();
    }
    cout << tasks.size() << endl;
}
