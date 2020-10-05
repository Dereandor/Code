#include <iostream>
#include <functional>
#include "Workers.h"

using namespace std;

int main() {
    auto worker_threads = new Workers(6);
    auto event_loop = new Workers(1);

    for (int i = 0; i < 100; i++) {
        worker_threads->post([i] {
            cout << "Hello from " << i << "!" << endl;
        });
    }

    for (int i = 0; i < 10; i++) {
        event_loop->post([i] {
            cout << "EV: Hello from " << i << "!" << endl;
        });
    }

    worker_threads->post_timeout([] {
        cout << "This should be done after a while" << endl;
    }, 5000);

    worker_threads->post_timeout([] {
        cout << "And this should come right after!" << endl;
    }, 5500);

    worker_threads->start();

    worker_threads->stop();

    return 0;
}
