//
// Created by dereandor on 2/17/20.
//

#ifndef TASK02_WORKERS_H
#define TASK02_WORKERS_H
#include <functional>
#include <list>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

class Workers {
private:
    list<function<void()>>  tasks;
    mutex func_mutex;
    bool run = false;
    condition_variable cv;
    int count;
    vector<thread> threads;

public:
    Workers(int _count) {
        count = _count;
    }
    void start() {
        run = true;
        for(int i = 0; i < count; i++) {
            threads.emplace_back([this](){
                while(this->run) {
                    std::thread::id this_id = std::this_thread::get_id();
                    cout << "thread " << this_id << endl;
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(func_mutex);

                        if(!this->tasks.empty()) {
                            cv.wait(lock);
                            task = *this->tasks.begin();
                            this->tasks.pop_front();
                            cv.notify_one();
                        }
                    }
                }
            });
        }
    }

    void post(const function<void()>& func) {
        unique_lock<mutex> lock(func_mutex);
        threads.emplace_back(func);
        cv.notify_one();
    }

    void stop() {
        run = false;
        for (auto &thread : threads) {
            thread.join();
        }
    }

    void post_timeout(const function<void()> &func, const int timeout) {
        thread t([this, &func, &timeout] {
            this_thread::sleep_for(std::chrono::milliseconds(timeout));
            this->post(func);
        });
        t.join();
    }
};


#endif //TASK02_WORKERS_H
