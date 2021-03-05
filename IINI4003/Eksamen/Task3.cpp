#include <thread>
#include <vector>
#include <iostream>

using namespace std;

class ThreadSafeGrowingList {

};

int main() {
    ThreadSafeGrowingList list;
    vector<thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&list, i] {
            list.add(i);
        });
    }

    list.for_each([](int value) {
        cout << value << endl;
        this_thread::sleep_for(200ms);
    });

    for (auto &thread : threads)
        thread.join();
}
