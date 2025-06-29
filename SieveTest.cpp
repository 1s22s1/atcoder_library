#include <gtest/gtest.h>

#include "Sieve.cpp"

using namespace std;

TEST(SieveTest, BasicAssertions)
{
    Sieve sieve(10);

    vector<vector<bool>> expected_visited = {false, false, true, true, false, true, false, true, false, false, false};
    EXPECT_EQ(expected_visited, sieve.prime_vector);
}
