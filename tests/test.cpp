#include "prime.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <vector>

TEST(PrimeFctTest, EMTY_TEST)
{
    EXPECT_EQ(1, 1);
}

TEST(PrimeFctTest, Given2_2)
{
    std::vector<int> expect = { 2 };
    EXPECT_EQ(primeFactorize(2), expect);
}

TEST(PrimeFctTest, Given3_3)
{
    std::vector<int> expect = { 3 };
    EXPECT_EQ(primeFactorize(3), expect);
}

TEST(PrimeFctTest, Given4_2N2)
{
    std::vector<int> expect = { 2, 2 };

    EXPECT_EQ(primeFactorize(4), expect);
}

TEST(PrimeFctTest, Given5_5)
{
    std::vector<int> expect = { 5 };

    EXPECT_EQ(primeFactorize(5), expect);
}

TEST(PrimeFctTest, Given6_2N3)
{
    std::vector<int> expect = { 2, 3 };

    EXPECT_EQ(primeFactorize(6), expect);
}

TEST(PrimeFctTest, Given7_7)
{
    std::vector<int> expect = { 7 };

    EXPECT_EQ(primeFactorize(7), expect);
}

TEST(PrimeFctTest, Given8_24)
{
    std::vector<int> expect = { 2, 2, 2 };

    EXPECT_EQ(primeFactorize(8), expect);
}

TEST(PrimeFctTest, Given9_33)
{
    std::vector<int> expect = { 3, 3 };

    EXPECT_EQ(primeFactorize(9), expect);
}

TEST(PrimeFctTest, Given10_25)
{
    std::vector<int> expect = { 2, 5 };

    EXPECT_EQ(primeFactorize(10), expect);
}

TEST(PrimeFctTest, Givenlarge_25)
{
    std::vector<int> expect = { 2, 2, 5, 7, 13, 17 };

    EXPECT_EQ(primeFactorize(2 * 2 * 5 * 7 * 17 * 13), expect);
}
