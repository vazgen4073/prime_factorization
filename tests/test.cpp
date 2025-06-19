#include "prime.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <vector>

TEST(prime_factor, test3)
{

    std::vector<int> tmp_vec;
    EXPECT_EQ(primeFactorize(0).size(), 0);
    EXPECT_EQ(primeFactorize(1).size(), 0);
    EXPECT_EQ(primeFactorize(2).size(), 0);
    EXPECT_EQ(primeFactorize(3).size(), 0);

    tmp_vec = primeFactorize(6);
    EXPECT_EQ(tmp_vec[0], 2);
    EXPECT_EQ(tmp_vec[1], 3);

    tmp_vec = primeFactorize(60);
    EXPECT_EQ(tmp_vec[0], 2);
    EXPECT_EQ(tmp_vec[1], 2);
    EXPECT_EQ(tmp_vec[2], 3);
    EXPECT_EQ(tmp_vec[3], 5);

    tmp_vec = primeFactorize(125);
    EXPECT_EQ(tmp_vec[0], 5);
    EXPECT_EQ(tmp_vec[1], 5);
    EXPECT_EQ(tmp_vec[2], 5);
}

TEST(check_prime, test2)
{

    EXPECT_TRUE(IsNumberPrime(2));
    EXPECT_TRUE(IsNumberPrime(3));
    EXPECT_TRUE(IsNumberPrime(5));
    EXPECT_TRUE(IsNumberPrime(7));
    EXPECT_TRUE(IsNumberPrime(11));
    EXPECT_TRUE(IsNumberPrime(83));
    EXPECT_TRUE(IsNumberPrime(97));
}

TEST(hello, EMTY_TEST)
{
    EXPECT_EQ(1, 1);
}
