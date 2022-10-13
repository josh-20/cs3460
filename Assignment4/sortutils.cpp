#include "sortutils.hpp"
#include <array>
#include <iostream>
#include <chrono>
#include <algorithm>

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[])
{
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
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}
void evaluateStdArray(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
     auto start = std::chrono::steady_clock::now();
     std::sort(std::begin(sorted), std::end(sorted));
     auto end = std::chrono::steady_clock::now();
     std::cout << "Sorted Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

}
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted, const SourceArray& reversed, const SourceArray& organPipe, const SourceArray& rotated)
{
}