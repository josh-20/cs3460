#include "sortutils.hpp"

#include <algorithm>
#include <array>
#include <chrono>
#include <execution>
#include <fmt/format.h>
#include <iostream>
#include <iterator>

void initializeRawArrayFromStdArray(const SourceArray& source, int dest[])
{
    for (int i = 0; i < static_cast<int>(source.size()); i++)
    {
        dest[i] = source[i];
    }
}
void organPipeStdArray(SourceArray& data)
{
    for (int i = static_cast<int>(data.size() / 2); i < static_cast<int>(data.size()); i++)
    {
        data[i] = data[data.size() - i - 1];
    }
}
void helperForStd(const SourceArray& source, std::string name)
{
    { // first scope to save stack space
        auto total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            auto tempList = source;
            auto start = std::chrono::steady_clock::now();
            std::sort(tempList.begin(), tempList.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void helperForStdPar(const SourceArray& source, std::string name)
{
    { // parallel sort
        auto total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            auto tempList = source;
            auto start = std::chrono::steady_clock::now();
            std::sort(std::execution::par, tempList.begin(), tempList.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void helperForRaw(const SourceArray& source, std::string name)
{
    {
        int total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            int tempList[HOW_MANY_ELEMENTS];
            initializeRawArrayFromStdArray(source, tempList);
            auto start = std::chrono::steady_clock::now();
            std::sort(std::begin(tempList), std::end(tempList));
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void helperForRawPar(const SourceArray& source, std::string name)
{
    {
        int total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {
            int tempList[HOW_MANY_ELEMENTS];
            initializeRawArrayFromStdArray(source, tempList);
            auto start = std::chrono::steady_clock::now();
            std::sort(std::execution::par, std::begin(tempList), std::end(tempList));
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void helperForVector(const SourceArray& source, std::string name)
{
    {
        int total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {

            std::vector tempList(source.begin(), source.end());
            auto start = std::chrono::steady_clock::now();
            std::sort(tempList.begin(), tempList.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void helperForVectorPar(const SourceArray& source, std::string name)
{
    {
        int total = 0;
        for (int i = 0; i <= HOW_MANY_TIMES; i++)
        {

            std::vector tempList(source.begin(), source.end());
            auto start = std::chrono::steady_clock::now();
            std::sort(std::execution::par, tempList.begin(), tempList.end());
            auto end = std::chrono::steady_clock::now();
            total += static_cast<int>(
                std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                      start)
                    .count());
        }
        std::cout << fmt::format("\t{:<16} {} {} ms", name, ":", total) << std::endl;
    }
}
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted,
                      const SourceArray& reversed, const SourceArray& organPipe,
                      const SourceArray& rotated)
{
    std::cout << "--- Raw Array Performance ---\n"
              << std::endl;
    std::cout << "Sequential"
              << std::endl;
    helperForRaw(random, "Random Time");
    helperForRaw(sorted, "Sorted Time");
    helperForRaw(reversed, "Reversed Time");
    helperForRaw(organPipe, "Organ Pipe Time");
    helperForRaw(rotated, "Rotated Time");
    std::cout << "\nParrallel" << std::endl;
    helperForRawPar(random, "Random Time");
    helperForRawPar(sorted, "Sorted Time");
    helperForRawPar(reversed, "Reversed Time");
    helperForRawPar(organPipe, "Organ Pipe Time");
    helperForRawPar(rotated, "Rotated Time");
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
                      const SourceArray& reversed, const SourceArray& organPipe,
                      const SourceArray& rotated)
{
    std::cout << "\n--- std::array Performance ---\n"
              << std::endl;
    std::cout << "Sequential" << std::endl;
    helperForStd(random, "Random Time");
    helperForStd(sorted, "Sorted Time");
    helperForStd(reversed, "Reversed Time");
    helperForStd(organPipe, "Organ Pipe Time");
    helperForStd(rotated, "Rotated Time");
    std::cout << "\nParallel" << std::endl;
    helperForStdPar(random, "Random Time");
    helperForStdPar(sorted, "Sorted Time");
    helperForStdPar(reversed, "Reversed Time");
    helperForStdPar(organPipe, "Organ Pipe Time");
    helperForStdPar(rotated, "Rotated Time");
}
void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
                       const SourceArray& reversed,
                       const SourceArray& organPipe, const SourceArray& rotated)
{
    std::cout << "\n--- std::vector Performance ---\n"
              << std::endl;
    std::cout << "Sequential" << std::endl;
    helperForVector(random, "Random Time");
    helperForVector(sorted, "Sorted Time");
    helperForVector(reversed, "Reversed Time");
    helperForVector(organPipe, "Organ Pipe Time");
    helperForVector(rotated, "Rotated Time");
    std::cout << "\nParallel" << std::endl;
    helperForVectorPar(random, "Random Time");
    helperForVectorPar(sorted, "Sorted Time");
    helperForVectorPar(reversed, "Reversed Time");
    helperForVectorPar(organPipe, "Organ Pipe Time");
    helperForVectorPar(rotated, "Rotated Time");
}
