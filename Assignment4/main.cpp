#include "sortutils.hpp"
#include <iostream>
#include <algorithm>
#include <array>
#include <list>
#include <random>

SourceArray generateRandomArray()
{
    std::default_random_engine engine{ 0u };
    std::uniform_int_distribution<> dist{ -10000000, 10000000 };
    SourceArray array;
    std::generate(array.begin(), array.end(), [&]
                  { return dist(engine); });
    return array;
}

int main()
{
    auto random = generateRandomArray();
    auto sorted = random;
    std::sort(std::begin(sorted), std::end(sorted));
    auto reverseList = sorted;
    std::reverse(std::begin(reverseList), std::end(reverseList));
    auto rotateList = sorted;
    std::rotate(rotateList.begin(), rotateList.begin() + 1, rotateList.end());
    auto organ = sorted;
    organPipeStdArray(organ);
    //evaluateRawArray();
    evaluateStdArray(random, sorted, reverseList, organ, rotateList);
    //evaluateStdVector();

}  