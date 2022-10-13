#include "sortutils.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[])
{
    dest[source.size()];
    for (int i = 0; i < source.size(); i++)
    {
        dest[i] = source[i];
    }
}
void organPipeStdArray(SourceArray& data)
{
    for (int i = 0; i <= data.size() / 2; i++)
    {
        data[data.size() / 2 + i] = data[data.size() / 2 - i];
    }
}
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted,
                      const SourceArray& reversed, const SourceArray& organPipe,
                      const SourceArray& rotated)
{
}
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
                      const SourceArray& reversed, const SourceArray& organPipe,
                      const SourceArray& rotated)
{
    { // first scope to save stack space
        auto total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            auto tempSort = sorted;
            auto start = std::chrono::steady_clock::now();
            std::sort(tempSort.begin(), tempSort.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << "Sorted Time:  " << total << " ms" << std::endl;
    }

    { // second scope to save stack space
        auto total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            auto tempReverse = reversed;
            auto start = std::chrono::steady_clock::now();
            std::reverse(tempReverse.begin(), tempReverse.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << "Reveresed Time:  " << total << " ms" << std::endl;
    }
}
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
                       const SourceArray& reversed,
                       const SourceArray& organPipe, const SourceArray& rotated)
{
}