
#include "distributions.hpp"

#include <cstdlib>
#include <fmt/format.h>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
std::vector<DistributionPair> generateVectorList(uint32_t min, uint32_t max,
                                                 std::uint8_t numberBins)
{
    std::vector<DistributionPair> arr;
    for (double i = min; i <= max; i += ((max - min) / numberBins) + 1)
    {
        uint32_t j = static_cast<uint32_t>(i);
        DistributionPair bin(j, j + ((max - min) / numberBins));
        arr.push_back(bin);
    }
    return arr;
}

std::vector<DistributionPair>
generateUniformDistribution(std::uint32_t howMany, std::uint32_t min,
                            std::uint32_t max, std::uint8_t numberBins)
{
    auto arr = generateVectorList(min, max, numberBins);
    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::uniform_real_distribution<double> dist(min, max + 1);

        auto ranNum = dist(engine);
        for (int v = 0; v < static_cast<int>(arr.size()); v++)
        {
            if (arr[v].minValue == max - 1 || ranNum == max)
            {
                arr[numberBins - 1].count += 1;
                break;
            }
            else if (ranNum >= arr[v].minValue && ranNum < arr[v + 1].minValue)
            {
                arr[v].count += 1;
                break;
            }
        }
    }
    return arr;
}
std::vector<DistributionPair>
generateNormalDistribution(std::uint32_t howMany, float mean, float stdev,
                           std::uint8_t numberBins)
{
    uint32_t max = static_cast<uint32_t>((mean + (4 * stdev)) - 1);
    uint32_t min = static_cast<uint32_t>((mean - (4 * stdev)));
    auto arr = generateVectorList(min, max, numberBins);
    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::normal_distribution<double> dist(mean, stdev);
        auto ranNum = dist(engine);
        for (int v = 0; v < static_cast<int>(arr.size()) + 1; v++)
        {
            if (arr[v].minValue == max - 1 || ranNum >= max)
            {
                arr[numberBins - 1].count += 1;
                break;
            }
            else if (ranNum < min)
            {
                arr[0].count += 1;
                break;
            }
            else if (ranNum >= arr[v].minValue && ranNum < arr[v + 1].minValue)
            {
                arr[v].count += 1;
                break;
            }
        }
    }
    return arr;
}
std::vector<DistributionPair>
generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften,
                            std::uint8_t numberBins)
{
    auto arr = generateVectorList(0, numberBins - 1, numberBins);

    for (int i = 0; i < static_cast<int>(howMany); i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::poisson_distribution<> dist(howOften);
        uint32_t ranNum = dist(engine);
        for (int v = 0; v < static_cast<int>(arr.size()); v++)
        {
            if (arr[v].maxValue == ranNum)
            {
                arr[v].count++;
                break;
            }
        }
    }
    return arr;
}
void plotDistribution(std::string title,
                      const std::vector<DistributionPair>& distribution,
                      const std::uint8_t maxPlotLineSize)
{
    double binMax = 0;
    for (DistributionPair pair : distribution)
    {
        if (pair.count > binMax)
        {
            binMax = pair.count;
        }
    }
    std::cout << title << std::endl;
    for (DistributionPair value : distribution)
    {
        double p = value.count * (maxPlotLineSize / binMax);
        std::string ast(p, '*');
        std::cout << fmt::format("[{:>3}, : {:>4}] : {}\n", value.minValue, value.maxValue, ast);
    }
}
