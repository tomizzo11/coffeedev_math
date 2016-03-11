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
            return avg;
        }

        /* Covariance - Calculates covariance between two data sets */
        template<typename T, std::size_t N1, std::size_t N2>
        auto Covariance(const std::array<T,N1>& data1, const std::array<T, N2>& data2)
        {
            auto i = 0.0;
            auto stop = 0.0;
            auto covar = 0.0;
            auto avg1 = ExpectedValue(data1);
            auto avg2 = ExpectedValue(data2);
            auto it1 = data1.begin();
            auto it2 = data2.begin();

            /* Determine stop index (dependent on smallest size input array )*/
            if (N1 <= N2)
                stop = N1;
            else
                stop = N2;

            /* Compute covariance iteratively */
            while(i <= stop)
            {
                i = it1 - data1.begin() + 1;
                covar = (i-1)*covar/i + (*it1 - avg1)*(*it2 - avg2)/i;
                it1++, it2++;
            }

            return covar;
        }

        /* Variance - Calculates the variance of a data set */
        template <typename T, std::size_t N>
        auto Variance(const std::array<T,N>& data)
        {
            return Covariance(data, data);
        }

        /* Standard Deviation - Calculates the standard deviation of a data set */
        template <typename T, std::size_t N>
        auto StdDev(const std::array<T,N>& data)
        {
            return sqrt(Covariance(data, data));
        }

        /* Cross Covariance */
        template<typename T, std::size_t N>
        void Crosscovariance(const std::array<T, N>& data1, const std::array<T,N>& data2, std::array<T, N>& data_out)
        {
            auto length = data1.size();
            auto avg1 = ExpectedValue(data1);
            auto avg2 = ExpectedValue(data2);
            auto covar = 0.0;
            auto i = 0.0;
            auto j = 0;
            auto it1 = data1.begin();
            auto it2 = data2.begin();
            auto it3 = data_out.begin();

            while(length != 0)
            {
                covar = 0.0;
                while(i <= length)
                {
                    i = it1 - data1.begin() + 1;
                    covar = (i-1)*covar/i + (*it1 - avg1)*(*it2 - avg2)/i;
                    it1++, it2++;
                    std::cout << "Here" ;
                }

                /* Prepare iterators for next covariance calculation cycle */
                i = 0.0;
                j++;
                it1 = data1.begin();
                it2 = data2.begin() + j;
                length--;

                /* Write to output data */
                *it3 = covar;
                it3++;

                std::cout << covar << "\n";
            }
            return;
        }


        /* Autocovariance */
        template<typename T, std::size_t N>
        void Autocovariance(const std::array<T, N>& data, std::array<T,N>& data_out)
        {
            Crosscovariance(data, data, data_out);
        }
};

#endif // COFFEEDEVMATH_PROBABILITY_H
