#include "rng.h"
#include <ctime>
#include <random>

namespace Rng {
    std::mt19937 gen(std::time(nullptr));
    int IntInRange(int low, int high){
        std::uniform_int_distribution<> dis(low, high);
        return dis(gen);
    }
}
