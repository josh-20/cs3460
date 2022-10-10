#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
class DistributionPair
{
  public:
    DistributionPair(std::uint32_t minValue, std::uint32_t maxValue) :
        minValue(minValue),
        maxValue(maxValue),
        count(0)
    {
    }
    std::uint32_t minValue;
    std::uint32_t maxValue;
    std::uint32_t count;
};
std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins);
std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins);
std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins);
void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize);
std::vector<DistributionPair> generateVectorList(std::uint32_t min, std::uint32_t max, std::uint8_t numberBins);
int main()
{
    auto uniform = generateUniformDistribution(100000, 0, 79, 40);
    plotDistribution("--- Uniform ---", uniform, 80);
    auto normal = generateNormalDistribution(100000, 50, 5, 40);
    plotDistribution("--- Normal ---", normal, 80);
    auto poisson = generatePoissonDistribution(100000, 6, 40);
    plotDistribution("--- Poisson ---", poisson, 80);
    return 0;
}

std::vector<DistributionPair> generateUniformDistribution(std::uint32_t howMany, std::uint32_t min, std::uint32_t max, std::uint8_t numberBins)
{
    auto arr = generateVectorList(min, max, numberBins);
    for (unsigned int i = 0; i <= howMany; i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::uniform_real_distribution<double> dist(min, max + 1);
        auto ranNum = dist(engine);
        for (unsigned int v = 0; v <= arr.size(); v++)
        {
            if (arr[v].minValue == max - 1 || ranNum == max)
            {
                arr[numberBins - 1].count++;
                break;
            }
            else if (ranNum >= arr[v].minValue && ranNum < arr[v + 1].minValue)
            {
                arr[v].count++;
                break;
            }
        }
    }
    return arr;
}
std::vector<DistributionPair> generateNormalDistribution(std::uint32_t howMany, float mean, float stdev, std::uint8_t numberBins)
{
    uint32_t max = static_cast<uint32_t>((mean + (4 * stdev)) - 1);
    uint32_t min = static_cast<uint32_t>((mean - (4 * stdev)));
    auto arr = generateVectorList(min, max, numberBins);
    for (unsigned int i = 0; i <= howMany; i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::normal_distribution<double> dist(mean, stdev);
        auto ranNum = dist(engine);
        for (unsigned int v = 0; v <= arr.size(); v++)
        {
            if (arr[v].minValue == max - 1 || ranNum >= max)
            {
                arr[numberBins - 1].count++;
                break;
            }
            else if (ranNum < min)
            {
                arr[0].count++;
                break;
            }
            else if (ranNum >= arr[v].minValue && ranNum < arr[v + 1].minValue)
            {
                arr[v].count++;
                break;
            }
        }
    }
    return arr;
}
std::vector<DistributionPair> generatePoissonDistribution(std::uint32_t howMany, std::uint8_t howOften, std::uint8_t numberBins)
{
    auto arr = generateVectorList(0, numberBins - 1, numberBins);

    for (unsigned int i = 0; i <= howMany; i++)
    {
        std::random_device rd;
        std::default_random_engine engine(rd());
        std::poisson_distribution<> dist(howOften);
        uint32_t ranNum = dist(engine);
        for (int v = 0; v <= arr.size(); v++)
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
void plotDistribution(std::string title, const std::vector<DistributionPair>& distribution, const std::uint8_t maxPlotLineSize)
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
        if (value.maxValue < 10)
        {
            std::cout << "[ " << value.minValue << ",    " << value.maxValue << "] count : ";
        }
        else
        {
            std::cout << "[" << value.minValue << ",   " << value.maxValue << "] count : ";
        }
        for (double i = 0; i < p; i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
std::vector<DistributionPair> generateVectorList(uint32_t min, uint32_t max, std::uint8_t numberBins)
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
