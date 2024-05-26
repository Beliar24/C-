#include "VectorUtils.h"
#include <unordered_set>
#include <algorithm>


bool hasDuplicates(const std::vector<int>& vec) {
    std::unordered_set<int> seen;
    for (const int& value : vec) {
        if (seen.find(value) != seen.end()) {
            return true;
        }
        seen.insert(value);
    }
    return false;
}


bool containsNumber(const std::vector<int>& vec, int number) {
    return any_of(vec.begin(), vec.end(), [number](int value) {
        return value == number;
    });
}
