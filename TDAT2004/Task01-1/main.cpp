#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>

using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    else if (n <= 3) return true;
    else if (n % 2 == 0 || n % 3 == 0) return false;
    int i = 5;
    while (i*i <= n) {
        if (n % i == 0 || n % (i+2) == 0) return false;
        i = i+6;
    }
    return true;
}

vector<int> primes;
mutex prime_mutex;

vector<int> findPrimes(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if(isPrime(i)) {
            lock_guard<mutex> lock(prime_mutex);
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    const int THREADS = 2;
    const int START = 1;
    const int END = 100;
    const int STEP = floor((END - START)/THREADS);
    vector<thread> threads;
    int threadEndNum;

    for (int i = START; i <= END; i += STEP) {
        threadEndNum = i + STEP;
        if(threadEndNum > END) threadEndNum = END;
        threads.emplace_back([i, threadEndNum]() {
            findPrimes(i, threadEndNum);
        });
    }

    for (unsigned i = 0; i < threads.size(); ++i) {
        threads[i].join();
    }

    for (unsigned i = 0; i < primes.size(); ++i) {
        cout << primes[i] << ' ';
    }
    return 0;
}
