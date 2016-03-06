#ifndef COFFEEDEVMATH_PROBABILITY_H
#define COFFEEDEVMATH_PROBABILITY_H

#include <array>
#include <iostream>
#include <math.h>

namespace Probability
{
        /* ExpectedValue - Calculates the expected value of a data set */
        template <typename T, std::size_t N>
        auto ExpectedValue(const std::array<T, N>& data)
        {
            auto i = 0.0;
            auto avg = 0.0;

            for(auto it = data.begin(); it != data.end(); it++)
            {
                i = it - data.begin() + 1;
                avg = (i-1)*avg/i + (*it)/i;
            }

            std::cout << "Expected Value " << avg << " \n";
            return avg;
        }

        /* Variance - Calculates the variance of a data set */
        template <typename T, std::size_t N>
        auto Variance(const std::array<T,N>& data)
        {
            auto i = 0.0;
            auto avg = ExpectedValue(data);
            auto var = 0.0;

            for (auto it = data.begin(); it != data.end(); it++)
            {
                i = it - data.begin() + 1;
                var = (i-1)*var/i + pow((*it - avg),2)/i;
            }

            std::cout << "Variance: " << var << "\n";
            return var;
        }

        /* Standard Deviation - Calculates the standard deviation of a data set */
        template <typename T, std::size_t N>
        auto StdDev(const std::array<T,N>& data)
        {
            return sqrt(Variance(data));
        }

        /* Covariance - Calculates covariance between two data sets */
        template<typename T1, typename T2, std::size_t N>
        auto Covariance(const std::array<T1,N>& data1, const std::array<T2, N>& data2)
        {
            auto i = 1.0;
            auto covar = 0.0;
            auto avg1 = ExpectedValue(data1);
            auto avg2 = ExpectedValue(data2);
            auto it1 = data1.begin();
            auto it2 = data2.begin();

            while(it1 != data1.end())
            {
                covar = (i-1)*covar/i + (*it1 - avg1)*(*it2 - avg2)/i;
                i++, it1++, it2++;
            }
            std::cout << "Covariance: " << covar << "\n";
            return covar;
        }

};

#endif // COFFEEDEVMATH_PROBABILITY_H
