#include <array>
#include <iostream>
#include "include/Probability.h"

int main()
{

    std::array<float, 5> hoor = {1,2,3,4, 5};
    std::array<float, 5> ay = {2,4,5,2,3};
    std::array<float, 5> zeros = {0, 0, 0, 0, 0};

    float here = Probability::Covariance(hoor, ay);
    std::cout << "Covariance: " << here << "\n";
    std::cout << "-------------- \n";
    Probability::Crosscovariance(hoor, ay, zeros);

}

