#include "sortutils.hpp"

#include <algorithm>
#include <array>
#include <iostream>
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
    SourceArray sorted = generateRandomArray();
    std::sort(std::begin(sorted), std::end(sorted));
    SourceArray reverse = generateRandomArray();
    std::reverse(std::begin(reverse), std::end(reverse));
    SourceArray rotate = generateRandomArray();
    std::rotate(std::begin)
    SourceArray random = generateRandomArray();
    SourceArray organ = generateRandomArray();

   eval
}