#include "sortutils.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <random>

// generate Random array code from TestPerformance.cpp
SourceArray generateRandomArray()
{
    std::default_random_engine engine{0u};
    std::uniform_int_distribution<> dist{-10000000, 10000000};
    SourceArray array;
    std::generate(array.begin(), array.end(), [&] { return dist(engine); });
    return array;
}

int main()
{
    auto random = generateRandomArray();
    auto sorted = random;
    // std::sort(sorted.begin(), sorted.end());
    auto reverseList = sorted;
    // std::reverse(reverseList.begin(), reverseList.end());
    auto rotateList = sorted;
    std::rotate(rotateList.begin(), rotateList.begin() + 1, rotateList.end());
    auto organ = sorted;
    organPipeStdArray(organ);
    // evaluateRawArray();
    evaluateStdArray(random, sorted, reverseList, organ, rotateList);
    // evaluateStdVector();
}