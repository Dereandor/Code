#ifndef TASK01_MAIN_H
#define TASK01_MAIN_H

#include <cmath>
#include <vector>
#include <memory>

void findPrime (
        unsigned long long start,
        unsigned long long stop,
        unsigned long long step,
        std::unique_ptr<std::vector<unsigned long long>>& results
        );




#endif //TASK01_MAIN_H
