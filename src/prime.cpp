#include "prime.h"
#include "gtest/gtest.h"
#include <cmath>
#include <vector>

/// @brief  The function returns a collection of integers which
///         contains the prime factors of the given number.
/// @param  n is a given number
/// @return Returns vector of collection
std::vector<int> primeFactorize(int n)
{

    std::vector<int> result;

    int div = 2;
    while (div < n ) {
        while (n % div == 0) {
            result.push_back(div);
            n = n / div;
        }
        div++;
    }

    if (n > 1) {
        result.push_back(n);
        return result;
    }


    return result;
}