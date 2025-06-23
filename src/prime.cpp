#include "prime.h"
#include "gtest/gtest.h"
#include <cmath>
#include <vector>

///\brief    This function checks if the number is prime or not
///\param    Number which should be checked for primarity
///\return   Returns bool  1:Number is prime, 0:Number is not prime
bool IsNumberPrime(int number)
{

    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }


    for (int i = 3; i <= number / i; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

 
/// @brief  The function returns a collection of integers which 
///         contains the prime factors of the given number. 
/// @param  n is a given number
/// @return Returns vector of collection
std::vector<int> primeFactorize(int n)
{
    std::vector<int> result;

    if (n == 0 || n == 1
        || n == 2 || n == 3) {
        return result;
    }

    for (int i = 2; i <= n; ++i) {
        if (IsNumberPrime(i)) {
            if (n % i == 0) {
                result.push_back(i);
                n = n / i;
                i = 1; 
            } 
        }
    }

    return result;
}